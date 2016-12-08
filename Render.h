#pragma once
class Render
{
public:
	Render();
	~Render();

	void DrawEnemy(Enemy* e);
	void DrawPlayer(Player* p);
	void Begin(ALLEGRO_BITMAP* bg);
	void End();
};

