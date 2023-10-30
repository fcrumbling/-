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

void DeleteRecord(STU students[], int* totalStudents, int courseCount)
{
	int i, j;
	long id;
	char ch;
	printf("��������Ҫɾ��ѧ����Ϣ��Ӧ��ѧ�ţ�");
	scanf_s("%ld", &id);
	for (i = 0; i < *totalStudents; i++)
	{
		if (students[i].num == id)
		{
			printf("�ҵ��˸�ѧ���ļ�¼����ϢΪ��\n");
			printf("%10ld%15s", students[i].num, students[i].name);
			for (j = 0; j < courseCount; j++) {
				printf("%10.2f", students[i].score[j]);
			}
			printf("%10.2f%10.2f\n", students[i].sum, students[i].aver);
			printf("��ȷ���Ƿ���Ҫɾ��������¼����Y/y��N/n��:");
			getchar();
			scanf_s("%c", &ch);
			if (ch == 'Y' || ch == 'y') {
				for (j = i; j < *totalStudents - 1; j++)
				{
					students[j] = students[j + 1];
				}
				printf("ɾ�����\n");
				return;
			}
			else if (ch == 'N' || ch == 'n') {
				printf("�ҵ��˸�ѧ����¼������ɾ��");
				return;
			}
			else {
				printf("�������\n");
				return;
			}
		}
	}
	printf("û�ҵ���¼��\n");
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
	printf("��������Ҫ���ҵ�ѧ��������");
	scanf_s("%s", name);
	for (i = 0; i < totalStudents; i++) {
		if (strcmp(students[i].name, name) == 0) {
			printf("�ҵ��ˣ���%dѧ����ϢΪ:\n", ++k);
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

void WriteToFile(STU students[], int totalStudents, int courseCount, const char* filePath)
{
	int i, j;
	FILE* fp = NULL;
	errno_t err = fopen_s(&fp, filePath, "w");
	if (err != 0 || fp == NULL) {
		std::cout << "�ļ���ʧ��!" << std::endl;
		exit(0);
	}

	int ret = fprintf(fp, "%10d%10d\n", totalStudents, courseCount);
	if (ret < 0) {
		std::cout << "д���ļ�ʧ��!" << std::endl;
		fclose(fp);
		exit(0);
	}

	for (i = 0; i < totalStudents; i++) {
		// ȷ����������null��ֹ��
		students[i].name[sizeof(students[i].name) - 1] = '\0';

		ret = fprintf(fp, "%10ld%50s", students[i].num, students[i].name);
		if (ret < 0) {
			std::cout << "д���ļ�ʧ��!" << std::endl;
			fclose(fp);
			exit(0);
		}

		for (j = 0; j < courseCount; j++) {
			ret = fprintf(fp, "%10f", students[i].score[j]);
			if (ret < 0) {
				std::cout << "д���ļ�ʧ��!" << std::endl;
				fclose(fp);
				exit(0);
			}
		}

		ret = fprintf(fp, "%10lf%10lf\n", students[i].sum, students[i].aver);
		if (ret < 0) {
			std::cout << "д���ļ�ʧ��!" << std::endl;
			fclose(fp);
			exit(0);
		}
	}

	fclose(fp);
	std::cout << "�ļ�����ɹ���" << std::endl;
}


int ReadFromFile(STU records[], int* totalStudents, int* courseCount, int* first)
{
	FILE* fp = NULL;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);  
	errno_t err = fopen_s(&fp, ".\\data\\records.txt", "r");
	if (err != 0 || fp == NULL) {
		std::cout << "�ļ���ʧ��!";
		return 1;
	}

	int ret = fscanf_s(fp, "%10d%10d", totalStudents, courseCount);
	if (ret != 2) {
		std::cout << "��ȡ�ļ�ͷʧ��!";
		fclose(fp);
		return 1;
	}

	for (i = 0; i < *totalStudents; i++) {
		ret = fscanf_s(fp, "%10ld%50s", &records[i].num, records[i].name, _countof(records[i].name));
		if (ret != 2) {
			std::cout << "��ȡѧ����¼ʧ��!";
			fclose(fp);
			return 1;
		}

		for (j = 0; j < *courseCount; j++) {
			ret = fscanf_s(fp, "%10f", &records[i].score[j]);  // ����Ϊ %10f
			if (ret != 1) {
				std::cout << "��ȡ����ʧ��!";
				fclose(fp);
				return 1;
			}
		}

		ret = fscanf_s(fp, "%10f%10f", &records[i].sum, &records[i].aver);  // ����Ϊ %10f
		if (ret != 2) {
			std::cout << "��ȡ�ֺܷ�ƽ����ʧ��!";
			fclose(fp);
			return 1;
		}
	}

	fclose(fp);
	printf("��ȡ��ϣ�\n");
	return 0;
}