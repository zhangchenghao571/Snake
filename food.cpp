#include "food.h"

food::food()
{

}

food::~food()
{

}

void food::CreatPos()
{

	srand((int)time(0));
	m_x = KLEFT + 5 + rand() % (KWIDTH - 6);
	m_y = KUP + 5 + rand() % (KHEIGHT - 6);

}
