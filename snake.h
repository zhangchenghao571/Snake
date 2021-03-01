#pragma once
#include<vector>
#include "unit.h"
#include "food.h"
enum Dir
{
	KUP, KDOWN, KLEFT, KRIGHT
};

class snake
{
public:
	int m_HeadX;
	int m_HeadY;
	int m_Len;
	int m_Speed;
	Dir m_dir;
	vector<unit> m_Body;

public:
	snake(int x = 40, int y = 10, int len = 5, int speed = 400, Dir dir = KRIGHT, char pic = 'o');
	~snake();
	void showSnake();
	void eraseSnake();
	void move();
	bool eatfood(food* pfood);
	void growup();
	void changeDir(int vk);

};


