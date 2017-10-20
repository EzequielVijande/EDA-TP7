#include "JumpingState.h"
#include<iostream>
#define LAST_JUMP_FRAME 50

JumpingState::JumpingState() {};
JumpingState::~JumpingState() {};

GenericState* JumpingState::PressMove(WormEvent* ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
	if (current_frame == LAST_JUMP_FRAME)
	{
		(ev->worm)->startMoving();
		WaitingMoveState* prox_estado = new WaitingMoveState; //Si termino el salto pasa a monitor move
		return prox_estado;
	}

	else
	{
		JumpingState* prox_estado = new JumpingState; //Si no termino el salto, ignora el input.
		return prox_estado;
	}
}


GenericState* JumpingState::PressJump(WormEvent* ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
	std::cout << current_frame << std::endl;
	if (current_frame == LAST_JUMP_FRAME)
	{
		(ev->worm)->startJumping();
		JumpingState* prox_estado = new JumpingState; //Si termino el salto, inicia un  nuevo salto.
		return prox_estado;
	}

	else
	{
		JumpingState* prox_estado = new JumpingState; //Si no termino el salto, ignora el input.
		return prox_estado;
	}
}

GenericState* JumpingState::ReleaseJump(WormEvent* ev)
{
	(ev->worm)->stopJumping();
	unsigned int current_frame = (ev->worm)->getFrameCount();
	if (current_frame == LAST_JUMP_FRAME)
	{
		IdleState* prox_estado = new IdleState;
		return prox_estado;
	}
	else
	{
		JumpingState* prox_estado = new JumpingState;
		return prox_estado;
	}
	
}

GenericState* JumpingState::Refresh(RefreshEvent* ev)
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

	if (current_frame == LAST_JUMP_FRAME)
	{
		(ev->p2worm)->stopJumping();
		IdleState* prox_estado = new IdleState;
		return prox_estado;
	}
	else
	{
		return nullptr; //Como no cambia el estado devuelve nullptr.
	}
	
}
