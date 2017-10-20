#include "MovingState.h"
#define END_MOVEMENT_FRAME 50
MovingState::MovingState() {};
MovingState::~MovingState() {};

GenericState* MovingState::PressMove(WormEvent* ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
	if (current_frame == END_MOVEMENT_FRAME)
	{
		(ev->worm)->startMoving();
		WaitingMoveState* estado = new WaitingMoveState;
		return estado;
	}
	else
	{
		MovingState* estado = new MovingState;
		return estado;
	}
}

GenericState* MovingState::ReleaseMove(WormEvent* ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
	if (current_frame == END_MOVEMENT_FRAME)
	{
		(ev->worm)->stopMoving();
		IdleState* estado = new IdleState;
		return estado;
	}
	else
	{
		MovingState* estado = new MovingState;
		return estado;
	}

}
GenericState* MovingState::PressJump(WormEvent* ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
	if (current_frame == END_MOVEMENT_FRAME)
	{
		(ev->worm)->stopMoving();
		(ev->worm)->startJumping();
		JumpingState* estado = new JumpingState;
		return estado;
	}
	else
	{
		MovingState* estado = new MovingState;
		return estado;
	}
}
