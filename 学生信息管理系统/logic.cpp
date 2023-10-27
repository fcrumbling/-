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
	for (i = 0; i < 2; i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++) {
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf_s("请输入%d个学生的学号、姓名和各门课程成绩:", *totalStudents);
	for (i = 0; i < *totalStudents; i++)
	{
		SetPosition(POS_X2, ++posy);
		printf("输入第%d个信息\t", i + 1);
		cin >>students[i].num >> students[i].name;
		for (j = 0; j < *courseCount; j++) {
			cin >> students[i].score[j];
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
	int i, j;
	cout << ("每个学生各门课程的总分和平均分为：\n");
	for ( i = 0; i < totalStudents; i++) {
		students[i].sum = 0;
		for (j = 0; j < courseCount; j++) { students[i].sum += students[i].score[j]; }
		students[i].aver = students[i].sum / courseCount;
		printf("第%d个学生：总分=%.2f平均分=%.2f\n", i + 1, students[i].sum, students[i].aver);
	}
	
	
}


void CalculateScoreOfCourse(STU students[], int totalStudents, int courseCount)
{
	int i, j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("??\n");
	for (i = 0; i < courseCount; i++) {
		sum[i] = 0;
		aver[i] = 0;
		for (j = 0; j < totalStudents; j++) {
			sum[i] += students[j].score[i];
		}
		aver[i] = sum[i] / totalStudents;
		printf("第%d门课程：总分=%.2f平均分=%.2f\n", i + 1, sum[i], aver[i]);
	}
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

void WriteToFile(STU students[], int totalStudents, int courseCount)
{
	int i, j;
	FILE* fp = NULL;
	errno_t err = fopen_s(&fp, ".\\data\\records.txt", "w");
	if (err != 0 || fp == NULL) {
		cout << "文件打开失败!";
		exit(0);
	}

	fprintf(fp, "%10ld%10d\n", totalStudents, courseCount);
	for (i = 0; i < totalStudents; i++) {
		fprintf(fp, "%10ld%10s", students[i].num, students[i].name);
		for (j = 0; j < courseCount; j++) {
			fprintf(fp, "%10lf", students[i].score[j]);
		}
		fprintf(fp, "%10ld%10lf\n", students[i].sum, students[i].aver);
	}
	fclose(fp);
	cout << "文件保存成功！"<<endl; 
}

int ReadFromFile(STU records[], int* totalStudents, int* courseCount, int* first)
{
	return 0;
}
