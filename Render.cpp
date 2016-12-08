#include "Main.h"



Render::Render()
{
}


Render::~Render()
{
}

void Render::DrawEnemy(Enemy* e)
{
	if (e->bmp != NULL)
		al_draw_bitmap(e->bmp, e->x, e->y, 0);

}
void Render::DrawPlayer(Player* p)
{
	if (p->GetBmp() != NULL)
		al_draw_bitmap(p->GetBmp(), p->GetX(), p->GetY(), 0);
}
void Render::Begin(ALLEGRO_BITMAP* bg)
{
	al_draw_bitmap(bg, 20, 0, 0);
}
void Render::End()
{
	al_flip_display();
}
