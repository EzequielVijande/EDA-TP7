#include "MovingState.h"

MovingState::MovingState() {};
MovingState::~MovingState() {};

GenericState* MovingState::PressMove(WormEvent* ev)
{
	return ev;
}

GenericState* MovingState::ReleaseMove(WormEvent*ev)
{
	return ev;
}

GenericState* MovingState::PressJump(WormEvent*ev)
{
	return ev;
}

GenericState* MovingState::ReleaseJump(WormEvent*ev)
{
	return ev;
}

GenericState* MovingState::NoEvent(WormEvent*ev)
{
	return ev;
}