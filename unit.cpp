#include "unit.h"
#include<iostream>
using namespace std;
const int unit::KWIDTH = 70;
const int unit::KHEIGHT = 20;
const int unit::KUP = 1;
const int unit::KLEFT = 2;

unit::unit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
	
}


unit::~unit()
{

}

void unit::gotoxy(int x, int y)
{
	
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);

}

void unit::show()
{
	gotoxy(m_x, m_y);
	cout << m_pic;
}

void unit::erase()
{
	gotoxy(m_x, m_y);
	cout << " ";
}
