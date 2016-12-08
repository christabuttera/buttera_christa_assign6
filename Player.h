#pragma once
enum CollisionMethod
{
	TopLeft,
	Centre,
	InsideRect
};

class Player
{
	int x;
	int y;
	ALLEGRO_BITMAP* bmp; //shape
	int score;
	int health;
	int sx;
	int sy;

public:
	CollisionMethod collisionMethod;

	Player();
	~Player();

	void Move();
	bool Collision(Enemy* o1, Player* o2);
	bool Collision1(Enemy* o1, Player* o2);
	bool Collision2(Enemy* o1, Player* o2);
	bool Collision3(Enemy* o1, Player* o2);

	void SetX(int newx);
	int GetX();
	void SetY(int newy);
	int GetY();
	void SetSX(int newsx);
	int GetSX();
	void SetSY(int newsy);
	int GetSY();
	void SetScore(int newscore);
	int GetScore();
	void SetHealth(int newhealth);
	int GetHealth();
	void SetBmp(ALLEGRO_BITMAP* newbmp);
	ALLEGRO_BITMAP* GetBmp();


};

