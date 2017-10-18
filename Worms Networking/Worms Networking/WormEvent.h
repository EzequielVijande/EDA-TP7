#pragma once
#include "Event.h"
#include "Worm.h"
class WormEvent : public GenericEvent
{

public:
	Worm* worm;
	WormEvent();
	WormEvent(GenericEvent evnt);
};
