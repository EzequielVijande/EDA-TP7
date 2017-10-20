#include "WaitingMoveState.h"

#define START_MOVING_FRAME 5

WaitingMoveState::WaitingMoveState() {};
WaitingMoveState::~WaitingMoveState() {};

GenericState* WaitingMoveState::PressMove(WormEvent* ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
	if (current_frame >= START_MOVING_FRAME)
	{
		MovingState* prox_estado = new MovingState;
		return prox_estado;
	}
	WaitingMoveState* prox_estado = new WaitingMoveState; 
	return prox_estado;
}

GenericState* WaitingMoveState::ReleaseMove(WormEvent* ev)
{
	(ev->worm)->stopMoving();
	IdleState* prox_estado = new IdleState; //No se llego a cumplir el lapso de tiempo necesario
	return prox_estado;
}

GenericState* WaitingMoveState::PressJump(WormEvent* ev)
{
	(ev->worm)->stopMoving();
	(ev->worm)->startJumping();
	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* WaitingMoveState::Refresh(RefreshEvent* ev)
{
	unsigned int current_frame = (ev->p2worm)->getFrameCount();
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

	if (current_frame >= START_MOVING_FRAME)
	{
		MovingState* prox_estado = new MovingState;
		return prox_estado;
	}
	else
	{
		return nullptr; //Como no cambia el estado devuelve nullptr.
	}

}

