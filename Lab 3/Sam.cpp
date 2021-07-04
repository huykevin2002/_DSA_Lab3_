void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// https://stackoverflow.com/questions/33837737/quick-sort-middle-pivot-implementation-strange-behaviour
void quickSortMiddle(int* a, int left, int right)
{
	if (left >= right) return;
	int pivot = a[left + (right - left) / 2];
	int leftI = left - 1;
	int rightI = right + 1;
	while (1)
	{
		while (a[++leftI] < pivot);
		while (a[--rightI] > pivot);
		if (leftI >= rightI)
			break;
		Swap(a[leftI], a[rightI]);
	}
	quickSortMiddle(a, left, rightI);
	quickSortMiddle(a, rightI + 1, right);
}

void quickSortMiddleCompare(int* a, int left, int right, unsigned long long& compare)
{
	if (++compare && left >= right) return;
	int pivot = a[left + (right - left) / 2];
	int leftI = left - 1;
	int rightI = right + 1;
	while (1)
	{
		while (++compare && a[++leftI] < pivot);
		while (++compare && a[--rightI] > pivot);
		if (++compare && leftI >= rightI)
			break;
		Swap(a[leftI], a[rightI]);
	}
	quickSortMiddle(a, left, rightI);
	quickSortMiddle(a, rightI + 1, right);
}

//https://nguyenvanhieu.vn/thuat-toan-sap-xep-bubble-sort/
void BubbleSort(int* a, int n)
{
	for (int j = n; j > 0; j--)
	{
		bool isSwap = false;
		for (int i = 0; i < j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				isSwap = true;
			}
		}
		if (!isSwap)
			break;
	}
}

void BubbleSortCompare(int* a, int n, unsigned long long& compare)
{
	for (int j = n; ++compare && j > 0; j--)
	{
		bool isSwap = false;
		for (int i = 0; ++compare && i < j - 1; i++)
		{
			if (++compare && a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				isSwap = true;
			}
		}
		if (++compare && !isSwap)
			break;
	}
}

// https://www.stdio.vn/giai-thuat-lap-trinh/bubble-sort-va-shaker-sort-01Si3U
void ShakerSort(int* a, int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				Swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

void ShakerSortCompare(int* a, int n, unsigned long long compare)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++compare && Left < Right)
	{
		for (int i = Left; ++compare && i < Right; i++)
		{
			if (++compare && a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++compare && i > Left; i--)
		{
			if (++compare && a[i] < a[i - 1])
			{
				Swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}