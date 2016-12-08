#pragma once
class Enemy
{
public:
	int x;
	int y;
	ALLEGRO_BITMAP* bmp;
	int sx;
	int sy;
	int type;

	Enemy();
	~Enemy();

	void Move(int px, int py);
};

