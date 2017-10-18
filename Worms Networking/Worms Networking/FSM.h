#pragma once
//Modulo que se encarga del manejo de la maquina de estados.

#include "Event.h"
#include "State.h"
#include "WormEvent.h"
#include "RefreshEvent.h"
#include "IdleState.h"
#include "MovingState.h"
#include "JumpingState.h"
#include "WaitingJumpState.h"
#include "WaitingMoveState.h"


class fsm
{
public:
	fsm();
	~fsm();
	void dispatch(GenericEvent e); //Funcion que pasa los eventos a la maquina.
								  //se encarga de pasar al proximo estado
								  //y ejecutar la rutina correspondiente.

private:
	GenericState *estado, *prox_estado;
};

