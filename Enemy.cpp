#include "Main.h"



Enemy::Enemy()
{
	x = y = 0;
	bmp = NULL;
	type = 0;
}


Enemy::~Enemy()
{
}


void Enemy::Move(int px, int py)
{
	if (type == 0)
	{
		x += sx;
		y += sy;
	}

	if (type == 1)
	{
		if (x < px)
			x += sx;
		if (x > px)
			x -= sx;
		if (y < py)
			y += sy;
		if (y > py)
			y -= sy;
	}

	if (x > 640)
		sx *= -1;
	if (x < 0)
		sx *= -1;
	if (y > 480)
		sy *= -1;
	if (y < 0)
		sy *= -1;
}