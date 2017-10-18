#ifndef WORM_EVENT
#define WORM_EVENT
#include "Event.h"
#include "Worm.h"
class WormEvent : public GenericEvent
{

public:
	Worm* worm;
	WormEvent();
	WormEvent(GenericEvent evnt);
};


#endif //WORM_EVENT