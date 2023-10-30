// main.cpp
#include "main.h"
//
int main() {
	STU students[STU_NUM];
	int totalStudents = 0;
	int courseCount = 0;
	int first = 1;
	while (true) {
		system("cls");
		int choice = Menu();

		switch (choice) {
		case 1:
			system("cls");
			InputRecord(students, &totalStudents, &courseCount);
			first = 0;
			break;
		case 2:
			break;
		case 3:
			system("cls");
			if (first) {
				printf("ϵͳ������ѧ����Ϣ����������!\n");
				system("pause");
				return;
			}
			DeleteRecord(students, &totalStudents, courseCount);
			system("pause");
			break;
		case 4:
			break;
		case 5:
			system("cls");
			if (first) {
				printf("ϵͳ������ѧ����Ϣ����������!\n");
				system("pause");
				break;
			}
			SearchByName(students, courseCount, totalStudents);
			system("pause");
			break;
		case 6:
			break;
		case 7:
			system("cls");
			if (first) {
				cout << "ϵͳ������ѧ���ɼ���Ϣ���������룡" << endl;
				system("pause");
				break;

			}
			CalculateScoreOfStudent(students, totalStudents, courseCount);
			system("pause");
			break;
		case 8:
			system("cls");
			if (first) {
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ���ɼ���Ϣ!"); 
				_getch();
				break;
			}
			CalculateScoreOfCourse(students, totalStudents, courseCount);
			_getch();
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
			system("cls");
			if (first) {
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ���ɼ���Ϣ!\n");
				_getch();
				break;
			}
			WriteToFile(students, totalStudents, courseCount,".\\data\\records.txt");
			_getch();
			break;
		case 16:
			system("cls");
			if (ReadFromFile(students,&totalStudents, &courseCount, &first) || first) {
				SetPosition(POS_X1, 10);
				cout << "��δ����" << endl;
				_getch();
				break;
			}
			_getch();
			break;
		case 0:
			return 0;
		default:
			cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}