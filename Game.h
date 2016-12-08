#pragma once

#define NUM_ENEMIES 10

class Game
{
public:
	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_MOUSE_STATE mouse_state;

	Render render;

	ALLEGRO_BITMAP* bg;
	ALLEGRO_BITMAP* winbg;
	Player player;
	ALLEGRO_BITMAP* pbmp;
	ALLEGRO_BITMAP* pbmp2;
	ALLEGRO_BITMAP* pOpenbmp;
	Enemy enemy[NUM_ENEMIES];
	ALLEGRO_BITMAP* ebmp;
	ALLEGRO_BITMAP* ebmp2;

	bool end;

	//functions
	Game();
	~Game();
	void Run();
	void Update();
	void Draw();
};


