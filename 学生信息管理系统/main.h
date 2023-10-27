// main.h
#pragma once
#include <iostream>
#include <string>
#include<Windows.h>
#include<conio.h>
using namespace std;

#define STU_NUM 50
#define COURSE_NUM 10
#define NAME_LEN 10
#define STU_NUM 50//��ѧ������������
#define COURSE_NUM 10//һѧ�ڿγ���������
#define NAME_LEN 10//ѧ��������������
#define POS_X1 35//��һ��
#define POS_X2 40
#define POS_X3 50//����
#define POS_X4 60//�ڶ���
#define POS_Y 3


struct Student {
    long num;
    string name;
    float score[COURSE_NUM];
    float sum;
    float aver;
};

using STU = Student;

int Menu();

// ���ÿ���̨���λ��
void SetPosition(int x, int y);

// ������ѧ����¼
void InputRecord(STU students[], int* totalStudents, int* courseCount);

// ׷��ѧ����¼
void AppendRecord(STU students[], int* totalStudents, int courseCount);

// ɾ��ָ��ѧ����¼
void DeleteRecord(STU students[], int totalStudents, int courseCount);

// ͨ��ѧ������ѧ����¼
void SearchByNum(STU students[], int totalStudents, int courseCount);

// ͨ����������ѧ����¼
void SearchByName(STU students[], int totalStudents, int courseCount);

// �޸�ָ��ѧ����¼
void ModifyRecord(STU students[], int totalStudents, int courseCount);

// ���㵥��ѧ���ĳɼ����ֺܷ�ƽ���ֵȣ�
void CalculateScoreOfStudent(STU students[], int totalStudents, int courseCount);

// ����ÿ�ſγ̵ĳɼ�����ƽ���֣�
void CalculateScoreOfCourse(STU students[], int totalStudents, int courseCount);

// ��ѧ������ѧ����¼
void SortByNum(STU students[], int totalStudents, int courseCount);

// ����������ѧ����¼
void SortByName(STU students[], int totalStudents, int courseCount);

// ���ɼ�����ѧ����¼���ɴ����Զ���ıȽϺ���
void SortByScore(STU students[], int totalStudents, int courseCount, int (*compare)(float a, float b));

// ����Ƚ�����������
int Ascending(float a, float b);

// ����Ƚ�����������
int Descending(float a, float b);

// ͳ�Ʒ�������ƽ���֣���߷ֵȣ�
void StatisticAnalysis(STU students[], int totalStudents, int courseCount);

// ��ӡ����ѧ����¼
void PrintRecord(STU students[], int totalStudents, int courseCount);

// ��ѧ����¼д���ļ�
void WriteToFile(STU students[], int totalStudents, int courseCount);

// ���ļ���ȡѧ����¼
int ReadFromFile(STU records[], int* totalStudents, int* courseCount, int* first);
