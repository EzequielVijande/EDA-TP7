#include "JumpingState.h"

JumpingState::JumpingState() {};
JumpingState::~JumpingState() {};

GenericState* JumpingState::PressMove(WormEvent* ev)
{
	return ev;
}

GenericState* JumpingState::ReleaseMove(WormEvent*ev)
{
	return ev;
}

GenericState* JumpingState::PressJump(WormEvent*ev)
{
	return ev;
}

GenericState* JumpingState::ReleaseJump(WormEvent*ev)
{
	return ev;
}

GenericState* JumpingState::NoEvent(WormEvent*ev)
{
	return ev;
}