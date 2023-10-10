#include "snake.h"

//@表示蛇头，o表示蛇身,$表示食物

/*定义全局变量*/
Snake snake;
Food food;
char pre_Dir = right;//当前蛇头方向
char toDir = right;//预期蛇头方向

int Menu() {
	GotoXY(40, 12);
	printf("欢迎来玩贪吃蛇");
	GotoXY(43, 14);
	printf("1.开始游戏");
	GotoXY(43, 16);
	printf("2.帮助");
	GotoXY(43, 18);
	printf("3.关于");
	GotoXY(43, 20);
	printf("输入其他键以退出游戏");
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
	HANDLE hout;//控制台输出的句柄
	COORD cor;//希望移动到的光标位置
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);//设置控制台光标位置
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
	printf("贪吃蛇——控制台游戏");
	GotoXY(34, 14);
	printf("作者：crumbling");
	GotoXY(34, 16);
	printf("按任意键以返回上级菜单");
	Hide();
	char number = _getch();
	system("cls");
}

void Help() {
	GotoXY(43, 12);
	printf("w 上");
	GotoXY(43, 14);
	printf("a 左");
	GotoXY(43, 16);
	printf("s 下");
	GotoXY(43, 18);
	printf("d 右");
	GotoXY(45, 20);
	printf("按任意键以返回上级菜单");
	Hide();
	char number = _getch();
	system("cls");
}

void InitMap() {
	Hide();
	/*初始化蛇状态*/
	snake.snakeNODE[0].x = map_width/2;
	snake.snakeNODE[0].y = map_height / 2;
	GotoXY(snake.snakeNODE[0].x, snake.snakeNODE[0].y);
	printf("@");//打印蛇头
	snake.length = 3;
	snake.speed = 250;
	pre_Dir = right;
	
	//显示蛇身
	for (int i = 1; i < snake.length; i++) {
		snake.snakeNODE[i].y = snake.snakeNODE[i - 1].y;
		snake.snakeNODE[i].x = snake.snakeNODE[i - 1].x - 1;
		GotoXY(snake.snakeNODE[i].x, snake.snakeNODE[i].y);
		printf("o");
	}

	//生成地图
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

	//生成食物
	printfood();

	//计分板
	GotoXY(50, 5);
	printf("得分：0");
}

/*仅生成一个食物*/
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
	Snakenode temp=snake.snakeNODE[snake.length - 1];//尾节点的记录
	int flag = 0;//用于记录是否吃到食物
	for (int i = snake.length - 1; i > 0; i--) {
		snake.snakeNODE[i] = snake.snakeNODE[i - 1];//前移一个位置
	}
	GotoXY(snake.snakeNODE[1].x, snake.snakeNODE[1].y);//光标移动到原蛇头部分
	printf("o");//打印一节蛇身，相当于蛇头替换成了节点

	if (_kbhit()) {//键盘输入返回1，非键盘输入返回0 
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
		flag = 1;//1表示吃到食物
		snake.snakeNODE[snake.length - 1] = temp;//蛇尾加一节
	}
	//往某个方向吃到食物，相当于食物变成蛇头，原蛇头变成蛇身
	//输出此时蛇的状态
	if (!flag) {
		GotoXY(temp.x, temp.y);
		printf(" ");//没吃到则删除蛇尾
	}
	else {
		printfood();
		GotoXY(50, 5);
		printf("当前得分:%d", snake.length - 3);
	}
	/*判断是否死亡，死亡则清除屏幕打印分数*/
	if (!check()) {
		system("cls");
		GotoXY(45, 14);
		printf("Game Over");
		GotoXY(45, 16);
		printf("最终得分:%d", snake.length - 3);
		GotoXY(45, 18);
		printf("按任意键返回主菜单");
		char ch = _getch();
		system("cls");
		return 0;
	}
	//调整速度
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