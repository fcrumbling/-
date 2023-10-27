// menu.cpp
#include "main.h"

int Menu() {
    int posy = 5;
    int option;
    int i, j;
    SetPosition(POS_X3, posy);
    printf("学生成绩管理系统\n");//输出系统的的名字
    //输出分割线
    for (i = 0; i < 2; i++) {
		SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++) {
			printf("-"); 
        }
    }
    //输出系统支持的功能和对应的功能代号
    SetPosition(POS_X1, ++posy);
	printf("1.输入学生成绩\n");
	SetPosition(POS_X4, posy);
	printf("2.增加学生成绩\n");
	SetPosition(POS_X1, posy+=2);
	printf("3.删除学生成绩\n");
	SetPosition(POS_X4, posy);
	printf("4.按学号查找记录\n");
	SetPosition(POS_X1, posy+=2);
	printf("5.按姓名查找记录\n");
	SetPosition(POS_X4, posy);
	printf("6.修改学生信息\n");
	SetPosition(POS_X1, posy += 2);
	printf("7.计算学生成绩\n");
	SetPosition(POS_X4, posy);
	printf("8.计算课程成绩\n");
	SetPosition(POS_X1, posy += 2);
	printf("9.按学号排序\n");
	SetPosition(POS_X4, posy);
	printf("10.按姓名排序\n");
	SetPosition(POS_X1, posy += 2);
	printf("11.按总成绩降序排序\n");
	SetPosition(POS_X4, posy);
	printf("12.按总成绩升序排序\n");
	SetPosition(POS_X1, posy += 2);
	printf("13.学生成绩统计\n");
	SetPosition(POS_X4, posy);
	printf("14.打印学生记录\n");
	SetPosition(POS_X1, posy += 2);
	printf("15.学生记录存盘\n");
	SetPosition(POS_X4, posy);
	printf("16.从磁盘读取学生记录\n");
	SetPosition(POS_X1, posy += 2);
	printf("0.退出\n");
	//输出分割线
	for (int i = 0; i < 2; i++) {
		SetPosition(POS_X1,++posy);
		for (j = 0; j < 55; j++) {
			printf("-");
		}
	}

	SetPosition(POS_X1, ++posy);
	printf("请输入你的选择:[0-16]:[  ]\b\b\b");
	scanf_s("%d", &option);
	return option;

}
