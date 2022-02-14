#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct snake
{
	int x;
	int y;
	struct snake *next;
}snake;
snake *head;	//头指针
snake *food;				//食物指针
/*
	设置光标位置
*/
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*
	文字颜色函数
*/
int color(int c)
{
	//SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
	return 0;
}
/*
	字符拼成英文图案
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
	开始界面
*/
void welcometogame()
{
	int n;
	int i,j = 1;
	gotoxy(43,18);
	color(11);
	printf("贪 吃 蛇 游 戏");
	color(14);          			//黄色边框
	for (i = 20; i <= 26; i++)   	//输出上下边框┅
	{
		for (j = 27; j <= 74; j++)  //输出左右边框┇
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
	printf("1.开始游戏");
	gotoxy(55, 22);
	printf("2.游戏说明");
	gotoxy(35, 24);
	printf("3.退出游戏");
	gotoxy(29,27);
	color(3);
	printf("请选择[1 2 3]:[ ]\b\b");        //\b为退格，使得光标处于[]中间，写两个\b的原因是光标先退到“]”，再退到“[]”中间
	color(14);
    scanf("%d", &n);    		//输入选项
    switch (n)
    {
    	case 1:					//选择开始游戏
    		system("cls");		//清屏
			createMap();        //创建地图
			initsnake();        //初始化蛇身
			createfood();		//初始化食物
			keyboardControl();	//控制键盘按钮
        	break;
    	case 2:					//选择游戏说明
        	explation();
        	break;
    	case 3:					//选择退出游戏
        	exit(0);     		//退出游戏
        	break;
		default:				//输入非1~3之间的选项
			color(12);
			gotoxy(40,28);
			printf("请输入1~3之间的数!");
			getch();			//输入任意键
			system("cls");		//清屏
			printsnake();
			welcometogame();
    }
}
/*
	游戏说明
*/
void explation()
{
	int i,j = 1;
    system("cls");
    color(15);
    gotoxy(44,3);
    printf("游戏说明");
    color(2);
    for (i = 6; i <= 22; i++)   //输出上下边框===
	{
		for (j = 20; j <= 76; j++)  //输出左右边框||
		{
			gotoxy(j, i);
			if (i == 6 || i == 22) printf("=");
			else if (j == 20 || j == 75) printf("||");
		}
	}
    color(3);
    gotoxy(30,8);
    printf("tip1: 不能撞墙，不能咬到自己");
    color(10);
    gotoxy(30,11);
    printf("tip2: 用↑.↓.←.→分别控制蛇的移动");
    color(14);
    gotoxy(30,14);
    printf("tip3: F1 为加速，F2 为减速");
    color(11);
    gotoxy(30,17);
    printf("tip4: 按空格键暂停游戏，再按空格键继续");
    color(4);
    gotoxy(30,20);
    printf("tip5: Esc ：退出游戏");
    getch();                //按任意键返回主界面，建议用getchar或者system("pause")代替
    system("cls");
    printsnake();
    welcometogame();
}
/*
	创建地图
*/
void createMap()
{
    int i,j;
    for(i=0;i<58;i+=2)		//打印上下边框
    {
        gotoxy(i,0);
		color(6);			//深绿色的边框
        printf("□");
        gotoxy(i,26);
        printf("□");
    }
    for(i=1;i<26;i++)		//打印左右边框
    {
        gotoxy(0,i);
        printf("□");                        
        gotoxy(56,i);
        printf("□");        
    }
	for(i = 2;i<56;i+=2)	//打印中间网格
	{
		for(j = 1;j<26;j++)
		{
			gotoxy(i,j);
			color(3);
			printf("■\n\n");
		}
	}
}
/*
	初始化蛇身，画蛇身
*/
void initsnake()
{
    snake *tail;
    int i;
    tail=(snake*)malloc(sizeof(snake));	//从蛇尾开始，头插法，以x,y设定开始的位置
    tail->x=24;				//蛇的初始位置（24,5）
    tail->y=5;
    tail->next=NULL;
    for(i=1;i<=4;i++)       //设置蛇身，长度为5
    {
        head=(snake*)malloc(sizeof(snake)); //初始化蛇头
        head->next=tail;    //蛇头的下一位为蛇尾
        head->x=24+2*i;     //设置蛇头位置
        head->y=5;
        tail=head;          //蛇头变成蛇尾，然后重复循环
    }
    while(tail!=NULL)		//从头到尾，输出蛇身
    {
        gotoxy(tail->x,tail->y);
		color(14);
        printf("◆");       //输出蛇身，蛇身使用◆组成
        tail=tail->next;    //蛇头输出完毕，输出蛇头的下一位，一直输出到蛇尾
    }
}
/*
	随机出现食物
*/
void createfood()
{
    snake *food_1;
    srand((unsigned)time(NULL));        	//播种
    food_1=(snake*)malloc(sizeof(snake));   //初始化food_1
    while((food_1->x%2)!=0)    				//保证其为偶数，使得食物能与蛇头对齐，然后食物会出现在网格线上
    {
        food_1->x=rand()%52+2;              //食物随机出现，食物的x坐标在2~53
    }
    food_1->y=rand()%24+1;					//食物的y坐标在1~24
    q=head;
    while(q->next==NULL)
    {
        if(q->x==food_1->x && q->y==food_1->y) //判断蛇身是否与食物重合
        {
            free(food_1);               //如果蛇身和食物重合，那么释放食物指针
            createfood();               //重新创建食物
        }
        q=q->next;
    }
    gotoxy(food_1->x,food_1->y);
    food=food_1;
	color(12);
    printf("●");           //输出食物
}
void scoreandtips()
{
	File_out();				//调用File_out()，读取文件save.txt中的内容
	gotoxy(64,4);			//确定打印输出的位置
	color(11);				//设置颜色
	printf("☆最高记录☆：%d",HighScore);	//打印最高分
	gotoxy(64,8);
	color(14);
	printf("当前得分：%d  ",score);
	color(15);
	gotoxy(73,11);
	printf("小 提 示");
	gotoxy(60,13);
	color(6);
	printf("╬ ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ ╬");
	gotoxy(60,25);
	printf("╬ ┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅ ╬");
	color(3);
	gotoxy(64,14);
	printf("每个食物得分：%d分",add);
	gotoxy(64,16);
	printf("不能撞墙，不能咬到自己");
	gotoxy(64,18);
	printf("用↑ ↓ ← →分别控制蛇的移动");
	gotoxy(64,20);
	printf("F1键加速，F2键减速");
	gotoxy(64,22);
	printf("空格键暂停游戏");
	gotoxy(64,24);
    printf("Esc键退出游戏");
}