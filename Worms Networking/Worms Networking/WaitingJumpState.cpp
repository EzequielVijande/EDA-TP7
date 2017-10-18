#include "WaitingJumpState.h"

WaitingJumpState::WaitingJumpState() {};
WaitingJumpState::~WaitingJumpState() {};

GenericState* WaitingJumpState::PressMove(WormEvent* ev)
{
	WaitingMoveState* prox_estado = new JumpingState; //Si no termino el salto, ignora el input.
	return prox_estado;
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