#include <iostream>
#include "food.h"
#include "control.h"
#include "snake.h"
#include <conio.h>
#include<stdio.h>
#include<windows.h>//���ع��
#include<mmsystem.h>//��ӱ�������
#pragma comment(lib,"WINMM.LIB")//��ӱ�������

int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬*/

	//color���� 0�Ǳ���ɫbaidu���� ,A��ǰ��ɫ(����)���ţ�zhi����Ը�dao����Щ�������ɸı� 
	system("color 0A ");
	/* 0 = ��ɫ
	1 = ��ɫ
	2 = ��ɫbai       A = ����ɫ
	3 = ����ɫ     B = ��ǳ��ɫ
	4 = ��ɫ       C = ����ɫ
	5 = ��ɫ       D = ����ɫ
	6 = ��ɫ       E = ����ɫ
	7 = ��ɫ       F = ����ɫ
	8 = ��ɫ
	9 = ����ɫ
  */
	PlaySound(TEXT("D:\\57184\\tcss\\1.wav"), NULL, SND_ASYNC | SND_LOOP | SND_NODEFAULT);//��ӱ�������//SDN_LOOP����ѭ������
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