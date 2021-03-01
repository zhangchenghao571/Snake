#pragma once
#include <Windows.h>
#include"food.h"
#include"snake.h"
#include"conio.h"//kbhit
class control
{
public:
	food* pfood;//食物
	snake* psnake;//蛇
	int iScore;//分数
	int iLevel;//等级
public:
	control();
	~control();
	void run();
	void drawGameArea();
	void drawGameInfo();
	bool checkFailed();//失败检测
	bool checkLevel();//等级检测
};


