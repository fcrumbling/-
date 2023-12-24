#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int loop = 0;

int menu();// 显示主菜单
int menu2();// 显示查询菜单
int menu3();// 显示统计菜单
void gotoxy();// 将光标移动到控制台上的指定位置
void HideCursor();// 隐藏控制台中的光标
void Insert();// 插入关于车辆的信息
void Print();//显示所有车辆信息
void IdSearch();//根据身份证号搜索车辆信息
void PlateNumber();//根据车牌号搜索车辆信息
void ExitSystem();//退出系统
void Revise();//修改车辆信息
void Delete();//删除车辆信息
void Add();//追加车辆信息
void Money();//统计车辆总收入
void MaxCar();//查找盈利最高的车辆

struct information {
    int theOrderNumber;
    char IdNumber[20];
    char PlateNumber[10];
    double Cost;
}car[10000];

int key;
int main() {
    HideCursor();
    key = menu();
    switch (key) {
    case 1:
        system("cls");
        Insert();
        break;
    case 2:
        Print();
        break;
    case 3:
        switch (menu2()) {
        case 1:
            IdSearch();
            break;
        case 2:
            PlateNumber();
            break;
        case 3:
            system("cls");
            main();
            break;
        case 4:
            ExitSystem();
            break;
        }
        break;
    case 4:
        Revise();
        break;
    case 5:
        Delete();
        break;
    case 6:
        Add();
        break;
    case 7:
        switch (menu3()) {
        case 1:
            Money();
            break;
        case 2:
            MaxCar();
            break;
        case 3:
            system("cls");
            main();
            break;
        case 4:
            ExitSystem();
            break;
        }
        break;
    case 8:
        ExitSystem();
        break;
    }
    return 0;
}

void gotoxy(int x, int y) {
    HANDLE hout;//控制台输出的句柄
    COORD cor;//希望移动到的光标位置
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout, cor);//设置控制台光标位置
}


void HideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int menu(void) {
    system("cls");
    int i, choose;
    gotoxy(40, 6);
    printf("欢迎使用汽车租赁管理系统");
    gotoxy(43, 8);
    printf("[1]信息录入");
    gotoxy(43, 10);
    printf("[2]信息显示");
    gotoxy(43, 12);
    printf("[3]查询信息");
    gotoxy(43, 14);
    printf("[4]修改信息");
    gotoxy(43, 16);
    printf("[5]删除信息");
    gotoxy(43, 18);
    printf("[6]追加信息");
    gotoxy(43, 20);
    printf("[7]统计信息");
    gotoxy(43, 22);
    printf("[8]退出");
    gotoxy(43, 24);
    printf("请选择(1-8):");
    scanf("%d", &choose);
    if (choose >= 1 && choose <= 8) return choose;
    while (choose < 1 || choose>8) {
        gotoxy(43, 26);
        printf("请输入范围为1-8的整数");
        Sleep(1000);
        ExitSystem();
    }
    return choose;
}
int menu2(void) {
    system("cls");
    int i, choose;
    gotoxy(40, 6);
    printf("欢迎使用汽车租赁管理系统");
    gotoxy(43, 8);
    printf("[1]按照身份证号检索");
    gotoxy(43, 10);
    printf("[2]按照车牌号检索");
    gotoxy(43, 12);
    printf("[3]返回主菜单");
    gotoxy(43, 14);
    printf("[4]退出系统");
    gotoxy(43, 16);
    printf("请选择(1-4):");
    scanf("%d", &choose);
    if (choose >= 1 && choose <= 4) return choose;
    while (choose < 1 || choose>4) {
        gotoxy(43, 18);
        printf("请输入范围为1-4的整数");
        Sleep(1000);
        ExitSystem();
    }
    return choose;
}
int menu3(void) {
    system("cls");
    int i, choose;
    gotoxy(40, 6);
    printf("欢迎使用汽车租赁管理系统");
    gotoxy(43, 8);
    printf("[1]查看当月订单总金额");
    gotoxy(43, 10);
    printf("[2]查看订单金额最高的车牌号");
    gotoxy(43, 12);
    printf("[3]返回主菜单");
    gotoxy(43,14);
    printf("[4]退出系统");
    gotoxy(43, 16);
    printf("请选择(1-4):");
    scanf("%d", &choose);
    if (choose >= 1 && choose <= 4) return choose;
    while (choose < 1 || choose>4) {
        printf("请输入范围为1-4的整数");
        gotoxy(40, 23);
        printf("请选择(1-4):");
        scanf("%d", &choose);
    }
    return choose;
}
void Insert() {
    system("cls");
    int a, k, j, x, one;
    double cost;
    int i = 0;
    do {
        system("cls");
        printf("——————信息录入——————\n\n");
        fflush(stdin);     //清空缓冲区
        printf("请输入订单号(1-10000):");
        scanf("%d", &x);
        while (x < 1 || x>10000) {
            printf("订单号范围为1~10000:");
            scanf("%d", &x);
        }
        one = 0;
        for (j = 0; j < loop; j++) {
            if (x == car[j].theOrderNumber) {
                one = 1;
                printf("\n记录中已有!不得重复添加...");
                getch();
                system("cls");
                menu();
            }
        }
        if (one == 0) {
            car[loop].theOrderNumber = x;
        }
        printf("请输入身份证号:");
        scanf("%s", &car[loop].IdNumber);
        printf("请输入车牌号:");
        scanf("%s", &car[loop].PlateNumber);
        printf("请输入费用:");
        scanf("%lf", &cost);
        car[loop].Cost = cost;
        loop++;
        printf("\n添加完毕! 目前共有%d辆车!\n按1回到主界面!按2继续添加信息!按其他键退出程序! ", loop);
        scanf("%d", &a);
    } while (a == 2);
    if (a == 1) {
        system("cls");
        main();
    }
    if (a != 1) {
        ExitSystem();
    }
}
void Print() {
    system("cls");
    int a, j;
    printf("——————信息显示——————\n\n");
    if (loop == 0) {
        printf("Error,无数据,请添加数据后再试\n");
    }
    else {
        gotoxy(3, 5);
        printf("订单号");
        gotoxy(10, 5);
        printf("身份证号");
        gotoxy(32, 5);
        printf("车牌号");
        gotoxy(45, 5);
        printf("费用");
        for (j = 0; j < loop; j++) {
            gotoxy(3, 7 + j);
            printf("%d", car[j].theOrderNumber);
            gotoxy(10, 7 + j);
            printf("%s", car[j].IdNumber);
            gotoxy(32, 7 + j);
            printf("%s", car[j].PlateNumber);
            gotoxy(45, 7 + j);
            printf("%f", car[j].Cost);
        }
    }
    printf("\n显示完毕! 目前共有%d辆车!\n按1回到主界面!按其他键退出程序! ", loop);
    scanf("%d", &a);
    if (a == 1) {
        system("cls");
        main();
    }
    if (a != 1) {
        ExitSystem();
    }
}
void IdSearch() {
    char idnumber[20];
    int i, j, a;
    do {
        system("cls");
        printf("——————查询(按照身份证号)——————\n\n");
        if (loop == 0) {
            gotoxy(3, 5);
            printf("无数据，请录入数据后查询，输入任意键返回主菜单");
            getch();
            system("cls");
            main();
        }
        gotoxy(3, 5);
        printf("请输入需要查询的身份证号:");
        scanf("%s", &idnumber);
        j = 0;
        for (i = 0; i < loop; i++) {
            if (strcmp(idnumber, car[i].IdNumber) == 0) {
                j = 1;
                gotoxy(3, 7);
                printf("订单号");
                gotoxy(10, 7);
                printf("身份证号");
                gotoxy(32, 7);
                printf("车牌号");
                gotoxy(45, 7);
                printf("费用");
                gotoxy(3, 9);
                printf("%d", car[i].theOrderNumber);
                gotoxy(10, 9);
                printf("%s", car[i].IdNumber);
                gotoxy(32, 9);
                printf("%s", car[i].PlateNumber);
                gotoxy(45, 9);
                printf("%f", car[i].Cost);
                break;
            }
        }
        if (j == 0) {
            gotoxy(3, 7);
            printf("对不起，未查询到您输入的身份证号，请核实后重新输入");
        }
        gotoxy(3, 11);
        printf("查询完成，输入1继续查询，输入2返回主菜单，按其他键退出程序!");
        scanf("%d", &a);
    } while (a == 1);
    if (a == 2) {
        system("cls");
        main();
    }
    if (a != 1) {
        ExitSystem();
    }
}
void PlateNumber() {
    char platenumber[10];
    int i, j, a;
    do {
        system("cls");
        printf("——————查询(按照车牌号)——————\n\n");
        if (loop == 0) {
            gotoxy(3, 5);
            printf("无数据，请录入数据后查询，输入任意键返回主菜单");
            getch();
            system("cls");
            main();
        }
        gotoxy(3, 5);
        printf("请输入需要查询的车牌号:");
        scanf("%s", &platenumber);
        j = 0;
        for (i = 0; i < loop; i++) {
            if (strcmp(platenumber, car[i].PlateNumber) == 0) {
                j = 1;
                gotoxy(3, 7);
                printf("订单号");
                gotoxy(10, 7);
                printf("身份证号");
                gotoxy(32, 7);
                printf("车牌号");
                gotoxy(45, 7);
                printf("费用");
                gotoxy(3, 9);
                printf("%d", car[i].theOrderNumber);
                gotoxy(10, 9);
                printf("%s", car[i].IdNumber);
                gotoxy(32, 9);
                printf("%s", car[i].PlateNumber);
                gotoxy(45, 9);
                printf("%f", car[i].Cost);
                break;
            }
        }
        if (j == 0) {
            gotoxy(3, 7);
            printf("对不起，未查询到您输入的车牌号，请核实后重新输入");
            break;
        }
        gotoxy(3, 11);
        printf("查询完成，输入1继续查询，输入2返回主菜单，按其他键退出程序!");
        scanf("%d", &a);
    } while (a == 1);
    if (a == 2) {
        system("cls");
        main();
    }
    if (a != 1) {
        ExitSystem();
    }
}
void Revise() {
    char idnumber[20];
    int i, j, a, b, c, cost;
    do {
        system("cls");;
        if (loop == 0) {
            gotoxy(3, 5);
            printf("无数据，请录入数据后查询，输入任意键返回主菜单");
            getch();
            system("cls");
            main();
        }
        printf("请输入需要修改的信息的身份证号:");
        scanf("%s", &idnumber);
        j = 0;
        for (i = 0; i < loop; i++) {
            if (strcmp(idnumber, car[i].IdNumber) == 0) {
                j = 1;
                do {
                    system("cls");
                    gotoxy(0, 6);
                    printf("您想要修改的内容如下");
                    gotoxy(0, 7);
                    printf("订单号");
                    gotoxy(7, 7);
                    printf("身份证号");
                    gotoxy(29, 7);
                    printf("车牌号");
                    gotoxy(42, 7);
                    printf("费用");
                    gotoxy(0, 9);
                    printf("%d", car[i].theOrderNumber);
                    gotoxy(7, 9);
                    printf("%s", car[i].IdNumber);
                    gotoxy(29, 9);
                    printf("%s", car[i].PlateNumber);
                    gotoxy(42, 9);
                    printf("%f", car[i].Cost);
                    printf("\n\n\n\n");
                    printf("请选择需要修改的项目\n");
                    printf("\t[1]身份证号\n");
                    printf("\t[2]车牌号\n");
                    printf("\t[3]费用\n");
                    scanf("%d", &b);
                    switch (b) {
                    case 1:
                        printf("\n请输入身份证号:");
                        scanf("%s", &car[i].IdNumber);
                        break;
                    case 2:
                        printf("\n请输入车牌号:");
                        scanf("%s", &car[i].PlateNumber);
                        break;
                    case 3:
                        printf("请输入费用:");
                        scanf("%lf", &car[i].Cost);
                        break;
                    }
                    printf("修改完成，输入1继续修改，输入其他键结束修改");
                    scanf("%d", &c);
                } while (c == 1);
                break;
            }
            if (j == 0) {
                gotoxy(3, 7);
                printf("未查询到您输入的身份证号，请核实后重新输入");
                break;
            }
        }
        gotoxy(0, 20);
        printf("输入1继续修改其他条目，输入2返回主菜单，按其他键退出程序!");
        scanf("%d", &a);
    } while (a == 1);
    if (a == 2) {
        system("cls");
        main();
    }
    if (a != 1) {
        ExitSystem();
    }
}
void Delete() {
    int j, x, k;
    char idnumber[20];
    system("cls");
    printf("——————信息删除——————\n\n");
    printf("\t 请输入需要删除的条目的身份证号:");
    scanf("%s", idnumber);
    k = 0;
    for (j = 0; j <= loop; j++) {
        if (strcmp(idnumber, car[j].IdNumber) == 0) {
            k = 1;
            for (x = j; x <= loop; x++) {
                car[x] = car[x + 1];
            }
            loop--;
            printf("\n\t 删除成功!");
            break;
        }
    }
    if (k == 0) {
        printf("\t 对不起,记录中没有此条目...");
        printf("输入任意键退出");
        getch();
        system("cls");
        main();
    }
    printf("输入任意键退出");
    getch();
    system("cls");
    main();
}
void Add() {
    int i, x, j, one, row;
    double cost;
    loop++;
    system("cls");
    printf("——————信息追加——————\n\n");
    gotoxy(1, 5);
    if (loop == 1) {
        printf("请在录入信息后选择此功能，按任意键退出！");
        getch();
        loop--;
        system("cls");
        main();
    }
    printf("请输入在第几行增添数据");
    scanf("%d", &row);
    if (row >= loop) {
        do {
            printf("输入的行数必须小于已有的条目数！请重新输入：");
            scanf("%d", &row);
        } while (row >= loop);
    }
    for (i = loop; i >= row; i--) {
        car[i] = car[i - 1];
    }
    printf("请输入订单号(1-100):");
    scanf("%d", &x);
    while (x < 1 || x>100) {
        printf("订单号范围为1~100:");
        scanf("%d", &x);
    }
    one = 0;
    for (j = 0; j < loop; j++) {
        if (x == car[j].theOrderNumber) {
            one = 1;
            printf("\n记录中已有!不得重复添加...");
            getch();
            system("cls");
            main();
        }
    }
    if (one == 0) {
        car[row].theOrderNumber = x;
    }
    printf("请输入身份证号:");
    scanf("%s", &car[i].IdNumber);
    printf("请输入车牌号:");
    scanf("%s", &car[row].PlateNumber);
    printf("请输入费用:");
    scanf("%lf", &cost);
    car[row].Cost = cost;
    printf("\n\t追加完成，请按任意键返回主菜单");
    getch();
    system("cls");
    main();
}
void Money() {
    int i;
    double sum = 0;
    system("cls");
    printf("——————信息统计(当月订单总金额)——————\n\n");
    for (i = 0; i <= loop; i++) {
        sum = sum + car[i].Cost;
    }
    gotoxy(1, 5);
    printf("截至目前当月订单总金额为%lf", sum);
    gotoxy(1, 6);
    printf("按任意键返回主菜单");
    getch();
    system("cls");
    main();
}
void MaxCar() {
    int i, j;
    double high = 0;
    system("cls");
    printf("——————信息统计(订单金额最高的车牌号)——————\n\n");
    for (i = 0; i < loop; i++) {
        if (car[i].Cost >= high) {
            high = car[i].Cost;
            j = i;
        }
    }
    gotoxy(1, 5);
    printf("截止目前订单金额最高的车牌号%s",car[j].PlateNumber);
    gotoxy(1, 6);
    printf("按任意键返回主菜单");
    getch();
    system("cls");
    main();
}
void ExitSystem() {
    system("cls");
    printf("\n退出系统中...");
    exit(0);
}