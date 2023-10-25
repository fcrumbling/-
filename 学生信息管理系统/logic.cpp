//logic.cpp
#include "main.h"

//光标
void SetPosition(int x, int y) {
	HANDLE hOut;
	COORD pos = { x,y };//直接构造位置
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

//计时器
void countdown(int seconds,int posy) {
	SetPosition(POS_X2, ++posy);
	for (int i = seconds; i > 0; --i) {
		SetPosition(POS_X2, posy);
		printf(" % d 秒后返回...\n", i);
		Sleep(1000);  // Sleep for 1000 milliseconds (1 second)
		//system("CLS");  // 清屏
	}
	SetPosition(POS_X2, ++posy);
	printf("返回中...\n");
}

void InputRecord(STU students[], int* totalStudents, int* courseCount)
{
	int i, j;
	int posy = 6;
	SetPosition(POS_X2, posy);
	printf_s("请输入学生人数(n<%d):",STU_NUM);
	scanf_s("%d", totalStudents);
	SetPosition(POS_X2, posy+=2);
	printf_s("请输入课程数(n<%d):", COURSE_NUM);
	scanf_s("%d", courseCount);
	for (int i = 0; i < 2; i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++) {
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf_s("请输入%d个学生的学号、姓名和各门课程成绩:", *totalStudents);
	for (size_t i = 0; i < *totalStudents; i++)
	{
		SetPosition(POS_X2, ++posy);
		printf("输入第%d个信息\t", i + 1);
		cin >>students[i].num >> students[i].name;
		for (int i = 0; i < *courseCount; i++) {
			cin >> students[i].score[i];
		}
	}

	// 在录入完毕之后
	SetPosition(POS_X2, ++posy);
	printf("录入成功！\n");
	countdown(2,posy);  // 开始2秒倒计时

}


void AppendRecord(STU students[], int* totalStudents, int courseCount)
{
}

void DeleteRecord(STU students[], int totalStudents, int courseCount)
{
}

void SearchByNum(STU students[], int totalStudents, int courseCount)
{
}

void SearchByName(STU students[], int totalStudents, int courseCount)
{
}

void ModifyRecord(STU students[], int totalStudents, int courseCount)
{
}

void CalculateScoreOfStudent(STU students[], int totalStudents, int courseCount)
{
}

void CalculateScoreOfCourse(STU students[], int totalStudents, int courseCount)
{
}

void SortByNum(STU students[], int totalStudents, int courseCount)
{
}

void SortByName(STU students[], int totalStudents, int courseCount)
{
}

void SortByScore(STU students[], int totalStudents, int courseCount, int(*compare)(float a, float b))
{
}

int Ascending(float a, float b)
{
	return 0;
}

int Descending(float a, float b)
{
	return 0;
}

void StatisticAnalysis(STU students[], int totalStudents, int courseCount)
{
}

void PrintRecord(STU students[], int totalStudents, int courseCount)
{
}

void WriteToFile(STU records[], int totalStudents, int courseCount)
{
}

int ReadFromFile(STU records[], int* totalStudents, int* courseCount, int* first)
{
	return 0;
}
