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

void DeleteRecord(STU students[], int* totalStudents, int courseCount)
{
	int i, j;
	long id;
	char ch;
	printf("请输入你要删除学生信息对应的学号：");
	scanf_s("%ld", &id);
	for (i = 0; i < *totalStudents; i++)
	{
		if (students[i].num == id)
		{
			printf("找到了该学生的记录，信息为：\n");
			printf("%10ld%15s", students[i].num, students[i].name);
			for (j = 0; j < courseCount; j++) {
				printf("%10.2f", students[i].score[j]);
			}
			printf("%10.2f%10.2f\n", students[i].sum, students[i].aver);
			printf("请确认是否需要删除这条记录？（Y/y或N/n）:");
			getchar();
			scanf_s("%c", &ch);
			if (ch == 'Y' || ch == 'y') {
				for (j = i; j < *totalStudents - 1; j++)
				{
					students[j] = students[j + 1];
				}
				printf("删除完毕\n");
				return;
			}
			else if (ch == 'N' || ch == 'n') {
				printf("找到了该学生记录，但不删除");
				return;
			}
			else {
				printf("输入出错！\n");
				return;
			}
		}
	}
	printf("没找到记录！\n");
	return;
}


void SearchByNum(STU students[], int totalStudents, int courseCount)
{
}

void SearchByName(STU students[], int totalStudents, int courseCount)
{
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("请输入你要查找的学生的姓名");
	scanf_s("%s", name);
	for (i = 0; i < totalStudents; i++) {
		if (strcmp(students[i].name, name) == 0) {
			printf("找到了，第%d学生信息为:\n", ++k);
			for (j = 0; j < courseCount; j++) {
				printf("%10.2f", students[i].score[j]);
			}
			printf("%10.2f%10.2f\n0", students[i].num, students[i].aver);
		}
	}
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

void WriteToFile(STU students[], int totalStudents, int courseCount, const char* filePath)
{
	int i, j;
	FILE* fp = NULL;
	errno_t err = fopen_s(&fp, filePath, "w");
	if (err != 0 || fp == NULL) {
		std::cout << "文件打开失败!" << std::endl;
		exit(0);
	}

	int ret = fprintf(fp, "%10d%10d\n", totalStudents, courseCount);
	if (ret < 0) {
		std::cout << "写入文件失败!" << std::endl;
		fclose(fp);
		exit(0);
	}

	for (i = 0; i < totalStudents; i++) {
		// 确保名字是以null终止的
		students[i].name[sizeof(students[i].name) - 1] = '\0';

		ret = fprintf(fp, "%10ld%50s", students[i].num, students[i].name);
		if (ret < 0) {
			std::cout << "写入文件失败!" << std::endl;
			fclose(fp);
			exit(0);
		}

		for (j = 0; j < courseCount; j++) {
			ret = fprintf(fp, "%10f", students[i].score[j]);
			if (ret < 0) {
				std::cout << "写入文件失败!" << std::endl;
				fclose(fp);
				exit(0);
			}
		}

		ret = fprintf(fp, "%10lf%10lf\n", students[i].sum, students[i].aver);
		if (ret < 0) {
			std::cout << "写入文件失败!" << std::endl;
			fclose(fp);
			exit(0);
		}
	}

	fclose(fp);
	std::cout << "文件保存成功！" << std::endl;
}


int ReadFromFile(STU records[], int* totalStudents, int* courseCount, int* first)
{
	FILE* fp = NULL;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);  
	errno_t err = fopen_s(&fp, ".\\data\\records.txt", "r");
	if (err != 0 || fp == NULL) {
		std::cout << "文件打开失败!";
		return 1;
	}

	int ret = fscanf_s(fp, "%10d%10d", totalStudents, courseCount);
	if (ret != 2) {
		std::cout << "读取文件头失败!";
		fclose(fp);
		return 1;
	}

	for (i = 0; i < *totalStudents; i++) {
		ret = fscanf_s(fp, "%10ld%50s", &records[i].num, records[i].name, _countof(records[i].name));
		if (ret != 2) {
			std::cout << "读取学生记录失败!";
			fclose(fp);
			return 1;
		}

		for (j = 0; j < *courseCount; j++) {
			ret = fscanf_s(fp, "%10f", &records[i].score[j]);  // 更新为 %10f
			if (ret != 1) {
				std::cout << "读取分数失败!";
				fclose(fp);
				return 1;
			}
		}

		ret = fscanf_s(fp, "%10f%10f", &records[i].sum, &records[i].aver);  // 更新为 %10f
		if (ret != 2) {
			std::cout << "读取总分和平均分失败!";
			fclose(fp);
			return 1;
		}
	}

	fclose(fp);
	printf("读取完毕！\n");
	return 0;
}