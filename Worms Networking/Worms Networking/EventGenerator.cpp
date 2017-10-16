#include "EventGenerator.h"

EventGenerator::EventGenerator(Worm & worm, Graphic & graficos)
{
	quit = false;
	for (int i = 0; i < 512; i++)
	{
		buffer[i] = 0;
	}
	//inicializar todos los datos miembros relacionados a worms y graphics;
}

EventGenerator::~EventGenerator()
{
}

void EventGenerator::searchForEvents()
{
	bool finished = false;
	int cant;
	while (!finished)
	{
		if (al_get_next_event(eventQueue,&evento))
		{
			shape(evento);
		}
		else if (cant = socket_forServer->read_some(boost::asio::buffer(buffer)))
		{
			shape(buffer,cant);
		}
		else 
		{
			finished = true;
		}
	}
}

bool EventGenerator::hayEvento()
{
	if (eventList.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool EventGenerator::isNotQuit()
{
	return (!quit);
}

/*
	La funcion  getNextEvent supone que hay por lo menos un elemento en la lista, se debe preguntar antes
	si lo hay con la funcion hayEvento
*/
genericEvent EventGenerator::getNextEvent()
{
	std::list<genericEvent>::iterator it= eventList.begin();
	genericEvent  current_ev = (*it);
	eventList.pop_front();
	return current_ev;
}

void EventGenerator::shape(ALLEGRO_EVENT ev)
{
		genericEvent events; //hay que cambiarlo a un wormEvent 
		switch (ev.type) 
		{
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				events.eventType = QUIT;
				events.ud = 0;
				quit = true;
				break;
			case ALLEGRO_EVENT_TIMER:
				events.eventType = REFRESH;
				events.ud = 0;
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				switch (ev.keyboard.keycode)
				{
				case P1_LEFT:
					events.eventType = PRESS_MOVE;
					events.ud = P1_LEFT;
					break;
				case P1_RIGHT:
					events.eventType = PRESS_MOVE;
					events.ud = P1_RIGHT;
					break;
				case P1_UP:
					events.eventType = PRESS_JUMP;
					events.ud = P1_UP;
					break;
				}
				break;
			case ALLEGRO_EVENT_KEY_UP:
				switch (ev.keyboard.keycode)
				{
				case P1_LEFT:
					events.eventType = RELEASE_MOVE;
					events.ud = P1_LEFT;
					break;
				case P1_RIGHT:
					events.eventType = RELEASE_MOVE;
					events.ud = P1_RIGHT;
					break;
				case P1_UP:
					events.eventType = RELEASE_JUMP;
					events.ud = P1_UP;
					break;
				}
				break;
		}
		eventList.push_back(events);
}

void EventGenerator::shape(char * buf, unsigned int cant)
{
	//segun como sea cada package, hay que generar un evento correspondiente para despues meterlo en la cola de eventos
}
