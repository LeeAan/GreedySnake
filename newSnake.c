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
    		system("cls");
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
    getch();                //按任意键返回主界面
    system("cls");
    printsnake();
    welcometogame();
}
