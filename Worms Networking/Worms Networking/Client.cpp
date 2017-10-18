#include "stdafx.h"
#include "Client.h"
#include <iostream>

enum { ANIM, COUNT };

using namespace std;

client::client()
{
	IO_handler = new boost::asio::io_service();
	socket_forClient = new boost::asio::ip::tcp::socket(*IO_handler);
	client_resolver = new boost::asio::ip::tcp::resolver(*IO_handler);
	cout << "--> Cliente creado exitosamente" << endl;
	error_flag = false;
	bufC_len = 0;
}


client::~client()
{
	socket_forClient->close();
	delete client_resolver;
	delete socket_forClient;
	delete IO_handler;
}

void client::conect_to_host(const char * host, char* port_num)
{
	endpoint = client_resolver->resolve(
		boost::asio::ip::tcp::resolver::query(host, port_num));
	cout << "--> Intentando conectarse a " << host << " en el puerto " << port_num << std::endl;
	boost::asio::connect(*socket_forClient, endpoint);
	socket_forClient->non_blocking(true);
	cout << "--> Conexion a host exitosa" << endl;
}

void client::read_from_port()
{
	boost::system::error_code error;
	size_t len;
	cout << "--> Esperando mensaje de servidor..." << endl;
	do
	{
		len = socket_forClient->read_some(boost::asio::buffer(buf), error);

		if (!error) {
			buf[len] = '\0';
			bufC_len = len;
		}


	} while (error.value() == WSAEWOULDBLOCK);

	if (!error)
	{
		//HAGO ALGO
	}
	else
	{

		cout << "--> Error al intentar conectarse a servidor " << error.message() << endl;
	}
}

void client::send_msg(char* bufC)
{
	char buf_aux[MAX_CAPACITY];
	unsigned int i = 0;
	while (i < bufC_len)
	{
		buf_aux[i] = bufC[i];
		i++;
	}
	buf_aux[i] = '\0';
	size_t len;
	boost::system::error_code error;

	do
	{
		len = socket_forClient->write_some(boost::asio::buffer(buf_aux, i), error);
	} while ((error.value() == WSAEWOULDBLOCK));
	if (error)
		cout << "--> Error al intentar conectarse a servidor " << error.message() << endl;
}

bool client::read_error()
{
	return error_flag;
}

void client::set_bufClen(unsigned int d)
{
	bufC_len = d;
}

char * client::get_buf()
{
	return buf;
}
