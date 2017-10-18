#include "IdleState.h"

IdleState::IdleState()
{

}
IdleState::~IdleState()
{

}

GenericState* IdleState::PressMove(WormEvent* ev)
{
	//Falta llamar a las funciones de worm
	//desde el worm que se recibe en el evento.

	WaitingMoveState* prox_estado = new WaitingMoveState;
	return prox_estado;
}
GenericState* IdleState::ReleaseMove(WormEvent*ev)
{
	IdleState* prox_estado = new IdleState; //No se supero el intervalo de tiempo
	return prox_estado;						//minimo para iniciar el movimiento.
}
GenericState* IdleState::PressJump(WormEvent*ev)
{
	WaitingJumpState* prox_estado = new WaitingJumpState;
	return prox_estado;
}
GenericState* IdleState::ReleaseJump(WormEvent*ev)
{
	IdleState* prox_estado = new IdleState;
	return prox_estado;
}
GenericState* IdleState::Refresh(WormEvent*ev)
{
	//Queda ver bien como hacer esta cuando ya este el output bien definido
}
GenericState* IdleState::Quit(WormEvent*ev)
{
	//Hay que mandar el paquete avisando que se finaliza el programa
	//desde los recursos en el evento recibido.
	IdleState* prox_estado = new IdleState;
	return prox_estado;
}
GenericState* IdleState::NoEvent(WormEvent*ev)
{
	IdleState* prox_estado = new IdleState;
	return prox_estado;
}