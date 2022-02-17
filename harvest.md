##### 1. gotoxy函数
通过gotoxy函数可以设置光标到文本屏幕的指定位置，如果在 Turbo C 或 Borland C 中使用 gotoxy 函数，就需要在文件头部添加包含头文件 conio.h代码。
而在 Visual C++ 或 GCC 中使用 gotoxy 函数，就需要把上面自定义的 gotoxy 函数写在自己的程序中。同时注意Windows.h头文件。
***修改文字颜色的函数同理。***
##### 2. \b
`printf("请选择[1 2 3]:[ ]\b\b");        //\b为退格，使得光标处于[]中间`
使用2个`\b`:使用1个光标停在“]”出，使用两个才能停在“[]”里面。
##### 3. system函数
需加头文件<stdlib.h>后方可调用。
**功 能：** 发出一个DOS命令
又如：system("pause")可以实现冻结屏幕，便于观察程序的执行结果；system("CLS")可以实现清屏操作。而调用color函数可以改变控制台的前景色和背景，
##### 4.  getch
用getch();会等待你按下任意键，再继续执行下面的语句；
所在头文件是conio.h。
getch();并非标准C中的函数，不存在C语言中。所以在使用的时候要注意程序的可移植性。国内C语言新手常常使用getch();来暂停程序且不知道此函数来源，建议使用getchar()或者使用头文件中的system("PAUSE")调用系统命令暂停;（如果情况允许）代替此功能或更换一款编译器。
##### 5. exit
C 库函数 void exit(int status) 立即终止调用进程。任何属于该进程的打开的文件描述符都会被关闭
所在头文件：stdlib.h(如果是”VC6.0“的话头文件为：windows.h)
exit(0)表示正常退出，
exit(x)（x不为0）都表示异常退出，这个x是返回给操作系统（包括UNIX,Linux,和MS DOS）的，以供其他程序使用。
**exit()和return的区别：**
即使在除main()之外的函数中调用exit()，它也将终止程序。
而return视级别而定。
##### 6. rand随机数
需要通过播种
```c
srand((unsigned)time(NULL));
```
这样每次才能产生不同的随机数。
在一个程序中，通过执行该语句后，接下来每次调用rand()都会产生不同的随机数，因为每次系统提供的种子都不同，由当前时间决定。
限定随机数的范围：
**通过%实现**
比如，产生0-9的随机数：
```c
int a = rand() % 10;    //产生0~9的随机数，注意10会被整除
```
[参考链接](http://c.biancheng.net/view/2043.html)
##### 7. GetAsyncKeyState函数
返回值类型为short，占2个字节，
**功能：** 
GetAsyncKeyState的返回值表示两个内容，一个是最高位bit的值，代表这个键是否被按下，一个是最低位bit的值，代表在上次调用
GetAsyncKeyState后，这个键是否被按下。
所以让键盘的"上下左右"出发事件可以这样写：
```
if( ::GetAsyncKeyState(VK_LEFT) & 0x8000 )
code...
if( ::GetAsyncKeyState(VK_RIGHT)& 0x8000 )
code...
if( ::GetAsyncKeyState(VK_UP) & 0x8000 )
code...
if( ::GetAsyncKeyState(VK_DOWN) & 0x8000 )
code...
```
“与”十六进制的0x8000，二进制为1000 0000 0000 0000 刚好2个字节，只看最高位的状态，即看“上下左右”键是否被按下。