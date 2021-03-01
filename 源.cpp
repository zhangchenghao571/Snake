#include <iostream>
#include "food.h"
#include "control.h"
#include "snake.h"
#include <conio.h>
#include<stdio.h>
#include<windows.h>//隐藏光标
#include<mmsystem.h>//添加背景音乐
#pragma comment(lib,"WINMM.LIB")//添加背景音乐

int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态*/

	//color后面 0是背景色baidu代号 ,A是前景色(字体)代号，zhi你可以根dao据这些代号自由改变 
	system("color 0A ");
	/* 0 = 黑色
	1 = 蓝色
	2 = 绿色bai       A = 淡绿色
	3 = 湖蓝色     B = 淡浅绿色
	4 = 红色       C = 淡红色
	5 = 紫色       D = 淡紫色
	6 = 黄色       E = 淡黄色
	7 = 白色       F = 亮白色
	8 = 灰色
	9 = 淡蓝色
  */
	PlaySound(TEXT("D:\\57184\\tcss\\1.wav"), NULL, SND_ASYNC | SND_LOOP | SND_NODEFAULT);//添加背景音乐//SDN_LOOP参数循环播放
	control MyControl;
	MyControl.run();
	//snake mySnake;
	/*while (true)
	{
		mySnake.move();

		
	
		

	}*/
	getchar();
	//system("pause");
}