// main.cpp
#include "main.h"

int main() {
	STU students[STU_NUM];
	int totalStudents = 0;
	int courseCount = 0;
	while (true) {
		system("cls");
		int choice = Menu();
		
		switch (choice) {
		case 1:
			system("cls");
			InputRecord(students , &totalStudents ,&courseCount );
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 0:
			return 0;
		default:
			cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}