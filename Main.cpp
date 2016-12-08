/*
Title:		Assignment-2
Author:		Christa Buttera
Objective:	Learning how to take a single-source-filed code and separate it into categorized classes; learning how to change the "Main" source file
			so that it can use objects and classes from different files; learning how to use Private pieces of data using Get/Set Functions
Object Description:
	1. Player Class
	a) Data:
		- x: horizontal position of player on screen
		- y: vertical position of player on screen
		- sx: player speed in x direction
		- sy: player speed in y direction
		- ALLEGRO_BITMAP* bmp: pointer to a bitmap that will dictate the shape/appearance of player
		- score: player score out of 10
		- health: player health out of 10
		- CollisionMethod: chooses which method of collision detection to use
	b) Functions:
		- Constructor: initializes player x, y, and bmp
		- Get/Set Functions: makes private variables (x, y, bmp, sx, sy, score, health) accessible in the rest of the program
		- Collision1, Collision2, Collision3: Methods of collision detection (top left corner of player/enemy, center of player/enemy,
		  or inside player/enemy bmp respectively)
	
	2. Enemy Class
	a) Data:
		- x: horizontal position of enemy on screen
		- y: vertical position of enemy on screen
		- ALLEGRO_BITMAP* bmp: pointer to a bitmap that will dictate the shape/appearance of enemy
		- sx: enemy speed in x direction
		- sy: enemy speed in y direction
		- type: dictates bmp and whether enemy moves toward player or moves freely
	b) Functions:
		- Constructor: initializes enemy x, y, bmp and type
		- Move: moves enemy either toward player or freely around the screen depending on type; stops both from leaving
		  the dimensions of the game window

	3. Render Class:
	a) Data:
		- None
	b) Functions:
		- Begin: draws background image bg
		- DrawPlayer: points to player and draws bitmap, as long as player's bitmap is not set to NULL (if NULL, code breaks)
		- DrawEnemy:  points to enemy and draws bitmap, as long as player's bitmap is not set to NULL (if NULL, code breaks)
		- End: Flips display; moves to primary buffer

	4. Game Class:
	a) Data:
		- ALLEGRO_KEYBOARD_STATE key_state: initializes keyboard state
		- ALLEGRO_MOUSE_STATE mouse_state: initializes mouse button state
		- Render render: initializes render class to be used in .cpp file
		- ALLEGRO_BITMAP* bg: initializes name of background image to bg
		- Player player: creates single player from Player class
		- ALLEGRO_BITMAP* pbmp, pbmp2, pOpenbmp: initializes names of images to be used for player
		- Enemy enemy[NUM_ENEMIES]: creates array of 10 enemies from Enemy class (NUM_ENEMIES defined as 10)
		- ALLEGRO_BITMAP* ebmp, ebmp2: initializes names of images to be used for enemy
		- bool end: creates boolean variable that will help dictate if the game is over or not
	b) Functions: 
		- Constructor: initializes player, all enemies and their respective x, y, sx, sy, etc. values. Sets end to false so the game can run, and
		  chooses collision detection method
		- Destructor: destroys bitmaps for bg, player and enemies
		- Run: runs a loop while end is false; loop calls Update and Draw functions, and sets a rest time to 0.01s
		- Update: gets key states and mouse states to dictate player movement, enemy movement, score, health and when end becomes true
		- Draw: calls render.Begin(), render.DrawPlayer(), and render.DrawEnemy(), and then render.End()

	5. Main Class:
	- header file contains all #include options for all of the previous classes mentioned as well as others
	- InitAllegro: initializes all components of allegro (keyboard, display, mouse, etc.)
	- EndAllegro: destroys the display
	- Main: calls InitAllegro(), sets screen width and height to 640x480, creates game from Game class, runs the game using game.Run(), calls EndAllegro
*/


#include "Main.h"

ALLEGRO_DISPLAY* display = NULL;

void InitAllegro(int W, int H)
{

	//initialize allegro
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}

	//initialize display screen
	display = al_create_display(W, H);
	if (!display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
	{
		printf("ok");
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//initialize keyboard
	if (!al_install_keyboard())
	{
		printf("failed to install keyboard!\n"); 
		exit(0);
	}

	//initialize image addon
	if (!al_init_image_addon())
	{
		printf("failed to initialize image addon!\n");
		exit(0);
	}

	//initialize mouse
	if (!al_install_mouse())
	{
		printf("failed to install mouse!\n");
		exit(0);
	}
	//initialize primitive shapes
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		exit(0);
	}
}

void EndAllegro()
{
	al_destroy_display(display);
}

void main()
{
	//initialize
	int sw = 640;
	int sh = 480;
	InitAllegro(sw, sh);

	Game game;

	//run game
	game.Run();

	//clean up
	EndAllegro();
}
