#include "Main.h"



Game::Game()
{
	srand(time(NULL));

	bg = al_load_bitmap("bg.bmp");

	//initialize player
	pbmp = al_load_bitmap("player.bmp");
	pbmp2 = al_load_bitmap("player2.bmp"); 
	pOpenbmp = al_load_bitmap("playerNom.bmp");
	player.SetBmp(pbmp);
	player.SetX(60);
	int px = player.GetX();
	player.SetY(150);
	int py = player.GetY();
	player.SetScore(0);
	player.SetHealth(10);

	//initialize enemies
	ebmp = al_load_bitmap("enemy.bmp");
	ebmp2 = al_load_bitmap("enemy2.bmp");
	for (int i = 0; i < NUM_ENEMIES; i++)
	{
		enemy[i].bmp = ebmp;
		enemy[i].x = rand() % 600;
		enemy[i].y = rand() % 400;
		enemy[i].sx = enemy[i].sy = rand() % -1 + 2;
		enemy[i].type = rand() % 2;
	}
	
	end = false;

	player.collisionMethod = CollisionMethod::InsideRect;
}


Game::~Game()
{
	//release/destroy everything created in this class
	al_destroy_bitmap(bg);
	al_destroy_bitmap(pbmp);
	al_destroy_bitmap(ebmp);
}

void Game::Run()
{
	while (end == false)
	{
		Update();
		Draw();
		al_rest(0.01);
	}

}
void Game::Update()
{		
	player.SetSX(0);
	player.SetSY(0);
	al_get_keyboard_state(&key_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
		end = true;

	if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
		player.SetSX(2);

	if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
		player.SetSX(-2);

	if (al_key_down(&key_state, ALLEGRO_KEY_UP))
		player.SetSY(-2);

	if (al_key_down(&key_state, ALLEGRO_KEY_DOWN))
		player.SetSY(2);

	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
	{
		player.SetBmp(pOpenbmp);
		player.SetSX(0);
		player.SetSY(0);
	}
	else
		player.SetBmp(pbmp);

	if (player.GetScore() == 10)
	{
		player.SetBmp(pbmp2);
	}

	player.Move();

	for (int i = 0; i < NUM_ENEMIES; i++)
	{
		if (enemy[i].type == 0)
		{
			enemy[i].bmp = ebmp;
			enemy[i].Move(player.GetX(), player.GetY());
		}
		if (enemy[i].type == 1)
		{
			enemy[i].bmp = ebmp2;
			enemy[i].Move(player.GetX(), player.GetY());
		}
		

		if (al_key_down(&key_state, ALLEGRO_KEY_SPACE) && player.Collision(&enemy[i], &player))
		{
			int score = player.GetScore();
			score ++;
			player.SetScore(score);
			enemy[i].x = 1000;
		}
		if (player.Collision(&enemy[i], &player))
		{
			int h = player.GetHealth();
			h--;
			player.SetHealth(h);
			enemy[i].x = rand() % 600;
			enemy[i].y = rand() % 400;
			if (player.GetHealth() == 0)
				end = true;
		}
	}
	
}
void Game::Draw()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	render.Begin(bg);

	render.DrawPlayer(&player);
	for (int i = 0; i < NUM_ENEMIES; i++)
		render.DrawEnemy(&enemy[i]);

	render.End();
}