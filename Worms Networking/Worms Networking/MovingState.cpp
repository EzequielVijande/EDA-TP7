#include "MovingState.h"
#define END_MOVEMENT_FRAME 50
MovingState::MovingState() {};
MovingState::~MovingState() {};

GenericState* MovingState::PressMove(WormEvent* ev)
{
	(ev->worm)->startMoving();
	MovingState* estado = new MovingState;
	return estado;
}

GenericState* MovingState::ReleaseMove(WormEvent* ev)
{
	unsigned int current_frame = (ev->worm)->getFrameCount();
	(ev->worm)->stopMoving();
	EndMovingState* estado = new EndMovingState;
	return estado;

}
<<<<<<< HEAD

=======
GenericState* MovingState::PressJump(WormEvent* ev)
{
	return nullptr;
}
>>>>>>> d5c16a2591c674b1d34b77ad40a801c755751617
