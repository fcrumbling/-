#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>


#define map_height 20
#define map_width 40
#define up 'w'
#define down 's'
#define right 'd'
#define left 'a'

typedef struct //����ʳ����߽ڵ�λ��  �����ϰ����λ��
{
	int x;
	int y;
}Food,Snakenode,Block;

typedef struct
{
	Snakenode snakeNODE[1000];//�߽ڵ�����
	int length;
	int speed;
}Snake;

/*��������*/
void GotoXY(int, int);//��궨λ
void Hide();//���ع��
void Help();//����
void About();//����
void InitMap();//��ͼ��ʼ��
void printfood();//ʳ������
void speedcontrol();//�ٶȿ���
int Snakemove();//���ƶ�
int check();//��ײ��ײǽ���
int Menu();//���˵�

void printblock();//�ϰ�������
int blockcheck();//�ϰ�����ײ���
void Rank();//�񵥹���  ÿ����գ�ֻ��¼�ļ�ִ���������ڼ�ķ���
void sort(int,int);//���� ����
void Backdoor();//��������������