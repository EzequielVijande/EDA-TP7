#pragma once

#include <list>
#include "Worm.h"
#include "allegro5\allegro.h"
#include "boost\asio.hpp"
#include "Event.h"
#include "Output.h" //Lo de graphics iria en este header


#define P1_LEFT		ALLEGRO_KEY_LEFT
#define P1_RIGHT	ALLEGRO_KEY_RIGHT
#define P1_UP		ALLEGRO_KEY_UP


class Graphic
{
	int hay_que_agregarlo;
};

class EventGenerator
{
public:
	EventGenerator(Worm& worm, Graphic& graficos);
	~EventGenerator();
	void searchForEvents();
	bool hayEvento();
	bool isNotQuit();
	GenericEvent getNextEvent();
private:
	void shape(ALLEGRO_EVENT ev);
	void shape(char * buf, unsigned int cant);

	ALLEGRO_EVENT_QUEUE * eventQueue;
	ALLEGRO_EVENT evento;

	char buffer[512];
	bool quit;
	std::list<GenericEvent> eventList;

	boost::asio::io_service*  IO_handler;
	boost::asio::ip::tcp::socket* socket_forServer;
	boost::asio::ip::tcp::acceptor* server_acceptor;
};

