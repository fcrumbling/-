#include "snake.h"

//@��ʾ��ͷ��o��ʾ����,$��ʾʳ��

/*����ȫ�ֱ���*/
Snake snake;
Food food;
char pre_Dir = right;//��ǰ��ͷ����
char toDir = right;//Ԥ����ͷ����

int Menu() {
	GotoXY(40, 12);
	printf("��ӭ����̰����");
	GotoXY(43, 14);
	printf("1.��ʼ��Ϸ");
	GotoXY(43, 16);
	printf("2.����");
	GotoXY(43, 18);
	printf("3.����");
	GotoXY(43, 20);
	printf("�������������˳���Ϸ");
	Hide();
	char number;
	int result = 0;
	number = _getch();
	switch (number) {
	case '1':result = 1; break;
	case '2':result = 2; break;
	case '3':result = 3; break;
	default: result = 0; break;
	}
	system("cls");
	return result;
}
void GotoXY(int x, int y) {
	HANDLE hout;//����̨����ľ��
	COORD cor;//ϣ���ƶ����Ĺ��λ��
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);//���ÿ���̨���λ��
}

void Hide(){
	HANDLE hout;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info= { 1,0 };
	SetConsoleCursorInfo(hout, &cor_info);
}

void About()
{
	GotoXY(30, 12);
	printf("̰���ߡ�������̨��Ϸ");
	GotoXY(34, 14);
	printf("���ߣ�crumbling");
	GotoXY(34, 16);
	printf("��������Է����ϼ��˵�");
	Hide();
	char number = _getch();
	system("cls");
}

void Help() {
	GotoXY(43, 12);
	printf("w ��");
	GotoXY(43, 14);
	printf("a ��");
	GotoXY(43, 16);
	printf("s ��");
	GotoXY(43, 18);
	printf("d ��");
	GotoXY(45, 20);
	printf("��������Է����ϼ��˵�");
	Hide();
	char number = _getch();
	system("cls");
}

void InitMap() {
	Hide();
	/*��ʼ����״̬*/
	snake.snakeNODE[0].x = map_width/2;
	snake.snakeNODE[0].y = map_height / 2;
	GotoXY(snake.snakeNODE[0].x, snake.snakeNODE[0].y);
	printf("@");//��ӡ��ͷ
	snake.length = 3;
	snake.speed = 250;
	pre_Dir = right;
	
	//��ʾ����
	for (int i = 1; i < snake.length; i++) {
		snake.snakeNODE[i].y = snake.snakeNODE[i - 1].y;
		snake.snakeNODE[i].x = snake.snakeNODE[i - 1].x - 1;
		GotoXY(snake.snakeNODE[i].x, snake.snakeNODE[i].y);
		printf("o");
	}

	//���ɵ�ͼ
	for (int i = 0; i < map_width; i++) {
		GotoXY(i, 0);
		printf("-");
		GotoXY(i, map_height - 1);
		printf("-");
	}
	for (int i = 0; i < map_height; i++) {
		GotoXY(0, i);
		printf("|");
		GotoXY(map_width - 1, i);
		printf("|");
	}

	//����ʳ��
	printfood();

	//�Ʒְ�
	GotoXY(50, 5);
	printf("�÷֣�0");
}

/*������һ��ʳ��*/
void printfood() {
	int flag = 1;
	while (flag) {
		flag = 0;
		food.x = rand() % (map_width - 2) + 1;
		food.y = rand() % (map_height - 2) + 1;
		for (int j=0; j < snake.length; j++) {
			if (food.x == snake.snakeNODE[j].x && food.y == snake.snakeNODE[j].y) {
				flag = 1;
				break;
			}
		}
	}
	GotoXY(food.x, food.y);
	printf("$");
}

int Snakemove() {
	Snakenode temp=snake.snakeNODE[snake.length - 1];//β�ڵ�ļ�¼
	int flag = 0;//���ڼ�¼�Ƿ�Ե�ʳ��
	for (int i = snake.length - 1; i > 0; i--) {
		snake.snakeNODE[i] = snake.snakeNODE[i - 1];//ǰ��һ��λ��
	}
	GotoXY(snake.snakeNODE[1].x, snake.snakeNODE[1].y);//����ƶ���ԭ��ͷ����
	printf("o");//��ӡһ�������൱����ͷ�滻���˽ڵ�

	if (_kbhit()) {//�������뷵��1���Ǽ������뷵��0 
		toDir = _getch();
		switch (toDir) {
		case up:
			if (pre_Dir != down)
				pre_Dir = toDir;
			break;
		case down:
			if (pre_Dir != up)
				pre_Dir = toDir;
			break;
		case left:
			if (pre_Dir != right)
				pre_Dir = toDir;
			break;
		case right:
			if (pre_Dir != left)
				pre_Dir = toDir;
			break;
		}
	}
	switch (pre_Dir) {
	case up:snake.snakeNODE[0].y--; break;
	case down:snake.snakeNODE[0].y++; break;
	case left:snake.snakeNODE[0].x--; break;
	case right:snake.snakeNODE[0].x++; break;
	}
	GotoXY(snake.snakeNODE[0].x, snake.snakeNODE[0].y);
	printf("@");
	if (snake.snakeNODE[0].x == food.x && snake.snakeNODE[0].y == food.y) {
		snake.length++;
		flag = 1;//1��ʾ�Ե�ʳ��
		snake.snakeNODE[snake.length - 1] = temp;//��β��һ��
	}
	//��ĳ������Ե�ʳ��൱��ʳ������ͷ��ԭ��ͷ�������
	//�����ʱ�ߵ�״̬
	if (!flag) {
		GotoXY(temp.x, temp.y);
		printf(" ");//û�Ե���ɾ����β
	}
	else {
		printfood();
		GotoXY(50, 5);
		printf("��ǰ�÷�:%d", snake.length - 3);
	}
	/*�ж��Ƿ������������������Ļ��ӡ����*/
	if (!check()) {
		system("cls");
		GotoXY(45, 14);
		printf("Game Over");
		GotoXY(45, 16);
		printf("���յ÷�:%d", snake.length - 3);
		GotoXY(45, 18);
		printf("��������������˵�");
		char ch = _getch();
		system("cls");
		return 0;
	}
	//�����ٶ�
	speedcontrol();
	Sleep(snake.speed);
	return 1;
}

int check() {
	if (snake.snakeNODE[0].x == 0 || snake.snakeNODE[0].y == 0 || snake.snakeNODE[0].x == map_width - 1 || snake.snakeNODE[0].y == map_height - 1)
		return 0;
	for (int i = 1; i < snake.length; i++) {
		if (snake.snakeNODE[0].x == snake.snakeNODE[i].x && snake.snakeNODE[0].y == snake.snakeNODE[i].y)
			return 0;
	}
	return 1;
}

void speedcontrol() {
	switch (snake.length) {
	case 6:snake.speed = 200; break;
	case 9:snake.speed = 180; break;
	case 12:snake.speed = 160; break;
	case 15:snake.speed = 140; break;
	case 18:snake.speed = 120; break;
	case 21:snake.speed = 100; break;
	case 24:snake.speed = 80; break;
	case 27:snake.speed = 60; break;
	case 30:snake.speed = 40; break;
	case 33:snake.speed = 20; break;
	default:break;
	}
}