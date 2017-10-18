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

GenericState* WaitingMoveState::ReleaseMove(WormEvent*ev)
{
	(ev->worm)->stopMoving();
	IdleState* prox_estado = new IdleState; //No se llego a cumplir el lapso de tiempo necesario
	return prox_estado;
}

GenericState* WaitingMoveState::PressJump(WormEvent*ev)
{
	(ev->worm)->stopMoving();
	(ev->worm)->startJumping();
	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

