//logic.cpp
#include "main.h"

//���
void SetPosition(int x, int y) {
	HANDLE hOut;
	COORD pos = { x,y };//ֱ�ӹ���λ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

//��ʱ��
void countdown(int seconds,int posy) {
	SetPosition(POS_X2, ++posy);
	for (int i = seconds; i > 0; --i) {
		SetPosition(POS_X2, posy);
		printf(" % d ��󷵻�...\n", i);
		Sleep(1000);  // Sleep for 1000 milliseconds (1 second)
		//system("CLS");  // ����
	}
	SetPosition(POS_X2, ++posy);
	printf("������...\n");
}

void InputRecord(STU students[], int* totalStudents, int* courseCount)
{
	int i, j;
	int posy = 6;
	SetPosition(POS_X2, posy);
	printf_s("������ѧ������(n<%d):",STU_NUM);
	scanf_s("%d", totalStudents);
	SetPosition(POS_X2, posy+=2);
	printf_s("������γ���(n<%d):", COURSE_NUM);
	scanf_s("%d", courseCount);
	for (i = 0; i < 2; i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++) {
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf_s("������%d��ѧ����ѧ�š������͸��ſγ̳ɼ�:", *totalStudents);
	for (i = 0; i < *totalStudents; i++)
	{
		SetPosition(POS_X2, ++posy);
		printf("�����%d����Ϣ\t", i + 1);
		cin >>students[i].num >> students[i].name;
		for (j = 0; j < *courseCount; j++) {
			cin >> students[i].score[j];
		}
	}

	// ��¼�����֮��
	SetPosition(POS_X2, ++posy);
	printf("¼��ɹ���\n");
	countdown(2,posy);  // ��ʼ2�뵹��ʱ

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
	cout << ("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
	for ( i = 0; i < totalStudents; i++) {
		students[i].sum = 0;
		for (j = 0; j < courseCount; j++) { students[i].sum += students[i].score[j]; }
		students[i].aver = students[i].sum / courseCount;
		printf("��%d��ѧ�����ܷ�=%.2fƽ����=%.2f\n", i + 1, students[i].sum, students[i].aver);
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
		printf("��%d�ſγ̣��ܷ�=%.2fƽ����=%.2f\n", i + 1, sum[i], aver[i]);
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
		cout << "�ļ���ʧ��!";
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
	cout << "�ļ�����ɹ���"<<endl; 
}

int ReadFromFile(STU records[], int* totalStudents, int* courseCount, int* first)
{
	return 0;
}
