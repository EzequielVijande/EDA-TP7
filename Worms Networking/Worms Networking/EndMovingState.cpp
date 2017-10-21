#include "EndMovingState.h"
#define END_MOVEMENT_FRAME 50
EndMovingState::EndMovingState() {};
EndMovingState::~EndMovingState() {};

GenericState*EndMovingState::PressMove(WormEvent* ev)
{
	(ev->worm)->startMoving();
	MovingState* estado = new MovingState;
	return estado;
}

GenericState*EndMovingState::Refresh(RefreshEvent* ev)
{
	unsigned int current_frame = (ev->p2worm)->getFrameCount();

	(ev->p2graphic)->flip_backgroundwoalpha();
	(ev->p2graphic)->flip_background();

	(ev->p2worm)->update();					//realizo refresh del worm propio de la maquina.
	(ev->p2graphic)->do_walking_step(*(ev->p2worm));
	(ev->p2graphic)->do_jumping_step(*(ev->p2worm));

	/*
	for (unsigned int i = 0; i < (ev->worm_number); i++, (ev->it)++) //worm_number es la cantidad de worms controlados por otras maquinas
	{												//it recorre la lista de WormInfo FALTA DEFINIR BIEN ESTE ITERADOR.
		(ev->p2graphic)->do_walking_step(*(ev->it));
		(ev->p2graphic)->do_jumping_step(*(ev->it));

	}
	//luego, informo a las demas maquinas sobre mi worm
	char * buf = createWormPackage(ev->p2worm);
	size_t len;

	len = (ev->socket_)->write_some(boost::asio::buffer(buf, 13)); //13: tama�o del buffer.

	delete buf;
	*/

	al_flip_display();
	if (current_frame == END_MOVEMENT_FRAME) 
	{
		IdleState* estado = new IdleState;
		return estado;
	}
	else
	{
		EndMovingState* estado = new EndMovingState;
		return estado;
	}
	return nullptr; //Como no cambia el estado devuelve nullptr.
}