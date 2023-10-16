//snake.cpp

#include "snake.h"

//@��ʾ��ͷ��o��ʾ����,$��ʾʳ��

/*����ȫ�ֱ���*/
Snake snake;
Food foods[FOOD_COUNT];
char pre_Dir = right;//��ǰ��ͷ����
char toDir = right;//Ԥ����ͷ����
int ranks[100];//��¼���η�����͵���������100�����顣
int rankindex = 0;
int blocknumber = 5;//�ϰ������ �����ϰ���Ĵ������һ�㣬���Ǻ����᲻ͨ�ã�����ֱ�ӴӸ�������ʼ��
Block blocks[5], block;//��¼�ϰ���
int backdoor = 1;//����δ����


char foodTypes[] = { '$', '*', '%' };// ʳ����������

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
	printf("4.���а�");
	GotoXY(43, 22);
	printf("�������������˳���Ϸ");
	Hide();
	char number;
	int result = 0;
	number = _getch();
	switch (number) {
	case '1':result = 1; break;
	case '2':result = 2; break;
	case '3':result = 3; break;
	case '4':result = 4; break;
	case '5':result = 5; break;
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

void Hide() {
	HANDLE hout;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cor_info);
}

void About()
{
	GotoXY(30, 12);
	printf("̰���ߡ�������̨��Ϸ");
	GotoXY(34, 14);
	printf("���ߣ�crumbling��yuuki");
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
	snake.snakeNODE[0].x = map_width / 2;
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
	//�����ϰ���
	printblock();
	//�Ʒְ�
	GotoXY(50, 5);
	printf("�÷֣�0");
}

/*����FOOD_COUNT��ʳ��*/
void printfood() {
	for (int i = 0; i < FOOD_COUNT; i++) {
		int not_permitted = 1;//Ĭ�ϲ�������ͨ�������ǲ��������ص�


		while (not_permitted) {
			not_permitted = 0;
			foods[i].x = rand() % (map_width - 2) + 1;
			foods[i].y = rand() % (map_height - 2) + 1;
			foods[i].type = foodTypes[rand() % 3];

			//���ʳ���Ƿ��������غ�
			for (int j = 0; j < snake.length; j++) {
				if (foods[i].x == snake.snakeNODE[j].x && foods[i].y == snake.snakeNODE[j].y) {
					not_permitted = 1;
					break;
				}
			}

			//���ʳ���Ƿ�������ʳ���غ�
			for (int k = 0; k < i; k++) {
				if (foods[i].x == foods[k].x && foods[i].y == foods[k].y) {
					not_permitted = 1;
					break;
				}
			}
		}
		GotoXY(foods[i].x, foods[i].y);
		printf("%c", foods[i].type);
	}
}



int Snakemove() {
	Snakenode temp = snake.snakeNODE[snake.length - 1];//β�ڵ�ļ�¼
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
		case 'q':
			system("cls");
			GotoXY(45, 14);
			printf("Game Over");
			GotoXY(45, 16);
			printf("���յ÷�:%d", snake.length - 3);
			ranks[rankindex++] = snake.length - 3;
			GotoXY(45, 18);
			printf("��������������˵�");
			char ch = _getch();
			system("cls");
			return 0;
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

	static int eatenFoodsCount = 0; // ��¼�ѱ��Ե���ʳ������

	int eatenIndex = -1;  // Ĭ��ֵΪ-1����ʾδ�Ե�ʳ��

	// �������е�ʳ��
	for (int i = 0; i < FOOD_COUNT; i++) {
		if (snake.snakeNODE[0].x == foods[i].x && snake.snakeNODE[0].y == foods[i].y) {
			eatenIndex = i;  // ��¼���Ե���ʳ�������
			break;
		}
	}

	// ����Ե���ʳ��
	if (eatenIndex != -1) {
		switch (foods[eatenIndex].type) {
		case '$':
			snake.length++;
			break;
		case '*':
			snake.length += 2;
			break;
		case '%':
			snake.length += 3;
			break;
		}
		flag = 1; // 1��ʾ�Ե�ʳ��
		snake.snakeNODE[snake.length - 1] = temp; // ��β��һ��

		eatenFoodsCount++;  // ���ӱ��Ե���ʳ�������

		// �������ʳ�ﶼ���Ե�
		if (eatenFoodsCount == FOOD_COUNT) {
			// ������������ʳ��
			for (int i = 0; i < FOOD_COUNT; i++) {
				foods[i].x = rand() % (map_width - 2) + 1;
				foods[i].y = rand() % (map_height - 2) + 1;
				foods[i].type = foodTypes[rand() % 3];
			}
			clear();
			printfood();
			printblock();

			eatenFoodsCount = 0;  // ���ñ��Ե���ʳ�������
		}
	}

	//��ĳ������Ե�ʳ��൱��ʳ������ͷ��ԭ��ͷ�������
	//�����ʱ�ߵ�״̬
	if (!flag) {
		GotoXY(temp.x, temp.y);
		printf(" ");//û�Ե���ɾ����β
	}
	else {
		//printfood();
		GotoXY(50, 5);
		printf("��ǰ�÷�:%d", snake.length - 3);
	}
	/*�ж��Ƿ������������������Ļ��ӡ����*/
	if (backdoor && (!check() || !blockcheck())) {
		system("cls");
		GotoXY(45, 14);
		printf("Game Over");
		GotoXY(45, 16);
		printf("���յ÷�:%d", snake.length - 3);
		ranks[rankindex++] = snake.length - 3;
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


//��������ʳ���Ҫ�ж��Ƿ���ʳ��
void printblock() {
	int i = blocknumber;
	while (i--) {
		block.x = rand() % (map_width - 2) + 1;
		block.y = rand() % (map_height - 2) + 1;

		// ����ϰ����Ƿ��������غ�
		for (int j = 0; j < snake.length; j++) {
			if (block.x == snake.snakeNODE[j].x && block.y == snake.snakeNODE[j].y) {
				i++;
				break;
			}
		}

		// ����ϰ����Ƿ���ʳ���غ�
		for (int k = 0; k < FOOD_COUNT; k++) {
			if (block.x == foods[k].x && block.y == foods[k].y) {
				i++;
				break;
			}
		}

		blocks[i].x = block.x;
		blocks[i].y = block.y;
		GotoXY(block.x, block.y);
		printf("#");
	}
}


int blockcheck() {
	for (int j = 0; j < blocknumber; j++) {
		for (int i = 0; i < snake.length; i++) {
			if (blocks[j].x == snake.snakeNODE[i].x && blocks[j].y == snake.snakeNODE[i].y)
				return 0;
		}
	}
	return 1;
}

void Rank() {
	GotoXY(43, 12);
	printf("���а�");
	sort(0, rankindex - 1);
	for (int i = 0; i < rankindex; i++) {
		GotoXY(43, 14 + 2 * i);
		printf("%d.%d", i + 1, ranks[rankindex - i - 1]);
	}
	GotoXY(43, 14 + 2 * rankindex);
	printf("��������Է����ϼ��˵�");
	Hide();
	char number = _getch();
	system("cls");
}

void sort(int low, int high) {
	int i = low;
	int j = high;
	int key = ranks[i];
	while (i < j) {
		while (i < j && ranks[j] >= key)j--;
		ranks[i] = ranks[j];
		while (i < j && ranks[i] <= key)i++;
		ranks[j] = ranks[i];
	}
	ranks[i] = key;
	if (i - 1 > low) sort(low, i - 1);
	if (i + 1 < high) sort(i + 1, high);
}

void Backdoor() {
	if (backdoor) {
		backdoor = 0;
		GotoXY(43, 12);
		printf("����������,q�˳����ٴδ򿪴�ҳ�����˳�����.");
		GotoXY(45, 14);
		printf("��������Է����ϼ��˵�");
		Hide();
		char number = _getch();
		system("cls");
	}
	else {
		backdoor = 1;
		GotoXY(43, 12);
		printf("�����ѹر�");
		GotoXY(45, 14);
		printf("��������Է����ϼ��˵�");
		Hide();
		char number = _getch();
		system("cls");
	}

}

void clear() {
	for (int j = 0; j < blocknumber; j++) {
		GotoXY(blocks[j].x, blocks[j].y);
		printf(" ");
	}
}