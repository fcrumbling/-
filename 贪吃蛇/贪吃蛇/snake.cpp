//snake.cpp

#include "snake.h"

//@表示蛇头，o表示蛇身,$表示食物

/*定义全局变量*/
Snake snake;
Food foods[FOOD_COUNT];
char pre_Dir = right;//当前蛇头方向
char toDir = right;//预期蛇头方向
int ranks[100];//记录历次分数，偷个懒，搞个100的数组。
int rankindex = 0;
int blocknumber = 5;//障碍物个数 单个障碍物的处理更简单一点，但是函数会不通用，所以直接从复数个开始。
Block blocks[5], block;//记录障碍物
int backdoor = 1;//作弊未启动


char foodTypes[] = { '$', '*', '%' };// 食物种类数组

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
	printf("4.排行榜");
	GotoXY(43, 22);
	printf("输入其他键以退出游戏");
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
	HANDLE hout;//控制台输出的句柄
	COORD cor;//希望移动到的光标位置
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);//设置控制台光标位置
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
	printf("贪吃蛇——控制台游戏");
	GotoXY(34, 14);
	printf("作者：crumbling、yuuki");
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
	snake.snakeNODE[0].x = map_width / 2;
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
	//生成障碍物
	printblock();
	//计分板
	GotoXY(50, 5);
	printf("得分：0");
}

/*生成FOOD_COUNT个食物*/
void printfood() {
	for (int i = 0; i < FOOD_COUNT; i++) {
		int not_permitted = 1;//默认不被允许通过，除非不与蛇身重叠


		while (not_permitted) {
			not_permitted = 0;
			foods[i].x = rand() % (map_width - 2) + 1;
			foods[i].y = rand() % (map_height - 2) + 1;
			foods[i].type = foodTypes[rand() % 3];

			//检查食物是否与蛇身重合
			for (int j = 0; j < snake.length; j++) {
				if (foods[i].x == snake.snakeNODE[j].x && foods[i].y == snake.snakeNODE[j].y) {
					not_permitted = 1;
					break;
				}
			}

			//检查食物是否与其他食物重合
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
	Snakenode temp = snake.snakeNODE[snake.length - 1];//尾节点的记录
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
		case 'q':
			system("cls");
			GotoXY(45, 14);
			printf("Game Over");
			GotoXY(45, 16);
			printf("最终得分:%d", snake.length - 3);
			ranks[rankindex++] = snake.length - 3;
			GotoXY(45, 18);
			printf("按任意键返回主菜单");
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

	static int eatenFoodsCount = 0; // 记录已被吃掉的食物数量

	int eatenIndex = -1;  // 默认值为-1，表示未吃到食物

	// 遍历所有的食物
	for (int i = 0; i < FOOD_COUNT; i++) {
		if (snake.snakeNODE[0].x == foods[i].x && snake.snakeNODE[0].y == foods[i].y) {
			eatenIndex = i;  // 记录被吃掉的食物的索引
			break;
		}
	}

	// 如果吃到了食物
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
		flag = 1; // 1表示吃到食物
		snake.snakeNODE[snake.length - 1] = temp; // 蛇尾加一节

		eatenFoodsCount++;  // 增加被吃掉的食物计数器

		// 如果所有食物都被吃掉
		if (eatenFoodsCount == FOOD_COUNT) {
			// 重新生成所有食物
			for (int i = 0; i < FOOD_COUNT; i++) {
				foods[i].x = rand() % (map_width - 2) + 1;
				foods[i].y = rand() % (map_height - 2) + 1;
				foods[i].type = foodTypes[rand() % 3];
			}
			clear();
			printfood();
			printblock();

			eatenFoodsCount = 0;  // 重置被吃掉的食物计数器
		}
	}

	//往某个方向吃到食物，相当于食物变成蛇头，原蛇头变成蛇身
	//输出此时蛇的状态
	if (!flag) {
		GotoXY(temp.x, temp.y);
		printf(" ");//没吃到则删除蛇尾
	}
	else {
		//printfood();
		GotoXY(50, 5);
		printf("当前得分:%d", snake.length - 3);
	}
	/*判断是否死亡，死亡则清除屏幕打印分数*/
	if (backdoor && (!check() || !blockcheck())) {
		system("cls");
		GotoXY(45, 14);
		printf("Game Over");
		GotoXY(45, 16);
		printf("最终得分:%d", snake.length - 3);
		ranks[rankindex++] = snake.length - 3;
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


//先生成了食物，还要判断是否有食物
void printblock() {
	int i = blocknumber;
	while (i--) {
		block.x = rand() % (map_width - 2) + 1;
		block.y = rand() % (map_height - 2) + 1;

		// 检查障碍物是否与蛇身重合
		for (int j = 0; j < snake.length; j++) {
			if (block.x == snake.snakeNODE[j].x && block.y == snake.snakeNODE[j].y) {
				i++;
				break;
			}
		}

		// 检查障碍物是否与食物重合
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
	printf("排行榜：");
	sort(0, rankindex - 1);
	for (int i = 0; i < rankindex; i++) {
		GotoXY(43, 14 + 2 * i);
		printf("%d.%d", i + 1, ranks[rankindex - i - 1]);
	}
	GotoXY(43, 14 + 2 * rankindex);
	printf("按任意键以返回上级菜单");
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
		printf("作弊已启动,q退出，再次打开此页面以退出作弊.");
		GotoXY(45, 14);
		printf("按任意键以返回上级菜单");
		Hide();
		char number = _getch();
		system("cls");
	}
	else {
		backdoor = 1;
		GotoXY(43, 12);
		printf("作弊已关闭");
		GotoXY(45, 14);
		printf("按任意键以返回上级菜单");
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