//snake main.cpp
#pragma once

#include "snake.h"

int main()
{
	srand((unsigned int)time(0));//随机数种子生成
	int end = 1, result;
	while (end) {
		result = Menu();//弹出主菜单，并返回用户选择
		switch (result) {
		case 1:
			InitMap();
			while (Snakemove());//返回1继续移动，返回0停止移动
			break;
		case 2:
			Help();
			break;
		case 3:
			About();
			break;
		case 4:
			Rank();
			break;
		case 5:
			Backdoor();
			break;
		case 0:
			end = 0;
			break;
		}
	}
	return 0;
}