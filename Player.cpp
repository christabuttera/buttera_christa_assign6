#include "Main.h"

struct Rect
{
	int x;
	int y;
	int w;
	int h;
};

float Distance(int x1, int y1, int x2, int y2)
{
	float d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	d = sqrt(d);
	return d;
}

bool InRect(int x, int y, Rect r)
{
	if (x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h)
		return true;
	else
		return false;
}

Player::Player()
{
	x = y = 0;
	bmp = NULL;
	collisionMethod = CollisionMethod::InsideRect;

}


Player::~Player()
{
}

void Player::Move()
{
	x += sx;
	y += sy;
}

bool Player::Collision(Enemy* o1, Player* o2)
{
	switch (collisionMethod)
	{
	case CollisionMethod::TopLeft:
		return Collision1(o1, o2);
		//break; 
	case CollisionMethod::Centre:
		return Collision2(o1, o2);
		//break;
	case CollisionMethod::InsideRect:
		return Collision3(o1, o2);
		//break;
	default:
		return false;
		//break;
	}
}

bool Player::Collision1(Enemy* o1, Player* o2)
{
	int x1 = o1->x;
	int y1 = o1->y;
	int x2 = o2->x;
	int y2 = o2->y;
	float d = Distance(x1, y1, x2, y2);
	if (d < 10)
		return true;
	else
		return false;
}
bool Player::Collision2(Enemy* o1, Player* o2)
{
	int w1 = al_get_bitmap_width(o1->bmp);
	int h1 = al_get_bitmap_height(o1->bmp);
	int w2 = al_get_bitmap_width(o2->bmp);
	int h2 = al_get_bitmap_height(o2->bmp);
	int x1 = o1->x + w1 / 2;
	int y1 = o1->y + h1 / 2;
	int x2 = o2->x + w2 / 2;
	int y2 = o2->y + h2 / 2;
	float d = Distance(x1, y1, x2, y2);
	if (d < 10)
		return true;
	else
		return false;
}
bool Player::Collision3(Enemy* o1, Player* o2)
{
	//method 3 (check if one is inside the other)
	int w1 = al_get_bitmap_width(o1->bmp);
	int h1 = al_get_bitmap_height(o1->bmp);
	int w2 = al_get_bitmap_width(o2->bmp);
	int h2 = al_get_bitmap_height(o2->bmp);
	Rect r;
	r.x = o2->x;
	r.y = o2->y;
	r.w = w2;
	r.h = h2;
	bool in_TopLeft = InRect(o1->x, o1->y, r);
	bool in_TopRight = InRect(o1->x + w1 - 1, o1->y, r);
	bool in_BottomLeft = InRect(o1->x, o1->y + h1 - 1, r);
	bool in_BottomRight = InRect(o1->x + w1 - 1, o1->y + h1 - 1, r);
	if (in_TopLeft || in_TopRight || in_BottomLeft || in_BottomRight)
		return true;
	else
		return false;
}

void Player::SetX(int newx)
{
	x = newx;
}
int Player::GetX()
{
	return x;
}
void Player::SetY(int newy)
{
	y = newy;
}
int Player::GetY()
{
	return y;
}
void Player::SetSX(int newsx)
{
	sx = newsx;
}
int Player::GetSX()
{
	return sx; 
}
void Player::SetSY(int newsy)
{
	sy = newsy;
}
int Player::GetSY()
{
	return sy;
}
void Player::SetScore(int newscore)
{
	score = newscore;
}
int Player::GetScore()
{
	return score;
}
void Player::SetHealth(int newhealth)
{
	health = newhealth;
}
int Player::GetHealth()
{
	return health;
}
void Player::SetBmp(ALLEGRO_BITMAP* newbmp)
{
	bmp = newbmp;
}
ALLEGRO_BITMAP* Player::GetBmp()
{
	return bmp;
}

