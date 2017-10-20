#pragma once

#include "State.h"
#include "MovingState.h"
#include "IdleState.h"
#include "JumpingState.h"

class  WaitingMoveState : public GenericState //Representa el intervalo entre el momento que se presiona
{											  //la tecla para comenzar el movimiento y el momento en el
public:									      //efectivamente se inicia el movimiento.
	WaitingMoveState();
	virtual ~WaitingMoveState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent* ev);
	virtual GenericState* PressJump(WormEvent* ev);

};

