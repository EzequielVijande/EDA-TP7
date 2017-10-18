#include "WaitingMoveState.h"

WaitingMoveState::WaitingMoveState() {};
WaitingMoveState::~WaitingMoveState() {};

GenericState* WaitingMoveState::PressMove(WormEvent* ev)
{
	return ev;
}

GenericState* WaitingMoveState::ReleaseMove(WormEvent*ev)
{
	return ev;
}

GenericState* WaitingMoveState::PressJump(WormEvent*ev)
{
	return ev;
}

GenericState* WaitingMoveState::ReleaseJump(WormEvent*ev)
{
	return ev;
}

GenericState* WaitingMoveState::NoEvent(WormEvent*ev)
{
	return ev;
}