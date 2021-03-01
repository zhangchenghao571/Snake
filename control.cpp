#include "control.h"
#include "unit.h"
#include"food.h"
#include<iostream>
#include<Windows.h>
#include <stdlib.h>
using namespace std;

control::control()
{

	this->pfood = new food();//食物
	this->psnake = new snake();//蛇
	this->iScore = 0;
	this->iLevel = 1;
	drawGameArea();//绘制游戏UI
	drawGameInfo();//绘制游戏信息
}

control::~control()
{
	delete psnake;
	delete pfood;
	psnake = NULL;
	pfood = NULL;
}
void control::run()
{
	pfood->CreatPos();
	pfood->show();
	psnake->showSnake();
	int key = 0;
	while (1)
	{
		psnake->move();//蛇移动
		if (_kbhit())//判断是否有输入
		{
			key = _getch();//输入键
			if (key == 32)//空格键
				while (1)
				{
					Sleep(1000);//暂停
					if (_kbhit())
					{
						key = _getch();
						if (key == 32)//再次输入空格键
							break;
					}
				}
			psnake->changeDir(key);//改变方向
		}
		if (psnake->eatfood(pfood)==1)//吃到食物
		{
			iScore = iScore + 10;//吃一个食物加10分
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			if (checkLevel())//检查是否过关
			{
				int k;
				k = MessageBox(NULL, TEXT("play again?"),TEXT ("you win"), MB_YESNO);//弹出对话框
				if (k == 7)//选择否，结束程序
				{
					system("cls");//清屏
                    break;//退出程序
				}
				else if (k == 6)//选择是，重启程序
				{
					system("cls");//清屏
					control mycontrol;
					mycontrol.run();
				}
			}
			pfood->CreatPos();//更改食物位置
			pfood->show();//再次出现食物
		}
		if (checkFailed())//检测是否失败
		{
			int m;
			m = MessageBox(NULL, TEXT("play again?"), TEXT("you  lose"), MB_YESNO);//弹出对话框
			if (m == 7)//选择否，结束程序
			{
				system("cls");//清屏
				break;
			}
			else if (m == 6)//选择是，重启程序
			{
				system("cls");//清屏
				control MyControl;
				MyControl.run();
			}
		}
	}
}
bool control::checkFailed()//失败检测
	{
		for (int i = 1; i < psnake->m_Len; i++)
		{
			//蛇头碰到蛇身——自残死
			if ((psnake->m_HeadX == psnake->m_Body[i].m_x) && (psnake->m_HeadY == psnake->m_Body[i].m_y))
				return true;
		}
		if ((psnake->m_Body[0].m_x <= unit::KLEFT) || (psnake->m_Body[0].m_x >= (unit::KLEFT + unit::KWIDTH - 1)))
		{
			//碰壁死（左右）
			return true;
		}
		if ((psnake->m_HeadY <= unit::KUP + 2) || (psnake->m_HeadY >= (unit::KUP + unit::KHEIGHT -1)))
		{
			//碰壁死（上下）
			return true;
		}
		return false;
    }
bool control::checkLevel()//等级检测
{
	switch (iLevel)
	{
	case 1:  //1级时，达到20分可升级
		if (iScore % 20 == 0 && iScore != 0 && iScore <= 20)
		{
			iScore = 0;//分数归0
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			iLevel++;//等级加1
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			psnake->m_Speed = psnake->m_Speed - 100;//提速
		}
		return false;
	case 2: //2级时，达到30分可升级
		if (iScore % 30 == 0 && iScore != 0 &&  iScore <= 30)
		{
			iScore = 0;//分数归0
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			iLevel++;//等级加1
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			psnake->m_Speed = psnake->m_Speed - 100;//提速
		}
		return false;
	case 3: //3级时，达到40分可通关
		if (iScore % 40 == 0 && iScore != 0 && iScore <= 40)
		{
			iScore = 0;//分数归0
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			iLevel++;//等级加1
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			psnake->m_Speed = psnake->m_Speed - 100;//提速
		}
		return false;
	case 4: //4级时，达到50分可通关
		if (iScore % 50 == 0 && iScore != 0 && iScore <= 50)
		{
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			return true;//通关
		}
	default:
		break;
	}
		
}

void control::drawGameArea()//绘制游戏框图 
{
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int j = 0; j < unit::KWIDTH; j++)//绘制上边框
		cout << "-";
	for (int i = 0; i < unit::KHEIGHT; i++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP  + i);//绘制左边框
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH , unit::KUP  + i);//绘制右边框
		cout << "|";
	}
	unit::gotoxy(unit::KLEFT,unit::KHEIGHT );//绘制下边框
	for (int k = 0; k < unit::KWIDTH; k++)
		cout << "-";
	unit::gotoxy(unit::KLEFT , unit::KUP + 2);//绘制标题下边框
	for (int i = 0; i < unit::KWIDTH ; i++)
		cout << "-";
}
void control::drawGameInfo()//绘制游戏信息
{
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);
	cout << "游戏名称：贪吃蛇";
	unit::gotoxy(unit::KLEFT + 21, unit::KUP + 1);
	cout << "编写者：张丞豪";
	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);
	cout << "当前得分";
	unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
	cout << iScore;
	unit::gotoxy(unit::KLEFT + 57, unit::KUP + 1);
	cout << "当前关卡";
	unit::gotoxy(unit::KLEFT +68 , unit::KUP + 1);
	cout << iLevel;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH +1, unit::KUP + 5);
	cout << "游戏规则： 通过wasd键控制贪吃蛇移动空格键暂停" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 6);
	cout << "共四关：第一关20分通过" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 7);
	cout << "        第二关30分通过" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 8);
	cout << "        第三关40分通过" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 9);
	cout << "        第四关50分通过" << endl;
}