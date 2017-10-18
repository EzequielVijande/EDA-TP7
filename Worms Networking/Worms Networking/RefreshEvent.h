#ifndef REFRESH_EVENT
#define REFRESH_EVENT
#include "Event.h"
#include "graphic_movement.h"
#include "EventGenerator.h"
class RefreshEvent : public GenericEvent
{
public:
	RefreshEvent();
	RefreshEvent(GenericEvent evnt);
	graphic_movement* p2graphic;
	Worm* p2worm;
	std::list<WormInfo>::iterator it;
	unsigned int worm_number;
	
	//Datos de Boost

	boost::asio::ip::tcp::socket* socket_;
};

#endif //REFRESH_EVENT

