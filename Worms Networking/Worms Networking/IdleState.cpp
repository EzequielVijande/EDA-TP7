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
GenericState* IdleState::ReleaseMove(WormEvent* ev)
{
	(ev->worm)->stopMoving();
	IdleState* prox_estado = new IdleState; //No se supero el intervalo de tiempo
	return prox_estado;						//minimo para iniciar el movimiento.
}
GenericState* IdleState::PressJump(WormEvent* ev)
{
	(ev->worm)->startJumping();
	JumpingState* prox_estado = new JumpingState;
	return prox_estado;
}
