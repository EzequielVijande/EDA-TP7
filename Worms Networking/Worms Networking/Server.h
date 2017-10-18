#pragma once
#include "maquina.h"

#include <boost/asio.hpp>

class server : public maquina
{
public:
	server(unsigned int port_num);
	~server();
	void conect_to_port();
	void read_from_port();
	void send_msg(char *bufS);
	bool read_error();
	void set_bufSlen(unsigned int d);
	void close_serverAcceptor();
	char* get_buf();
	boost::asio::ip::tcp::socket* getSocket(void);
private:
	boost::asio::io_service*  IO_handler;
	boost::asio::ip::tcp::socket* socket_forServer;
	boost::asio::ip::tcp::acceptor* server_acceptor;

	char buf[WORM_PACKAGE_LEN];
	unsigned int bufS_len;
	bool error_flag;
};