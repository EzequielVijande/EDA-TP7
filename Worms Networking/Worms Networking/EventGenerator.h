#pragma once

#include <list>
#include "Worm.h"
#include "allegro5\allegro.h"
#include "boost\asio.hpp"
#include "Event.h"
#include "WormEvent.h"
#include "RefreshEvent.h"


#define P1_LEFT		ALLEGRO_KEY_LEFT
#define P1_RIGHT	ALLEGRO_KEY_RIGHT
#define P1_UP		ALLEGRO_KEY_UP



struct WormInfo
{
	uint32_t posx;
	uint32_t posy;
	char wormNumber;
	char frame;
	char orientation;
	char state;
};

std::list<WormInfo> wormsList;

class EventGenerator
{
public:
	EventGenerator(Worm * worm, Graphic * graficos, BoostResources * connection);
	~EventGenerator();
	void searchForEvents();
	bool hayEvento();
	bool isNotQuit();
	GenericEvent getNextEvent();
	std::list<WormInfo>::iterator getListIterator();

private:
	void shape(ALLEGRO_EVENT ev);
	void shape(char * buf, unsigned int cant);
	bool DetectLittleEndian(void);

	ALLEGRO_EVENT_QUEUE * eventQueue;
	ALLEGRO_EVENT evento;

	char buffer[512];
	bool quit;

	std::list<GenericEvent> eventList;
	std::list<WormInfo> wormsList;

	Worm * worm_;
	Graphic * graficos_;
	boost::asio::ip::tcp::socket* socket_; //lo necesario para poder leer y escribir
};

