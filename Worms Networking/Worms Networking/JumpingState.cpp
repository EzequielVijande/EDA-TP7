#include "JumpingState.h"
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
	}
	
}


GenericState* JumpingState::PressJump(WormEvent*ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
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
