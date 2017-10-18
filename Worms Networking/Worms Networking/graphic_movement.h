#pragma once
#include <allegro5\allegro5.h>
#include <string>
#include "Worm.h"

struct WormInfo
{
	uint32_t posx;
	uint32_t posy;
	char wormNumber;
	char frame;
	char orientation;
	char state;
};

#define PACKAGE_LEN 7 //tama�o del campo de datos del package del Worm.

#define HEADER 0         //ordenamiento del campo de datos del packacge de Worm.
#define WORM_NUMBER 1
#define STATE 2
#define FRAME 3
#define ORIENTATION 4
#define POSX 5
#define POSY 6

using namespace std;

class graphic_movement
{

public:

	unsigned int cant_walk_imgs;
	unsigned int cant_jump_imgs;

	//	ALLEGRO_BITMAP ** jump_img_lib;
	//	ALLEGRO_BITMAP ** walk_img_lib;

	ALLEGRO_BITMAP* walk_img_lib[15];
	ALLEGRO_BITMAP* jump_img_lib[10];
	ALLEGRO_BITMAP * background;
	ALLEGRO_BITMAP * backgroundwoalpha;


	string prefix_walk;
	string prefix_jump;
	string prefix_background;
	string prefix_backgroundwoalpha;
	string extension;

	graphic_movement();
	void init();
	void load_walk_imgs();
	void load_background();
	void flip_background();
	void do_walking_step(Worm &worm);
	void do_walking_step(WormInfo & worm); //para modificar Worms controlados por otra pc.
	void do_jumping_step(Worm &worm);
	void do_jumping_step(WormInfo & worm); //para modificar Worms controlados por otra pc.
	void load_jump_imgs();


	void load_backgroundwoalpha();

	void flip_backgroundwoalpha();


	~graphic_movement();
};


