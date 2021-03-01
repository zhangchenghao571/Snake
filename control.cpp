#include "control.h"
#include "unit.h"
#include"food.h"
#include<iostream>
#include<Windows.h>
#include <stdlib.h>
using namespace std;

control::control()
{

	this->pfood = new food();//ʳ��
	this->psnake = new snake();//��
	this->iScore = 0;
	this->iLevel = 1;
	drawGameArea();//������ϷUI
	drawGameInfo();//������Ϸ��Ϣ
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
		psnake->move();//���ƶ�
		if (_kbhit())//�ж��Ƿ�������
		{
			key = _getch();//�����
			if (key == 32)//�ո��
				while (1)
				{
					Sleep(1000);//��ͣ
					if (_kbhit())
					{
						key = _getch();
						if (key == 32)//�ٴ�����ո��
							break;
					}
				}
			psnake->changeDir(key);//�ı䷽��
		}
		if (psnake->eatfood(pfood)==1)//�Ե�ʳ��
		{
			iScore = iScore + 10;//��һ��ʳ���10��
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			if (checkLevel())//����Ƿ����
			{
				int k;
				k = MessageBox(NULL, TEXT("play again?"),TEXT ("you win"), MB_YESNO);//�����Ի���
				if (k == 7)//ѡ��񣬽�������
				{
					system("cls");//����
                    break;//�˳�����
				}
				else if (k == 6)//ѡ���ǣ���������
				{
					system("cls");//����
					control mycontrol;
					mycontrol.run();
				}
			}
			pfood->CreatPos();//����ʳ��λ��
			pfood->show();//�ٴγ���ʳ��
		}
		if (checkFailed())//����Ƿ�ʧ��
		{
			int m;
			m = MessageBox(NULL, TEXT("play again?"), TEXT("you  lose"), MB_YESNO);//�����Ի���
			if (m == 7)//ѡ��񣬽�������
			{
				system("cls");//����
				break;
			}
			else if (m == 6)//ѡ���ǣ���������
			{
				system("cls");//����
				control MyControl;
				MyControl.run();
			}
		}
	}
}
bool control::checkFailed()//ʧ�ܼ��
	{
		for (int i = 1; i < psnake->m_Len; i++)
		{
			//��ͷ�����������Բ���
			if ((psnake->m_HeadX == psnake->m_Body[i].m_x) && (psnake->m_HeadY == psnake->m_Body[i].m_y))
				return true;
		}
		if ((psnake->m_Body[0].m_x <= unit::KLEFT) || (psnake->m_Body[0].m_x >= (unit::KLEFT + unit::KWIDTH - 1)))
		{
			//�����������ң�
			return true;
		}
		if ((psnake->m_HeadY <= unit::KUP + 2) || (psnake->m_HeadY >= (unit::KUP + unit::KHEIGHT -1)))
		{
			//�����������£�
			return true;
		}
		return false;
    }
bool control::checkLevel()//�ȼ����
{
	switch (iLevel)
	{
	case 1:  //1��ʱ���ﵽ20�ֿ�����
		if (iScore % 20 == 0 && iScore != 0 && iScore <= 20)
		{
			iScore = 0;//������0
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			iLevel++;//�ȼ���1
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			psnake->m_Speed = psnake->m_Speed - 100;//����
		}
		return false;
	case 2: //2��ʱ���ﵽ30�ֿ�����
		if (iScore % 30 == 0 && iScore != 0 &&  iScore <= 30)
		{
			iScore = 0;//������0
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			iLevel++;//�ȼ���1
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			psnake->m_Speed = psnake->m_Speed - 100;//����
		}
		return false;
	case 3: //3��ʱ���ﵽ40�ֿ�ͨ��
		if (iScore % 40 == 0 && iScore != 0 && iScore <= 40)
		{
			iScore = 0;//������0
			unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
			cout << iScore;
			iLevel++;//�ȼ���1
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			psnake->m_Speed = psnake->m_Speed - 100;//����
		}
		return false;
	case 4: //4��ʱ���ﵽ50�ֿ�ͨ��
		if (iScore % 50 == 0 && iScore != 0 && iScore <= 50)
		{
			unit::gotoxy(unit::KLEFT + 68, unit::KUP + 1);
			cout << iLevel;
			return true;//ͨ��
		}
	default:
		break;
	}
		
}

void control::drawGameArea()//������Ϸ��ͼ 
{
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int j = 0; j < unit::KWIDTH; j++)//�����ϱ߿�
		cout << "-";
	for (int i = 0; i < unit::KHEIGHT; i++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP  + i);//������߿�
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH , unit::KUP  + i);//�����ұ߿�
		cout << "|";
	}
	unit::gotoxy(unit::KLEFT,unit::KHEIGHT );//�����±߿�
	for (int k = 0; k < unit::KWIDTH; k++)
		cout << "-";
	unit::gotoxy(unit::KLEFT , unit::KUP + 2);//���Ʊ����±߿�
	for (int i = 0; i < unit::KWIDTH ; i++)
		cout << "-";
}
void control::drawGameInfo()//������Ϸ��Ϣ
{
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);
	cout << "��Ϸ���ƣ�̰����";
	unit::gotoxy(unit::KLEFT + 21, unit::KUP + 1);
	cout << "��д�ߣ���ة��";
	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);
	cout << "��ǰ�÷�";
	unit::gotoxy(unit::KLEFT + 50, unit::KUP + 1);
	cout << iScore;
	unit::gotoxy(unit::KLEFT + 57, unit::KUP + 1);
	cout << "��ǰ�ؿ�";
	unit::gotoxy(unit::KLEFT +68 , unit::KUP + 1);
	cout << iLevel;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH +1, unit::KUP + 5);
	cout << "��Ϸ���� ͨ��wasd������̰�����ƶ��ո����ͣ" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 6);
	cout << "���Ĺأ���һ��20��ͨ��" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 7);
	cout << "        �ڶ���30��ͨ��" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 8);
	cout << "        ������40��ͨ��" << endl;
	unit::gotoxy(unit::KLEFT + unit::KWIDTH + 1, unit::KUP + 9);
	cout << "        ���Ĺ�50��ͨ��" << endl;
}