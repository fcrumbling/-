#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int loop = 0;

int menu();// ��ʾ���˵�
int menu2();// ��ʾ��ѯ�˵�
int menu3();// ��ʾͳ�Ʋ˵�
void gotoxy();// ������ƶ�������̨�ϵ�ָ��λ��
void HideCursor();// ���ؿ���̨�еĹ��
void Insert();// ������ڳ�������Ϣ
void Print();//��ʾ���г�����Ϣ
void IdSearch();//�������֤������������Ϣ
void PlateNumber();//���ݳ��ƺ�����������Ϣ
void ExitSystem();//�˳�ϵͳ
void Revise();//�޸ĳ�����Ϣ
void Delete();//ɾ��������Ϣ
void Add();//׷�ӳ�����Ϣ
void Money();//ͳ�Ƴ���������
void MaxCar();//����ӯ����ߵĳ���

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
    HANDLE hout;//����̨����ľ��
    COORD cor;//ϣ���ƶ����Ĺ��λ��
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout, cor);//���ÿ���̨���λ��
}


void HideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int menu(void) {
    system("cls");
    int i, choose;
    gotoxy(40, 6);
    printf("��ӭʹ���������޹���ϵͳ");
    gotoxy(43, 8);
    printf("[1]��Ϣ¼��");
    gotoxy(43, 10);
    printf("[2]��Ϣ��ʾ");
    gotoxy(43, 12);
    printf("[3]��ѯ��Ϣ");
    gotoxy(43, 14);
    printf("[4]�޸���Ϣ");
    gotoxy(43, 16);
    printf("[5]ɾ����Ϣ");
    gotoxy(43, 18);
    printf("[6]׷����Ϣ");
    gotoxy(43, 20);
    printf("[7]ͳ����Ϣ");
    gotoxy(43, 22);
    printf("[8]�˳�");
    gotoxy(43, 24);
    printf("��ѡ��(1-8):");
    scanf("%d", &choose);
    if (choose >= 1 && choose <= 8) return choose;
    while (choose < 1 || choose>8) {
        gotoxy(43, 26);
        printf("�����뷶ΧΪ1-8������");
        Sleep(1000);
        ExitSystem();
    }
    return choose;
}
int menu2(void) {
    system("cls");
    int i, choose;
    gotoxy(40, 6);
    printf("��ӭʹ���������޹���ϵͳ");
    gotoxy(43, 8);
    printf("[1]�������֤�ż���");
    gotoxy(43, 10);
    printf("[2]���ճ��ƺż���");
    gotoxy(43, 12);
    printf("[3]�������˵�");
    gotoxy(43, 14);
    printf("[4]�˳�ϵͳ");
    gotoxy(43, 16);
    printf("��ѡ��(1-4):");
    scanf("%d", &choose);
    if (choose >= 1 && choose <= 4) return choose;
    while (choose < 1 || choose>4) {
        gotoxy(43, 18);
        printf("�����뷶ΧΪ1-4������");
        Sleep(1000);
        ExitSystem();
    }
    return choose;
}
int menu3(void) {
    system("cls");
    int i, choose;
    gotoxy(40, 6);
    printf("��ӭʹ���������޹���ϵͳ");
    gotoxy(43, 8);
    printf("[1]�鿴���¶����ܽ��");
    gotoxy(43, 10);
    printf("[2]�鿴���������ߵĳ��ƺ�");
    gotoxy(43, 12);
    printf("[3]�������˵�");
    gotoxy(43,14);
    printf("[4]�˳�ϵͳ");
    gotoxy(43, 16);
    printf("��ѡ��(1-4):");
    scanf("%d", &choose);
    if (choose >= 1 && choose <= 4) return choose;
    while (choose < 1 || choose>4) {
        printf("�����뷶ΧΪ1-4������");
        gotoxy(40, 23);
        printf("��ѡ��(1-4):");
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
        printf("��������������Ϣ¼�롪����������\n\n");
        fflush(stdin);     //��ջ�����
        printf("�����붩����(1-10000):");
        scanf("%d", &x);
        while (x < 1 || x>10000) {
            printf("�����ŷ�ΧΪ1~10000:");
            scanf("%d", &x);
        }
        one = 0;
        for (j = 0; j < loop; j++) {
            if (x == car[j].theOrderNumber) {
                one = 1;
                printf("\n��¼������!�����ظ����...");
                getch();
                system("cls");
                menu();
            }
        }
        if (one == 0) {
            car[loop].theOrderNumber = x;
        }
        printf("���������֤��:");
        scanf("%s", &car[loop].IdNumber);
        printf("�����복�ƺ�:");
        scanf("%s", &car[loop].PlateNumber);
        printf("���������:");
        scanf("%lf", &cost);
        car[loop].Cost = cost;
        loop++;
        printf("\n������! Ŀǰ����%d����!\n��1�ص�������!��2���������Ϣ!���������˳�����! ", loop);
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
    printf("��������������Ϣ��ʾ������������\n\n");
    if (loop == 0) {
        printf("Error,������,��������ݺ�����\n");
    }
    else {
        gotoxy(3, 5);
        printf("������");
        gotoxy(10, 5);
        printf("���֤��");
        gotoxy(32, 5);
        printf("���ƺ�");
        gotoxy(45, 5);
        printf("����");
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
    printf("\n��ʾ���! Ŀǰ����%d����!\n��1�ص�������!���������˳�����! ", loop);
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
        printf("��������������ѯ(�������֤��)������������\n\n");
        if (loop == 0) {
            gotoxy(3, 5);
            printf("�����ݣ���¼�����ݺ��ѯ������������������˵�");
            getch();
            system("cls");
            main();
        }
        gotoxy(3, 5);
        printf("��������Ҫ��ѯ�����֤��:");
        scanf("%s", &idnumber);
        j = 0;
        for (i = 0; i < loop; i++) {
            if (strcmp(idnumber, car[i].IdNumber) == 0) {
                j = 1;
                gotoxy(3, 7);
                printf("������");
                gotoxy(10, 7);
                printf("���֤��");
                gotoxy(32, 7);
                printf("���ƺ�");
                gotoxy(45, 7);
                printf("����");
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
            printf("�Բ���δ��ѯ������������֤�ţ����ʵ����������");
        }
        gotoxy(3, 11);
        printf("��ѯ��ɣ�����1������ѯ������2�������˵������������˳�����!");
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
        printf("��������������ѯ(���ճ��ƺ�)������������\n\n");
        if (loop == 0) {
            gotoxy(3, 5);
            printf("�����ݣ���¼�����ݺ��ѯ������������������˵�");
            getch();
            system("cls");
            main();
        }
        gotoxy(3, 5);
        printf("��������Ҫ��ѯ�ĳ��ƺ�:");
        scanf("%s", &platenumber);
        j = 0;
        for (i = 0; i < loop; i++) {
            if (strcmp(platenumber, car[i].PlateNumber) == 0) {
                j = 1;
                gotoxy(3, 7);
                printf("������");
                gotoxy(10, 7);
                printf("���֤��");
                gotoxy(32, 7);
                printf("���ƺ�");
                gotoxy(45, 7);
                printf("����");
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
            printf("�Բ���δ��ѯ��������ĳ��ƺţ����ʵ����������");
            break;
        }
        gotoxy(3, 11);
        printf("��ѯ��ɣ�����1������ѯ������2�������˵������������˳�����!");
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
            printf("�����ݣ���¼�����ݺ��ѯ������������������˵�");
            getch();
            system("cls");
            main();
        }
        printf("��������Ҫ�޸ĵ���Ϣ�����֤��:");
        scanf("%s", &idnumber);
        j = 0;
        for (i = 0; i < loop; i++) {
            if (strcmp(idnumber, car[i].IdNumber) == 0) {
                j = 1;
                do {
                    system("cls");
                    gotoxy(0, 6);
                    printf("����Ҫ�޸ĵ���������");
                    gotoxy(0, 7);
                    printf("������");
                    gotoxy(7, 7);
                    printf("���֤��");
                    gotoxy(29, 7);
                    printf("���ƺ�");
                    gotoxy(42, 7);
                    printf("����");
                    gotoxy(0, 9);
                    printf("%d", car[i].theOrderNumber);
                    gotoxy(7, 9);
                    printf("%s", car[i].IdNumber);
                    gotoxy(29, 9);
                    printf("%s", car[i].PlateNumber);
                    gotoxy(42, 9);
                    printf("%f", car[i].Cost);
                    printf("\n\n\n\n");
                    printf("��ѡ����Ҫ�޸ĵ���Ŀ\n");
                    printf("\t[1]���֤��\n");
                    printf("\t[2]���ƺ�\n");
                    printf("\t[3]����\n");
                    scanf("%d", &b);
                    switch (b) {
                    case 1:
                        printf("\n���������֤��:");
                        scanf("%s", &car[i].IdNumber);
                        break;
                    case 2:
                        printf("\n�����복�ƺ�:");
                        scanf("%s", &car[i].PlateNumber);
                        break;
                    case 3:
                        printf("���������:");
                        scanf("%lf", &car[i].Cost);
                        break;
                    }
                    printf("�޸���ɣ�����1�����޸ģ����������������޸�");
                    scanf("%d", &c);
                } while (c == 1);
                break;
            }
            if (j == 0) {
                gotoxy(3, 7);
                printf("δ��ѯ������������֤�ţ����ʵ����������");
                break;
            }
        }
        gotoxy(0, 20);
        printf("����1�����޸�������Ŀ������2�������˵������������˳�����!");
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
    printf("��������������Ϣɾ��������������\n\n");
    printf("\t ��������Ҫɾ������Ŀ�����֤��:");
    scanf("%s", idnumber);
    k = 0;
    for (j = 0; j <= loop; j++) {
        if (strcmp(idnumber, car[j].IdNumber) == 0) {
            k = 1;
            for (x = j; x <= loop; x++) {
                car[x] = car[x + 1];
            }
            loop--;
            printf("\n\t ɾ���ɹ�!");
            break;
        }
    }
    if (k == 0) {
        printf("\t �Բ���,��¼��û�д���Ŀ...");
        printf("����������˳�");
        getch();
        system("cls");
        main();
    }
    printf("����������˳�");
    getch();
    system("cls");
    main();
}
void Add() {
    int i, x, j, one, row;
    double cost;
    loop++;
    system("cls");
    printf("��������������Ϣ׷�ӡ�����������\n\n");
    gotoxy(1, 5);
    if (loop == 1) {
        printf("����¼����Ϣ��ѡ��˹��ܣ���������˳���");
        getch();
        loop--;
        system("cls");
        main();
    }
    printf("�������ڵڼ�����������");
    scanf("%d", &row);
    if (row >= loop) {
        do {
            printf("�������������С�����е���Ŀ�������������룺");
            scanf("%d", &row);
        } while (row >= loop);
    }
    for (i = loop; i >= row; i--) {
        car[i] = car[i - 1];
    }
    printf("�����붩����(1-100):");
    scanf("%d", &x);
    while (x < 1 || x>100) {
        printf("�����ŷ�ΧΪ1~100:");
        scanf("%d", &x);
    }
    one = 0;
    for (j = 0; j < loop; j++) {
        if (x == car[j].theOrderNumber) {
            one = 1;
            printf("\n��¼������!�����ظ����...");
            getch();
            system("cls");
            main();
        }
    }
    if (one == 0) {
        car[row].theOrderNumber = x;
    }
    printf("���������֤��:");
    scanf("%s", &car[i].IdNumber);
    printf("�����복�ƺ�:");
    scanf("%s", &car[row].PlateNumber);
    printf("���������:");
    scanf("%lf", &cost);
    car[row].Cost = cost;
    printf("\n\t׷����ɣ��밴������������˵�");
    getch();
    system("cls");
    main();
}
void Money() {
    int i;
    double sum = 0;
    system("cls");
    printf("��������������Ϣͳ��(���¶����ܽ��)������������\n\n");
    for (i = 0; i <= loop; i++) {
        sum = sum + car[i].Cost;
    }
    gotoxy(1, 5);
    printf("����Ŀǰ���¶����ܽ��Ϊ%lf", sum);
    gotoxy(1, 6);
    printf("��������������˵�");
    getch();
    system("cls");
    main();
}
void MaxCar() {
    int i, j;
    double high = 0;
    system("cls");
    printf("��������������Ϣͳ��(���������ߵĳ��ƺ�)������������\n\n");
    for (i = 0; i < loop; i++) {
        if (car[i].Cost >= high) {
            high = car[i].Cost;
            j = i;
        }
    }
    gotoxy(1, 5);
    printf("��ֹĿǰ���������ߵĳ��ƺ�%s",car[j].PlateNumber);
    gotoxy(1, 6);
    printf("��������������˵�");
    getch();
    system("cls");
    main();
}
void ExitSystem() {
    system("cls");
    printf("\n�˳�ϵͳ��...");
    exit(0);
}