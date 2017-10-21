#pragma once

#include <list>
#include "State.h"
#include "Event.h"
#include "Worm.h"
#include "allegro5\allegro.h"
#include "Event.h"
#include "WormEvent.h"
#include "RefreshEvent.h"
#include "graphic_movement.h"
#include "WormInfo.h"

#define P1_RIGHT	ALLEGRO_KEY_RIGHT
#define P1_LEFT		ALLEGRO_KEY_LEFT
#define P1_UP		ALLEGRO_KEY_UP

class EventGenerator
{
public:
	EventGenerator(Worm * worm, graphic_movement * graficos, ALLEGRO_EVENT_QUEUE* ev_q);
	~EventGenerator();
	void searchForEvents();
	bool hayEvento();
	bool isNotQuit();
	GenericEvent* getNextEvent();
	std::list<WormInfo>::iterator getListIterator();

private:
	void shape(ALLEGRO_EVENT ev);
	bool DetectLittleEndian(void);

	ALLEGRO_EVENT_QUEUE * eventQueue;
	ALLEGRO_EVENT evento;
	bool quit;

	std::list<GenericEvent*> eventList;
	std::list<WormInfo> wormsList;

	Worm * worm_;
	graphic_movement * graficos_;
};

