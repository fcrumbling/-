// menu.cpp
#include "main.h"

int Menu() {
    int posy = 5;
    int option;
    int i, j;
    SetPosition(POS_X3, posy);
    printf("ѧ���ɼ�����ϵͳ\n");//���ϵͳ�ĵ�����
    //����ָ���
    for (i = 0; i < 2; i++) {
		SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++) {
			printf("-"); 
        }
    }
    //���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
    SetPosition(POS_X1, ++posy);
	printf("1.����ѧ���ɼ�\n");
	SetPosition(POS_X4, posy);
	printf("2.����ѧ���ɼ�\n");
	SetPosition(POS_X1, posy+=2);
	printf("3.ɾ��ѧ���ɼ�\n");
	SetPosition(POS_X4, posy);
	printf("4.��ѧ�Ų��Ҽ�¼\n");
	SetPosition(POS_X1, posy+=2);
	printf("5.���������Ҽ�¼\n");
	SetPosition(POS_X4, posy);
	printf("6.�޸�ѧ����Ϣ\n");
	SetPosition(POS_X1, posy += 2);
	printf("7.����ѧ���ɼ�\n");
	SetPosition(POS_X4, posy);
	printf("8.����γ̳ɼ�\n");
	SetPosition(POS_X1, posy += 2);
	printf("9.��ѧ������\n");
	SetPosition(POS_X4, posy);
	printf("10.����������\n");
	SetPosition(POS_X1, posy += 2);
	printf("11.���ܳɼ���������\n");
	SetPosition(POS_X4, posy);
	printf("12.���ܳɼ���������\n");
	SetPosition(POS_X1, posy += 2);
	printf("13.ѧ���ɼ�ͳ��\n");
	SetPosition(POS_X4, posy);
	printf("14.��ӡѧ����¼\n");
	SetPosition(POS_X1, posy += 2);
	printf("15.ѧ����¼����\n");
	SetPosition(POS_X4, posy);
	printf("16.�Ӵ��̶�ȡѧ����¼\n");
	SetPosition(POS_X1, posy += 2);
	printf("0.�˳�\n");
	//����ָ���
	for (int i = 0; i < 2; i++) {
		SetPosition(POS_X1,++posy);
		for (j = 0; j < 55; j++) {
			printf("-");
		}
	}

	SetPosition(POS_X1, ++posy);
	printf("���������ѡ��:[0-16]:[  ]\b\b\b");
	scanf_s("%d", &option);
	return option;

}
