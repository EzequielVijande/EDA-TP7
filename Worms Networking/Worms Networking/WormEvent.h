#ifndef WORM_EVENT
#define WORM_EVENT
#include "Event.h"
#include "Worm.h"
class WormEvent : public GenericEvent
{

private:
	Worm* worm;
};


#endif //WORM_EVENT