#include"Header.h"

int main(int argc, char* argv[]) {
	int command = determineCommand(argc, argv);
	switch (command) {
	case 1:
		Command1(argv);
		break;
	case 2:
		Command2(argv);
		break;
	case 3:
		Command3(argv);
		break;
	case 4:
		Command4(argv);
		break;
	case 5:
		Command5(argv);
		break;
	default: break;
	}
	return 0;
}