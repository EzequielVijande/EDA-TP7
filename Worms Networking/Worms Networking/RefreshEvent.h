#ifndef REFRESH_EVENT
#define REFRESH_EVENT
#include "Event.h"
#include "Output.h"

class RefreshEvent : public GenericEvent
{
private:
	Graphic* viewer;

	//Datos de Boost
	char buf[512];
	char sequence[255];

	boost::asio::io_service*  IO_handler;
	boost::asio::ip::tcp::socket* socket_forServer;
	boost::asio::ip::tcp::acceptor* server_acceptor;
};

#endif //REFRESH_EVENT