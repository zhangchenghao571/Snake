#pragma once
#include <Windows.h>
#include"food.h"
#include"snake.h"
#include"conio.h"//kbhit
class control
{
public:
	food* pfood;//ʳ��
	snake* psnake;//��
	int iScore;//����
	int iLevel;//�ȼ�
public:
	control();
	~control();
	void run();
	void drawGameArea();
	void drawGameInfo();
	bool checkFailed();//ʧ�ܼ��
	bool checkLevel();//�ȼ����
};


