#include "State.h"


GenericState::GenericState()
{

}
GenericState:: ~GenericState()
{

}

GenericState* GenericState::PressMove(WormEvent* ev)
{
	return nullptr;
}
GenericState* GenericState::ReleaseMove(WormEvent*ev)
{
	return nullptr;
}
GenericState* GenericState::PressJump(WormEvent*ev)
{
	return nullptr;
}
GenericState* GenericState::ReleaseJump(WormEvent*ev)
{
	return nullptr;
}

GenericState* GenericState::Refresh(RefreshEvent*ev)
{
	(ev->p2graphic)->flip_backgroundwoalpha();
	(ev->p2graphic)->flip_background();

	(ev->p2worm)->update();					//realizo refresh del worm propio de la maquina.
	(ev->p2graphic)->do_walking_step(*(ev->p2worm));
	(ev->p2graphic)->do_jumping_step(*(ev->p2worm));
	

	for (unsigned int i = 0; i < (ev->worm_number); i++, (ev->it)++) //worm_number es la cantidad de worms controlados por otras maquinas
	{												//it recorre la lista de WormInfo FALTA DEFINIR BIEN ESTE ITERADOR.
		(ev->p2graphic)->do_walking_step(*(ev->it));
		(ev->p2graphic)->do_jumping_step(*(ev->it));

	}
	//luego, informo a las demas maquinas sobre mi worm
	char * buf = createWormPackage(ev->p2worm);
	size_t len;

	len = (ev->socket_)->write_some(boost::asio::buffer(buf, 13)); //13: tamaño del buffer.

	delete buf;

	al_flip_display();

	return nullptr; //Como no cambia el estado devuelve nullptr.
}

GenericState* GenericState::Quit(RefreshEvent*ev)
{
	//Aca hay que mandar el paquete de Quit con boost
	return nullptr;
}

/*
Estructura del Worm Package: (12 chars)
buffer[0] ---> 'W' header del package
buffer[1] ---> Numero del Worm, para diferenciarlos cuando hay mas de uno
buffer[2] ---> Char del estado del Worm
buffer[3] ---> Char del Frame Counter del Worm
buffer[4] ---> Char de orientacion del Worm
buffer[5]-buffer[8] ---> uint32_t de posx del Worm
buffer[9]-buffer[12] --> uint32_t de posy del Worm
*/

char * GenericState::createWormPackage(Worm * p2worm)
{
	char * package = new char [13]; //13: tamaño del wormPackage
	package[0] = 'W';
	package[1] = p2worm->getNumber();
	package[2] = p2worm->getSentido();
	package[3] = (char)p2worm->getFrameCount();
	package[5] = (uint32_t)p2worm->getPos().x;
	package[9] = (uint32_t)p2worm->getPos().y;

	if (p2worm->getSentido()) //getSentido devuelve un bool
	{
		package[4] = 1;
	}
	else
	{
		package[4] = 0;
	}
	return package;
}