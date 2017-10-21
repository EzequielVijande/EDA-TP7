#include <iostream>
#include <cstdlib>
#include <ctime>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "EventGenerator.h"
#include "Worm.h"
#include "fileHandler.h"
#include "FSM.h"



const float FPS = 50.0;
typedef ALLEGRO_DISPLAY* p2display_t;
typedef ALLEGRO_TIMER* p2timer_t;
typedef ALLEGRO_EVENT_QUEUE* p2ev_queue_t;


bool initAll(p2display_t& display, p2timer_t& timer, p2ev_queue_t& evqueue);

int main(int argc, char ** argv)
{
	//inicilizacion de allegro y boost
	srand(time(NULL));
	ALLEGRO_DISPLAY * display = nullptr;
	ALLEGRO_TIMER * timer = nullptr;
	ALLEGRO_EVENT_QUEUE* event_queue = nullptr;

	if (!initAll(display, timer, event_queue))
	{
		cout << "Failed initialization" << endl;
		return -1;
	}

	graphic_movement Graphics;

	Graphics.init();
	Graphics.load_walk_imgs();
	Graphics.load_background();
	Graphics.load_jump_imgs();
	Graphics.load_backgroundwoalpha();




	fsm state_machine;
	Worm worms;
	worms.setKeys(P1_RIGHT, P1_LEFT, P1_UP);
	EventGenerator eg(&worms,&Graphics, event_queue); // se le pasan cosas que sobreviven al dispatcher

	cout << "Timer inicializado" << endl;

	al_start_timer(timer);
	do
	{
		eg.searchForEvents();
		if(eg.hayEvento())
		{

			state_machine.dispatch(eg.getNextEvent());

		}
	}while(eg.isNotQuit());

	//destruyo todo lo que cree
	
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	return 0;
}



bool initAll(p2display_t& display, p2timer_t& timer, p2ev_queue_t& ev_queue)
{
	if (!al_init()) {
		return false;
	}

	display = al_create_display(1920, 696);

	if (display == nullptr) {
		return false;
	}

	if (!al_install_keyboard())
	{
		return false;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		return false;
	}

	if (!al_init_image_addon()) { // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes
		return false;
	}
	ev_queue = al_create_event_queue();
	if (!ev_queue)
	{
		return false;
	}
	al_register_event_source(ev_queue, al_get_display_event_source(display));
	al_register_event_source(ev_queue, al_get_timer_event_source(timer));
	al_register_event_source(ev_queue, al_get_keyboard_event_source());
	al_register_event_source(ev_queue, al_get_keyboard_event_source());

	return true;
}