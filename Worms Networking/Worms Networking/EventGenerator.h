#ifndef EVENT_GENERATOR_H
#define EVENT_GENERATOR_H

#include "Event.h"
#include <list>

class EventGenerator
{
public:
	EventGenerator();
	~EventGenerator();
	void SearchForEvents();

private:
	std::list<GenericEvent> EventList;

};

#endif //EVENT_GENERATOR_H