#include "WaitingMoveState.h"

WaitingMoveState::WaitingMoveState() {};
WaitingMoveState::~WaitingMoveState() {};

GenericState* WaitingMoveState::PressMove(WormEvent* ev)
{
	//Fijarse si se cumplio el lapso de tiempo necesario
	//cambia a moving o sigue igual.
	return ev;
}

GenericState* WaitingMoveState::ReleaseMove(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	IdleState* prox_estado = new IdleState; //No se llego a cumplir el lapso de tiempo necesario
	return prox_estado;
}

GenericState* WaitingMoveState::PressJump(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	WaitingJumpState* prox_estado = new WaitingJumpState;
	return prox_estado;
}

GenericState* WaitingMoveState::ReleaseJump(WormEvent*ev)
{
	IdleState* prox_estado = new IdleState; //no deberia poder recibirse este evento desde WaitingMove.
	return prox_estado;
}

GenericState* WaitingMoveState::NoEvent(WormEvent*ev)
{
	IdleState* prox_estado = new IdleState; //no deberia poder recibirse este evento desde WaitingMove.
	return prox_estado;
}