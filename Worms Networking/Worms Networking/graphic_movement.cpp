#include "graphic_movement.h"
#include <iostream>


const unsigned int wwalkingseq_arr[42] = { 4,5,6,7,8,9,10,11,11,12,13,14,15,4 , 4,5,6,7,8,9,10,11,11,12,13,14,15,4  ,4,5,6,7,8,9,10,11,11,12,13,14,15,4 };
// el salto tarda 33 frames y el resto (o sea 50-33) los hago con las animaciones de "aterrizaje"
const unsigned int wjumpingseq_arr[33] = { 1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };
const unsigned int wlandingseq_arr[17] = { 3,3,4,4,4,5,5,5,6,6,7,7,8,8,8,8,9 };

graphic_movement::graphic_movement()
{

	for (unsigned int i = 0; i < cant_walk_imgs; i++) {
		walk_img_lib[i] = nullptr;
	}

	for (unsigned int i = 0; i < cant_jump_imgs; i++) {
		jump_img_lib[i] = nullptr;
	}
	background = nullptr;

}

void graphic_movement::init() {

	prefix_walk = "Worms Images/wwalking/wwalk-F";
	prefix_jump = "Worms Images/wjump/wjump-F";
	prefix_background = "Worms Images/Scenario";
	prefix_backgroundwoalpha = "Worms Images/windows";
	extension = ".png";

}

graphic_movement::~graphic_movement()
{

	for (unsigned int i = 0; i < cant_walk_imgs; i++) {
		al_destroy_bitmap(walk_img_lib[i]);
	}
	for (unsigned int i = 0; i < cant_jump_imgs; i++) {
		al_destroy_bitmap(jump_img_lib[i]);
	}
}




void graphic_movement::load_walk_imgs() {
	for (unsigned int i = 0; i < 15; i++) { // el 1 es por F1, F2.. etc

		string aux = prefix_walk + to_string(i + 1) + extension;
		walk_img_lib[i] = al_load_bitmap(&aux[0]);

	}
}

void graphic_movement::load_jump_imgs() {

	for (unsigned int i = 0; i < 10; i++) { // el 1 es por F1, F2.. etc
		string extension = ".png";
		string aux = prefix_jump + to_string(i + 1) + extension;
		jump_img_lib[i] = al_load_bitmap(&aux[0]);
	}
}

void graphic_movement::load_background()
{
	string aux = prefix_background + extension;
	background = al_load_bitmap(&aux[0]);
}

void graphic_movement::load_backgroundwoalpha()
{
	string aux2 = prefix_backgroundwoalpha + extension;
	backgroundwoalpha = al_load_bitmap(&aux2[0]);
}



void graphic_movement::do_jumping_step(Worm &worm) {

	switch (worm.getState()) {
	case IDLE:

		// NADA
		break;

	case JUMPING: // deberia saltar y saltar mientras esta saltando

		if (worm.getFrameCount() >= 0 && worm.getFrameCount() < 5) {
		}
		else if (worm.getFrameCount() >= 5 && worm.getFrameCount() < 38) { 
			al_draw_bitmap(jump_img_lib[wjumpingseq_arr[worm.getFrameCount() - 5] - 1], worm.getPos().x, worm.getPos().y, worm.getSentido());
		}

		if ((worm.getFrameCount() >= 38) && (worm.getFrameCount() <= 50)) {
			al_draw_bitmap(jump_img_lib[wlandingseq_arr[worm.getFrameCount() - 38] - 1], worm.getPos().x, worm.getPos().y, worm.getSentido());
		}

		break;
	case END_JUMPING:
		if (worm.getFrameCount() >= 0 && worm.getFrameCount() < 5) {
		}
		else if (worm.getFrameCount() >= 5 && worm.getFrameCount() < 38) {
			al_draw_bitmap(jump_img_lib[wjumpingseq_arr[worm.getFrameCount() - 5] - 1], worm.getPos().x, worm.getPos().y, worm.getSentido());
		}

		if ((worm.getFrameCount() >= 38) && (worm.getFrameCount() <= 50)) {
			al_draw_bitmap(jump_img_lib[wlandingseq_arr[worm.getFrameCount() - 38] - 1], worm.getPos().x, worm.getPos().y, worm.getSentido());
		}
		break;
	}

}

void graphic_movement::do_jumping_step(WormInfo & worm)
{
	switch (worm.state) {
	case IDLE:

		// NADA
		break;

	case JUMPING: // deberia saltar y saltar mientras esta saltando

		if (worm.frame >= 0 && worm.frame < 5) {
		}
		else if (worm.frame >= 5 && worm.frame < 38) {
			al_draw_bitmap(jump_img_lib[wjumpingseq_arr[(worm.frame) - 5] - 1], worm.posx, worm.posy, worm.orientation);
		}

		if ((worm.frame >= 38) && (worm.frame <= 50)) {
			al_draw_bitmap(jump_img_lib[wlandingseq_arr[(worm.frame) - 38] - 1], worm.posx, worm.posy, worm.orientation);
		}

		break;
	case END_JUMPING:
		if (worm.frame >= 0 && worm.frame < 5) {
		}
		else if (worm.frame >= 5 && worm.frame < 38) {
			al_draw_bitmap(jump_img_lib[wjumpingseq_arr[(worm.frame) - 5] - 1], worm.posx, worm.posy, worm.orientation);
		}

		if ((worm.frame >= 38) && (worm.frame <= 50)) {
			al_draw_bitmap(jump_img_lib[wlandingseq_arr[(worm.frame) - 38] - 1], worm.posx, worm.posy, worm.orientation);
		}
		break;
	}

}

void graphic_movement::do_walking_step(Worm &worm) {

	unsigned int aux = worm.getState();


	switch (aux) {
	case IDLE:

		al_draw_bitmap(walk_img_lib[0], worm.getPos().x, worm.getPos().y, worm.getSentido());


		break;
	case MONITOR_MOVING:

		al_draw_bitmap(walk_img_lib[0], worm.getPos().x, worm.getPos().y, worm.getSentido());
		break;

	case MOVING:

		if (worm.getFrameCount() >= 5 && worm.getFrameCount() < 8) {
			al_draw_bitmap(walk_img_lib[worm.getFrameCount() - 5], worm.getPos().x, worm.getPos().y, worm.getSentido());

		}

		if (worm.getFrameCount() >= 8 && worm.getFrameCount() < 50) {
			al_draw_bitmap(walk_img_lib[wwalkingseq_arr[worm.getFrameCount() - 8] - 1], worm.getPos().x, worm.getPos().y, worm.getSentido());

		}


		break;
	case END_MOVEMENT:
		if (worm.getFrameCount() >= 5 && worm.getFrameCount() < 8) {
			al_draw_bitmap(walk_img_lib[worm.getFrameCount() - 5], worm.getPos().x, worm.getPos().y, worm.getSentido());

		}

		if (worm.getFrameCount() >= 8 && worm.getFrameCount() < 50) {
			al_draw_bitmap(walk_img_lib[wwalkingseq_arr[worm.getFrameCount() - 8] - 1], worm.getPos().x, worm.getPos().y, worm.getSentido());

		}
		break;

	}
}

void graphic_movement::do_walking_step(WormInfo & worm)
{
	unsigned int aux = worm.state;


	switch (aux) {
	case IDLE:

		al_draw_bitmap(walk_img_lib[0], worm.posx, worm.posy, worm.orientation);


		break;
	case MONITOR_MOVING:

		al_draw_bitmap(walk_img_lib[0], worm.posx, worm.posy, worm.orientation);
		break;

	case MOVING:

		if (worm.frame >= 5 && worm.frame < 8) {
			al_draw_bitmap(walk_img_lib[(worm.frame) - 5], worm.posx, worm.posy, worm.orientation);

		}

		if (worm.frame >= 8 && worm.frame < 50) {
			al_draw_bitmap(walk_img_lib[wwalkingseq_arr[(worm.frame) - 8] - 1], worm.posx, worm.posy, worm.orientation);

		}


		break;
	case END_MOVEMENT:
		if (worm.frame >= 5 && worm.frame < 8) {
			al_draw_bitmap(walk_img_lib[(worm.frame) - 5], worm.posx, worm.posy, worm.orientation);

		}

		if (worm.frame >= 8 && worm.frame < 50) {
			al_draw_bitmap(walk_img_lib[wwalkingseq_arr[(worm.frame) - 8] - 1], worm.posx, worm.posy, worm.orientation);

		}
		break;

	}
}

void graphic_movement::flip_background()
{
	al_draw_scaled_bitmap(background, 0, 0, 1920, 696, 0, 0, 1920, 696, 0);
}


void graphic_movement::flip_backgroundwoalpha() {
	al_draw_scaled_bitmap(backgroundwoalpha, 0, 0, 1200, 800, 0, 0, 1920, 696, 0);
}