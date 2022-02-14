#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct snake
{
	int x;
	int y;
	struct snake *next;
}snake;
snake *head;	//ͷָ��
snake *food;				//ʳ��ָ��
/*
	���ù��λ��
*/
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*
	������ɫ����
*/
int color(int c)
{
	//SetConsoleTextAttribute��API���ÿ���̨����������ɫ�ͱ���ɫ�ĺ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //����������ɫ
	return 0;
}
/*
	�ַ�ƴ��Ӣ��ͼ��
*/
void printsnake()
{
	color(2);
	printf("                                                                                         \n");
	printf("                       __________       ___                                              \n");
	printf("                      /          \\     / \\ \\    |____      __\\__                     \n");
	printf("                     /  ________  \\   / ___ \\  _/ __     | |   /                       \n");
	printf("                     |  |      |__|     _/_   |_|  /    [|] |/                           \n");
	printf("                     |  |              | | |      /     _|_ \\__/                        \n");
	printf("                     \\  \\_______        / \\      |___/        ____                    \n");
	printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
	printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
	printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
	printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
	printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
	printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
	printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n");	
}
/*
	��ʼ����
*/
void welcometogame()
{
	int n;
	int i,j = 1;
	gotoxy(43,18);
	color(11);
	printf("̰ �� �� �� Ϸ");
	color(14);          			//��ɫ�߿�
	for (i = 20; i <= 26; i++)   	//������±߿�
	{
		for (j = 27; j <= 74; j++)  //������ұ߿�
		{
			gotoxy(j, i);
			if (i == 20 || i == 26)
			{
				printf("-");
            }
			else if (j == 27 || j == 74)
            {
				printf("|");
            }
		}
	}
	color(10);
	gotoxy(35, 22);
	printf("1.��ʼ��Ϸ");
	gotoxy(55, 22);
	printf("2.��Ϸ˵��");
	gotoxy(35, 24);
	printf("3.�˳���Ϸ");
	gotoxy(29,27);
	color(3);
	printf("��ѡ��[1 2 3]:[ ]\b\b");        //\bΪ�˸�ʹ�ù�괦��[]�м䣬д����\b��ԭ���ǹ�����˵���]�������˵���[]���м�
	color(14);
    scanf("%d", &n);    		//����ѡ��
    switch (n)
    {
    	case 1:					//ѡ��ʼ��Ϸ
    		system("cls");		//����
			createMap();        //������ͼ
			initsnake();        //��ʼ������
			createfood();		//��ʼ��ʳ��
			keyboardControl();	//���Ƽ��̰�ť
        	break;
    	case 2:					//ѡ����Ϸ˵��
        	explation();
        	break;
    	case 3:					//ѡ���˳���Ϸ
        	exit(0);     		//�˳���Ϸ
        	break;
		default:				//�����1~3֮���ѡ��
			color(12);
			gotoxy(40,28);
			printf("������1~3֮�����!");
			getch();			//���������
			system("cls");		//����
			printsnake();
			welcometogame();
    }
}
/*
	��Ϸ˵��
*/
void explation()
{
	int i,j = 1;
    system("cls");
    color(15);
    gotoxy(44,3);
    printf("��Ϸ˵��");
    color(2);
    for (i = 6; i <= 22; i++)   //������±߿�===
	{
		for (j = 20; j <= 76; j++)  //������ұ߿�||
		{
			gotoxy(j, i);
			if (i == 6 || i == 22) printf("=");
			else if (j == 20 || j == 75) printf("||");
		}
	}
    color(3);
    gotoxy(30,8);
    printf("tip1: ����ײǽ������ҧ���Լ�");
    color(10);
    gotoxy(30,11);
    printf("tip2: �á�.��.��.���ֱ�����ߵ��ƶ�");
    color(14);
    gotoxy(30,14);
    printf("tip3: F1 Ϊ���٣�F2 Ϊ����");
    color(11);
    gotoxy(30,17);
    printf("tip4: ���ո����ͣ��Ϸ���ٰ��ո������");
    color(4);
    gotoxy(30,20);
    printf("tip5: Esc ���˳���Ϸ");
    getch();                //����������������棬������getchar����system("pause")����
    system("cls");
    printsnake();
    welcometogame();
}
/*
	������ͼ
*/
void createMap()
{
    int i,j;
    for(i=0;i<58;i+=2)		//��ӡ���±߿�
    {
        gotoxy(i,0);
		color(6);			//����ɫ�ı߿�
        printf("��");
        gotoxy(i,26);
        printf("��");
    }
    for(i=1;i<26;i++)		//��ӡ���ұ߿�
    {
        gotoxy(0,i);
        printf("��");                        
        gotoxy(56,i);
        printf("��");        
    }
	for(i = 2;i<56;i+=2)	//��ӡ�м�����
	{
		for(j = 1;j<26;j++)
		{
			gotoxy(i,j);
			color(3);
			printf("��\n\n");
		}
	}
}
/*
	��ʼ������������
*/
void initsnake()
{
    snake *tail;
    int i;
    tail=(snake*)malloc(sizeof(snake));	//����β��ʼ��ͷ�巨����x,y�趨��ʼ��λ��
    tail->x=24;				//�ߵĳ�ʼλ�ã�24,5��
    tail->y=5;
    tail->next=NULL;
    for(i=1;i<=4;i++)       //������������Ϊ5
    {
        head=(snake*)malloc(sizeof(snake)); //��ʼ����ͷ
        head->next=tail;    //��ͷ����һλΪ��β
        head->x=24+2*i;     //������ͷλ��
        head->y=5;
        tail=head;          //��ͷ�����β��Ȼ���ظ�ѭ��
    }
    while(tail!=NULL)		//��ͷ��β���������
    {
        gotoxy(tail->x,tail->y);
		color(14);
        printf("��");       //�����������ʹ�á����
        tail=tail->next;    //��ͷ�����ϣ������ͷ����һλ��һֱ�������β
    }
}
/*
	�������ʳ��
*/
void createfood()
{
    snake *food_1;
    srand((unsigned)time(NULL));        	//����
    food_1=(snake*)malloc(sizeof(snake));   //��ʼ��food_1
    while((food_1->x%2)!=0)    				//��֤��Ϊż����ʹ��ʳ��������ͷ���룬Ȼ��ʳ����������������
    {
        food_1->x=rand()%52+2;              //ʳ��������֣�ʳ���x������2~53
    }
    food_1->y=rand()%24+1;					//ʳ���y������1~24
    q=head;
    while(q->next==NULL)
    {
        if(q->x==food_1->x && q->y==food_1->y) //�ж������Ƿ���ʳ���غ�
        {
            free(food_1);               //��������ʳ���غϣ���ô�ͷ�ʳ��ָ��
            createfood();               //���´���ʳ��
        }
        q=q->next;
    }
    gotoxy(food_1->x,food_1->y);
    food=food_1;
	color(12);
    printf("��");           //���ʳ��
}
void scoreandtips()
{
	File_out();				//����File_out()����ȡ�ļ�save.txt�е�����
	gotoxy(64,4);			//ȷ����ӡ�����λ��
	color(11);				//������ɫ
	printf("����߼�¼�%d",HighScore);	//��ӡ��߷�
	gotoxy(64,8);
	color(14);
	printf("��ǰ�÷֣�%d  ",score);
	color(15);
	gotoxy(73,11);
	printf("С �� ʾ");
	gotoxy(60,13);
	color(6);
	printf("�p ������������������������������ �p");
	gotoxy(60,25);
	printf("�p ������������������������������ �p");
	color(3);
	gotoxy(64,14);
	printf("ÿ��ʳ��÷֣�%d��",add);
	gotoxy(64,16);
	printf("����ײǽ������ҧ���Լ�");
	gotoxy(64,18);
	printf("�á� �� �� ���ֱ�����ߵ��ƶ�");
	gotoxy(64,20);
	printf("F1�����٣�F2������");
	gotoxy(64,22);
	printf("�ո����ͣ��Ϸ");
	gotoxy(64,24);
    printf("Esc���˳���Ϸ");
}