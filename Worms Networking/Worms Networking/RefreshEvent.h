#pragma once

#include "graphic_movement.h"
#include "EventGenerator.h"
#include "Event.h"

class RefreshEvent : public GenericEvent
{
public:
	RefreshEvent();
	RefreshEvent(GenericEvent evnt);
	graphic_movement* p2graphic;
	Worm* p2worm;
	std::list<WormInfo>::iterator it;
	unsigned int worm_number;
	
};


