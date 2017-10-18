#include "WaitingJumpState.h"

WaitingJumpState::WaitingJumpState() {};
WaitingJumpState::~WaitingJumpState() {};

GenericState* WaitingJumpState::PressMove(WormEvent* ev)
{
	return ev;
}

GenericState* WaitingJumpState::ReleaseMove(WormEvent*ev)
{
	return ev;
}

GenericState* WaitingJumpState::PressJump(WormEvent*ev)
{
	return ev;
}

GenericState* WaitingJumpState::ReleaseJump(WormEvent*ev)
{
	return ev;
}

GenericState* WaitingJumpState::NoEvent(WormEvent*ev)
{
	return ev;
}