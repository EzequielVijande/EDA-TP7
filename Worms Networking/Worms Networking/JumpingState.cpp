#include "JumpingState.h"
#define LAST_JUMP_FRAME 50

JumpingState::JumpingState() {};
JumpingState::~JumpingState() {};

GenericState* JumpingState::PressMove(WormEvent* ev)
{
	(ev->worm)->
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* JumpingState::ReleaseMove(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* JumpingState::PressJump(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* JumpingState::ReleaseJump(WormEvent*ev)
{
	(ev->worm)->stopJumping();
	unsigned int current_frame = (ev->worm)->getFrameCount();
	if (current_frame == 50)
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
