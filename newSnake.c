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
    		system("cls");
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
    getch();                //�����������������
    system("cls");
    printsnake();
    welcometogame();
}
