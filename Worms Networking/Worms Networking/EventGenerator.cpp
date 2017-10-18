#include "EventGenerator.h"


EventGenerator::EventGenerator(Worm * worm, Graphic * graficos, BoostResources * connection)
{
	quit = false;
	for (int i = 0; i < 512; i++)
	{
		buffer[i] = 0;
	}

	worm_ = worm;
	graficos_ = graficos;
	socket_ = connection->socket;


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
		else if (cant = socket_->read_some(boost::asio::buffer(buffer)))
		{
			if (buffer[0] == 'W')
			{
				shape(buffer, cant);
			}
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

std::list<WormInfo>::iterator EventGenerator::getListIterator()
	{
		std::list<WormInfo>::iterator it;
		return it;
	}
enum {ioEvent,WormEvent};
void EventGenerator::shape(ALLEGRO_EVENT ev)
{
	int type;
	GenericEvent events;
	switch (ev.type) 
	{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			events.SetEvent(QUIT);
			events.SetUd(0);
			quit = true;
			type = ioEvent;
			break;
		case ALLEGRO_EVENT_TIMER:
			events.SetEvent(REFRESH);
			events.SetUd(0);
			type = ioEvent;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			switch (ev.keyboard.keycode)
			{
			case P1_LEFT:
				events.SetEvent(PRESS_MOVE);
				events.SetUd(P1_LEFT);
				type = WormEvent;
				break;
			case P1_RIGHT:
				events.SetEvent(PRESS_MOVE);
				events.SetUd(P1_RIGHT);
				type = WormEvent;
				break;
			case P1_UP:
				events.SetEvent(PRESS_JUMP);
				events.SetUd(P1_UP);
				type = WormEvent;
				break;
			}
			break;
		case ALLEGRO_EVENT_KEY_UP:
			switch (ev.keyboard.keycode)
			{
			case P1_LEFT:
				events.SetEvent(RELEASE_MOVE);
				events.SetUd(P1_LEFT);
				type = WormEvent;
				break;
			case P1_RIGHT:
				events.SetEvent(RELEASE_MOVE);
				events.SetUd(P1_RIGHT);
				type = WormEvent;
				break;
			case P1_UP:
				events.SetEvent(RELEASE_JUMP);
				events.SetUd(P1_UP);
				type = WormEvent;
				break;
			}
			break;
	}
	//FALTA:: que segun el type se cree una clase del evento especifio y despues se pushee a tarves de un generic event a la lista 
	eventList.push_back(events);
}


//asume que el package es de un worm, se debe chequear antes de llamar a esta funcion que el buf[0] sea una 'W'
/*
Estructura del Worm Package: (12 chars)
buffer[0] ---> 'W' header del package
buffer[1] ---> Numero del Worm, para diferenciarlos cuando hay mas de uno
buffer[2] ---> Char del estado del Worm
buffer[3] ---> Char del Frame Counter del Worm
buffer[4] ---> Char de orientacion del Worm
buffer[5]-buffer[8] ---> uint32_t de posx del Worm
buffer[9]-buffer[12] --> uint32_t de posy del Worm
*/
void EventGenerator::shape(char * buf, unsigned int cant)
{
	if (buf[0] == 'W')
	{
		if (cant < 12)
		{
		}
		else
		{
			WormInfo newInfo;
			newInfo.wormNumber = buf[1];
			newInfo.state = buf[2];
			newInfo.frame = buf[3];
			newInfo.orientation = buf[4];
			uint32_t  * a;
			a = (uint32_t *)&buf[5];
			newInfo.posx = a[0];
			newInfo.posy = a[1];
			if (wormsList.size() == 0)
			{
				wormsList.push_back(newInfo); // si todavi ano hay ningun worm se agregar sin verficiacion
			}
			else
			{
				std::list<WormInfo>::iterator it;
				it = wormsList.begin();
				bool inserted = false;
				for (int i = 0; i < wormsList.size(); i++, it++)
				{
					if (it->wormNumber = buf[1])
					{
						wormsList.erase(it);
						wormsList.insert(it, newInfo);
						inserted = true;
					}
				}
				if (inserted == false) // signficia que no hay un worm con ese numero en la lista en el momento
				{
					wormsList.push_back(newInfo);
				}

			}
		}
	}
	else if (buf[0] == 'Q')
	{
		// se recibe package de error
		quit = true;
	}
	else if (buf == 'E')
	{
		//se recibe package de error
	}
}


/*
Little Endian --> True
Big Endian -----> False
*/
bool EventGenerator::DetectLittleEndian(void)
{
	bool returnValue = true;

	uint32_t temp = 1;

	uint32_t *ptemp = &temp;

	char firstByte = *((char *)ptemp);		//Tomo el primer byte EN MEMORIA de temp:
											//Little:	01 00 00 00
											//Big:		00 00 00 01
	if (firstByte)
	{
		returnValue = true;
	}
	else
	{
		returnValue = false;
	}

	return returnValue;
}