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
			system("cls");
			if (first) {
				cout << "系统中暂无学生成绩信息！" << endl;
				system("pause");
				break;

			}
			AppendRecord(students, &totalStudents, courseCount);
			system("pause"); 
			break;

			break;
		case 3:
			break;
		case 4:
			system("cls"); 
			if (first) {
				cout << "系统中暂无学生成绩信息!" << endl;
				system("pause");
				break; 
			}
			SearchByNum(students, totalStudents, courseCount);
			system("pause");
			
			break;
		case 5:


			break;
		case 6:
			break;
		case 7:
			system("cls");
			if (first) {
				cout << "系统中暂无学生成绩信息，请先输入！" << endl;
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
				printf("系统中暂无学生成绩信息!"); 
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
			system("cls");
			if (first) {
				SetPosition(POS_X3, POS_Y);
				printf("系统中暂无学生成绩信息!\n");
				_getch();
				break;
			}
			StatisticAnalysis(students, totalStudents, courseCount);
			_getch();
			break;
			break;
		case 14:
			break;
		case 15:
			system("cls");
			if (first) {
				SetPosition(POS_X3, POS_Y);
				printf("系统中暂无学生成绩信息!\n");
				_getch();
				break;
			}
			WriteToFile(students, totalStudents, courseCount,".\\data\\records.txt");
			_getch();
			break;
		case 16:
			system("cls");
			if (ReadFromFile(students,&totalStudents, &courseCount, &first)) {
				SetPosition(POS_X1, 10);
				cout << "尚未输入" << endl;
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