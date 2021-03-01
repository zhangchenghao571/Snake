#include "snake.h"
snake::snake(int x, int y, int len, int speed, Dir dir, char pic)
{
	m_HeadX = x;
	m_HeadY = y;
	m_dir = dir;
	m_Speed = speed;
	m_Len = len;

	for (int i = 0; i <= m_Len; i++)
	{
		unit MyUnit(0, 0, 'o');
		m_Body.push_back(MyUnit);
		switch (dir)
		{
		case KUP:
			m_Body[i].m_x = m_HeadX;
			m_Body[i].m_y = m_HeadY + i;
			break;
		case KDOWN:
			m_Body[i].m_x = m_HeadX;
			m_Body[i].m_y = m_HeadY - i;
			break;
		case KLEFT:
			m_Body[i].m_x = m_HeadX + i;
			m_Body[i].m_y = m_HeadY;
			break;
		case KRIGHT:
			m_Body[i].m_x = m_HeadX - i;
			m_Body[i].m_y = m_HeadY;
			break;
		default:
			break;
		}
	}
}

snake::~snake()
{
}

void snake::showSnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].show();
	}
}

void snake::eraseSnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].erase();
	}
}

void snake::move()
{

	//m_HeadX = m_Body[0].m_x;
	//m_HeadY = m_Body[0].m_y;
	eraseSnake();
	for (int i = m_Len - 1; i > 0 ; i--)
	{
		m_Body[i].m_x = m_Body[i-1].m_x;
		m_Body[i].m_y = m_Body[i-1].m_y;
	}

	switch (m_dir)
	{
	case KUP:
		m_Body[0].m_y--;
		m_HeadX = m_Body[0].m_x;
		m_HeadY = m_Body[0].m_y;
		break;
	case KDOWN:
		m_Body[0].m_y++;
		m_HeadX = m_Body[0].m_x;
		m_HeadY = m_Body[0].m_y;
		break;
	case KLEFT:
		m_Body[0].m_x--;
		m_HeadX = m_Body[0].m_x;
		m_HeadY = m_Body[0].m_y;
		break;
	case KRIGHT:
		m_Body[0].m_x++;
		m_HeadX = m_Body[0].m_x;
		m_HeadY = m_Body[0].m_y;
		break;
	default:
		break;
	}
	showSnake();
	Sleep(m_Speed);
	//eraseSnake();
}
bool  snake::eatfood(food* pfood)
{
	if (m_Body[0].m_x == pfood->m_x && m_Body[0].m_y == pfood->m_y)
	{
		pfood->erase();
		growup();
		//showSnake();
		return 1;
	}
	return 0;
}
void snake::growup()
{
	unit MyUnit(0, 0, 'o');
	m_Body.push_back(MyUnit);
	m_Len++;
}
void snake::changeDir(int vk)
{
	switch (vk)
	{
	case 119://w°´¼ü¼üÂë  72
		if ((m_dir != KUP) && (m_dir != KDOWN))
			m_dir = KUP;
		break;
	case 115://s°´¼ü¼üÂë  80
		if ((m_dir != KUP) && (m_dir != KDOWN))
			m_dir = KDOWN;
		break;
	case 97://a°´¼ü¼üÂë  75
		if ((m_dir != KLEFT) && (m_dir != KRIGHT))
			m_dir = KLEFT;
		break;
	case 100://d°´¼ü¼üÂë  77
		if ((m_dir != KLEFT) && (m_dir != KRIGHT))
			m_dir = KRIGHT;
		break;

	}
}