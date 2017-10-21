#pragma once
#include "boost\asio.hpp"
#include <iostream>
#define MAX_CAPACITY 255 //maxima capacidad de los paquetes que puede manejar la maquina

#define WORM_PACKAGE_LEN 13 //tamaño del campo de datos del package del Worm.

class maquina
{
public:
	maquina();
	virtual void read_from_port() = 0;
	virtual void send_msg(char *buf) = 0;
	virtual bool read_error() = 0;
	virtual char * get_buf() = 0;
	virtual boost::asio::ip::tcp::socket* getSocket() = 0;
	virtual void conect_to_port();
	virtual void close_serverAcceptor();
	virtual void conect_to_host(const char* host, char* port_num);
	~maquina();
};


