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
GenericEvent EventGenerator::getNextEvent()
{
	std::list<GenericEvent>::iterator it= eventList.begin();
	GenericEvent  current_ev = (*it);
	eventList.pop_front();
	return current_ev;
}

void EventGenerator::shape(ALLEGRO_EVENT ev)
{
	GenericEvent events; //hay que cambiarlo a un wormEvent 
		switch (ev.type) 
		{
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				events.SetEvent(QUIT);
				events.SetUd(0);
				quit = true;
				break;
			case ALLEGRO_EVENT_TIMER:
				events.SetEvent(REFRESH);
				events.SetUd(0);
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				switch (ev.keyboard.keycode)
				{
				case P1_LEFT:
					events.SetEvent(PRESS_MOVE);
					events.SetUd(P1_LEFT);
					break;
				case P1_RIGHT:
					events.SetEvent(PRESS_MOVE);
					events.SetUd(P1_RIGHT);
					break;
				case P1_UP:
					events.SetEvent(PRESS_JUMP);
					events.SetUd(P1_UP);
					break;
				}
				break;
			case ALLEGRO_EVENT_KEY_UP:
				switch (ev.keyboard.keycode)
				{
				case P1_LEFT:
					events.SetEvent(RELEASE_MOVE);
					events.SetUd(P1_LEFT);
					break;
				case P1_RIGHT:
					events.SetEvent(RELEASE_MOVE);
					events.SetUd(P1_RIGHT);
					break;
				case P1_UP:
					events.SetEvent(RELEASE_JUMP);
					events.SetUd(P1_UP);
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
