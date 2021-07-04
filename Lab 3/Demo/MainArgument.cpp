#include "Header.h"

void readFile(string path, int*& a, int& n) {
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
		return;

	fin >> n;

	a = new int[n];

	for (int i = 0; i < n; i++)
		fin >> a[i];

	fin.close();
}

void writeFile(string path, int a[], int n) {
	ofstream fout;
	fout.open(path);

	fout << n << endl;

	for (int i = 0; i < n; i++) {
		fout << a[i];
		if (i != n - 1)
			fout << " ";
	}

	fout.close();
}

bool isTextFile(char* a) {
	if (strlen(a) <= 4) return 0;

	if (a[strlen(a) - 4] == '.')
		return 1;

	return 0;
}

int determineCommand(int argc, char* argv[]) {
	if (argc == 5) {
		if (strcmp(argv[1], "-c") == 0)
			return 4;
		if (strcmp(argv[1], "-a") == 0) {
			if (isTextFile(argv[3]))
				return 1;
			else
				return 3;
		}
	}
	if (argc == 6) {
		if (strcmp(argv[1], "-a") == 0)
			return 2;
		if (strcmp(argv[1], "-c") == 0)
			return 5;
	}
	return 0;
}

int getDataType(char* a) {
	if (strcmp(a, "-rand") == 0)
		return 0;
	if (strcmp(a, "-sorted") == 0)
		return 1;
	if (strcmp(a, "-rev") == 0)
		return 2;
	if (strcmp(a, "-nsorted") == 0)
		return 3;
	return 4;
}

string runAlgorithm(char* a, int arr[], int n, double& runtime, unsigned long long& count_compare) {
	int* b = new int[n];
	CopyArr(arr, b, n);

	if (strcmp(a, "radix-sort") == 0) {
		count_compare = RadixCompare(arr, n);
		runtime = RadixTime(b, n);
		delete[]b;
		return "Radix Sort";
	}

	if (strcmp(a, "heap-sort") == 0) {
		count_compare = HeapSortCompare(arr, n);
		runtime = HeapSortTime(b, n);
		delete[]b;
		return "Heap Sort";
	}

	if (strcmp(a, "merge-sort") == 0) {
		int* c = new int[n];
		count_compare = MergeSort_Compare(arr, c, n);
		runtime = MergeSortTime(b, c, n);
		delete[]b;
		delete[]c;
		return "Merge Sort";
	}

	if (strcmp(a, "selection-sort") == 0) {
		count_compare = selection_sort_compare(arr, n);
		runtime = selection_sort_time(b, n);
		delete[]b;
		return "Selection Sort";
	}

	if (strcmp(a, "binary-insertion-sort") == 0) {
		count_compare = insert_sort_compare(arr, n);
		runtime = insert_sort_time(b, n);
		delete[]b;
		return "Binary Insertion Sort";
	}

	if (strcmp(a, "bubble-sort") == 0) {
		count_compare = BubbleSortCompare(arr, n);
		runtime = BubbleSortTime(b, n);
		delete[]b;
		return "Bubble Sort";
	}

	if (strcmp(a, "quick-sort") == 0) {
		count_compare = QuickSortCompare(arr, 0, n - 1);
		runtime = QuickSortTime(b, 0, n - 1);
		delete[]b;
		return "Quick Sort";
	}

	if (strcmp(a, "shaker-sort") == 0) {
		count_compare = ShakerSortCompare(arr, n);
		runtime = ShakerSortTime(b, n);
		delete[]b;
		return "Shaker Sort";
	}

	if (strcmp(a, "shell-sort") == 0) {
		count_compare = shell_sort_compare(arr, n);
		runtime = shell_sort_time(b, n);
		delete[]b;
		return "Shell Sort";
	}

	if (strcmp(a, "counting-sort") == 0) {
		count_compare = countingSort_compare(arr, n);
		runtime = countingSort_time(b, n);
		delete[]b;
		return "Counting Sort";
	}

	if (strcmp(a, "flash-sort") == 0) {
		count_compare = flashSort_compare(arr, n);
		runtime = flashSort_time(b, n);
		delete[]b;
		return "Flash Sort";
	}


	return "";
}

string getOrder(int a) {
	if (a == 0)
		return "Randomize";
	if (a == 1)
		return "Sorted";
	if (a == 2)
		return "Reversed";
	if (a == 3)
		return "Nearly sorted";
	return "";
}

void printCompTime(char* a, double runtime, unsigned long long count_compare) {
	if (strcmp(a, "-comp") == 0)
		cout << "Comparisons: " << count_compare << endl;

	if (strcmp(a, "-time") == 0)
		cout << "Running time: " << runtime << endl;

	if (strcmp(a, "-both") == 0) {
		cout << "Running time: " << runtime << " ms" << endl;
		cout << "Comparisons: " << count_compare << endl;
	}
}

void Command1(char* argv[]) {
	int* a = nullptr, n;
	readFile(argv[3], a, n);

	double runtime;
	unsigned long long count_compare;

	cout << "ALGORITHM" << endl;
	cout << "Algorithm: " << runAlgorithm(argv[2], a, n, runtime, count_compare) << endl;
	cout << "Input file: " << argv[3] << endl;
	cout << "Input size: " << n << endl;

	cout << "-------------------------" << endl;

	printCompTime(argv[4], runtime, count_compare);

	writeFile("output.txt", a, n);

	delete[]a;
}

void Command2(char* argv[]) {
	int n = stoi(argv[3]);
	int* a = new int[n];
	int DataType = getDataType(argv[4]);

	GenerateData(a, n, DataType);
	writeFile("input.txt", a, n);

	double runtime;
	unsigned long long count_compare;

	cout << "ALGORITHM" << endl;
	cout << "Algorithm: " << runAlgorithm(argv[2], a, n, runtime, count_compare) << endl;
	cout << "Input size: " << n << endl;
	cout << "Input order: " << getOrder(DataType) << endl;

	cout << "-------------------------" << endl;

	printCompTime(argv[5], runtime, count_compare);

	writeFile("output.txt", a, n);

	delete[]a;
}

void Command3(char* argv[]) {
	int n = stoi(argv[3]);
	int* a = new int[n];
	string filename = "input_";

	GenerateData(a, n, 0);
	writeFile(filename + "1.txt", a, n);

	double runtime;
	unsigned long long count_compare;

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << runAlgorithm(argv[2], a, n, runtime, count_compare) << endl;
	cout << "Input size: " << n << endl << endl;

	cout << "Input order: " << getOrder(0) << endl;
	cout << "-------------------------" << endl;
	printCompTime(argv[4], runtime, count_compare);
	cout << endl;

	for (int i = 0; i < 3; i++) {
		int temp;

		if (i == 0)
			temp = 3;
		else
			temp = i;

		cout << "Input order: " << getOrder(temp) << endl;
		cout << "-------------------------" << endl;

		GenerateData(a, n, temp);
		writeFile(filename + to_string(i + 2) + ".txt", a, n);

		runAlgorithm(argv[2], a, n, runtime, count_compare);

		printCompTime(argv[4], runtime, count_compare);
		cout << endl;
	}

	delete[]a;
}

void Command4(char* argv[]) {
	int* a = nullptr, n;
	readFile(argv[4], a, n);
	int* b = new int[n];
	CopyArr(a, b, n);

	double runtime1, runtime2;
	unsigned long long count_compare1, count_compare2;

	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << runAlgorithm(argv[2], a, n, runtime1, count_compare1) << " | " << runAlgorithm(argv[3], b, n, runtime2, count_compare2) << endl;
	cout << "Input file: " << argv[4] << endl;
	cout << "Input size: " << n << endl;

	cout << "-------------------------" << endl;

	cout << "Running time: " << runtime1 << " ms" << " | " << runtime2 << " ms" << endl;
	cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;

	delete[]a;
	delete[]b;
}

void Command5(char* argv[]) {
	int n = stoi(argv[4]);
	int* a = new int[n], * b = new int[n];
	int DataType = getDataType(argv[5]);

	GenerateData(a, n, DataType);
	writeFile("input.txt", a, n);
	CopyArr(a, b, n);

	double runtime1, runtime2;
	unsigned long long count_compare1, count_compare2;

	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << runAlgorithm(argv[2], a, n, runtime1, count_compare1) << " | " << runAlgorithm(argv[3], b, n, runtime2, count_compare2) << endl;
	cout << "Input size: " << n << endl;
	cout << "Input order: " << getOrder(DataType) << endl;

	cout << "-------------------------" << endl;

	cout << "Running time: " << runtime1 << " ms" << " | " << runtime2 << " ms" << endl;
	cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;

	delete[]a;
	delete[]b;
}

