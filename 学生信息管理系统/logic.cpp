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
void countdown(int seconds, int posy) {
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
	printf_s("请输入学生人数(n<%d):", STU_NUM);
	scanf_s("%d", totalStudents);
	SetPosition(POS_X2, posy += 2);
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
		cin >> students[i].num >> students[i].name;
		for (j = 0; j < *courseCount; j++) {
			cin >> students[i].score[j];
		}
	}

	// 在录入完毕之后
	SetPosition(POS_X2, ++posy);
	printf("录入成功！\n");
	countdown(2, posy);  // 开始2秒倒计时

}


void AppendRecord(STU students[], int* totalStudents, int courseCount)
{
	int i, j;
	int num_record;
	cout << "请输入要增加的学生记录条数：" << endl;
	cin >> num_record;
	for (i = *totalStudents; i < *totalStudents + num_record; i++) {
		cout << "请输入第" << i + 1 << "个学生的信息：" << endl;
		cin >> students[i].num >> students[i].name;
		for (j = 0; j < courseCount; j++) {
			cin >> students[i].score[j];
		}
	}
	*totalStudents += num_record;
	cout << "增加成功！" << endl;
	return;
}

void DeleteRecord(STU students[], int totalStudents, int courseCount)
{
}

void SearchByNum(STU students[], int totalStudents, int courseCount)
{
	long id;
	int i, j;
	cout << "请输入要查找的学生学号：" << endl;
	cin >> id;
	for (int i = 0; i < totalStudents; i++) {
		if (students[i].num == id) {
			cout << "查找成功！" << endl;
			for (j = 0; j < courseCount; j++) {
				cout << "第" << i + 1 << "个学生的第" << j + 1 << "门课程的成绩为:" << students[i].score[j] << endl;
			}
			return;
		}
	}
	printf("查找失败!\n");
	return;
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
	for (i = 0; i < totalStudents; i++) {
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
	int i, j, t[6];
	for (int j = 0; j < courseCount; j++) {
		cout << "\n课程" << j + 1 << "成绩结果统计为：\n";
		memset(t, 0, sizeof(t));
		for (int i = 0; i < totalStudents; i++) {
			if (students[i].score[j] >= 0 && students[i].score[j] < 60) {
				t[0]++;
			}
			else if (students[i].score[j] >= 60 && students[i].score[j] < 70) {
				t[1]++;
			}
			else if (students[i].score[j] >= 70 && students[i].score[j] < 80) {
				t[2]++;
			}
			else if (students[i].score[j] >= 80 && students[i].score[j] < 90) {
				t[3]++;
			}
			else if (students[i].score[j] >= 90 && students[i].score[j] <= 100) {
				t[4]++;
			}
			else if (students[i].score[j] == 100) {
				t[5]++;
			}
		}
		for (int i = 0; i < 6; i++) {
			if (i == 0)printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / totalStudents * 100);
			else if (i == 5)printf(">=100\t%d\t%.2f%%\n", t[i], (float)t[i] / totalStudents * 100);
			else printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / totalStudents * 100);
		}
	}
	cout << "\n" << "学生成绩平均分统计结果为" << endl;
	cout << "分数段\t人数\t占比\n";
	memset(t, 0, sizeof(t));
	for (int i = 0; i < totalStudents; i++) {
		if (students[i].aver >= 0 && students[i].aver < 60) {
			t[0]++;
		}
		else if (students[i].aver >= 60 && students[i].aver < 70) {
			t[1]++;
		}
		else if (students[i].aver >= 70 && students[i].aver < 80) {
			t[2]++;
		}
		else if (students[i].aver >= 80 && students[i].aver < 90) {
			t[3]++;
		}
		else if (students[i].aver >= 90 && students[i].aver <= 100) {
			t[4]++;
		}
		else if (students[i].aver == 100) {
			t[5]++;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (i == 0)printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / totalStudents * 100);
		else if (i == 5)printf(">=100\t%d\t%.2f%%\n", t[i], (float)t[i] / totalStudents * 100);
		else printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / totalStudents * 100);
	}
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

	int ret = fscanf(fp, "%10d%10d", totalStudents, courseCount);
	if (ret != 2) {
		std::cout << "读取文件头失败!";
		fclose(fp);
		return 1;
	}

	for (i = 0; i < *totalStudents; i++) {
		ret = fscanf(fp, "%10ld%50s", &records[i].num, records[i].name, _countof(records[i].name));
		if (ret != 2) {
			std::cout << "读取学生记录失败!";
			fclose(fp);
			return 1;
		}

		for (j = 0; j < *courseCount; j++) {
			ret = fscanf(fp, "%10f", &records[i].score[j]);  // 更新为 %10f
			if (ret != 1) {
				std::cout << "读取分数失败!";
				fclose(fp);
				return 1;
			}
		}

		ret = fscanf(fp, "%10f%10f", &records[i].sum, &records[i].aver);  // 更新为 %10f
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