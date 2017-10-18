#include "maquina.h"

#include <boost/asio.hpp>

class client : public maquina
{
public:
	client();
	~client();
	void conect_to_host(const char* host, char* port_num);
	void read_from_port();
	void send_msg(char* bufC);
	bool read_error();
	void set_bufClen(unsigned int d);
	char* get_buf();
private:
	boost::asio::io_service* IO_handler;
	boost::asio::ip::tcp::socket* socket_forClient;
	boost::asio::ip::tcp::resolver* client_resolver;
	boost::asio::ip::tcp::resolver::iterator endpoint;
	char buf[WORM_PACKAGE_LEN];
	unsigned int bufC_len;
	bool error_flag;
};

