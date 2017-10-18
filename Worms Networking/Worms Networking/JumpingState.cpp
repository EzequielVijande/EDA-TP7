#include "JumpingState.h"

JumpingState::JumpingState() {};
JumpingState::~JumpingState() {};

GenericState* JumpingState::PressMove(WormEvent* ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* JumpingState::ReleaseMove(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* JumpingState::PressJump(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* JumpingState::ReleaseJump(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}

GenericState* JumpingState::NoEvent(WormEvent*ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}