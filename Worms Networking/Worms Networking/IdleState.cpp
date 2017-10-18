#include "IdleState.h"

IdleState::IdleState()
{

}
IdleState::~IdleState()
{

}

GenericState* IdleState::PressMove(WormEvent* ev)
{
	(ev->worm)->startMoving();
	WaitingMoveState* prox_estado = new WaitingMoveState; //pasa al estado que monitorea cuanto tiempo se
	return prox_estado;									  //mantiene apretada la tecla.
}
GenericState* IdleState::ReleaseMove(WormEvent*ev)
{
	(ev->worm)->stopMoving();
	IdleState* prox_estado = new IdleState; //No se supero el intervalo de tiempo
	return prox_estado;						//minimo para iniciar el movimiento.
}
GenericState* IdleState::PressJump(WormEvent*ev)
{
	(ev->worm)->startJumping();
	WaitingJumpState* prox_estado = new WaitingJumpState;
	return prox_estado;
}
GenericState* IdleState::ReleaseJump(WormEvent*ev)
{
	IdleState* prox_estado = new IdleState;
	return prox_estado;
}

GenericState* IdleState::Quit(RefreshEvent*ev)
{
	//Hay que mandar el paquete avisando que se finaliza el programa
	//desde los recursos en el evento recibido.
	IdleState* prox_estado = new IdleState;
	return prox_estado;
}