#pragma once

#include "State.h"
#include "WaitingMoveState.h"
#include "MovingState.h"
#include "IdleState.h"
#include "JumpingState.h"

class  WaitingJumpState : public GenericState //Representa el intervalo entre el momento que se presiona
{											  //la tecla para iniciar el salto y el momento en el que inicia el salto.
public:
	WaitingJumpState();
	virtual ~WaitingJumpState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* PressJump(WormEvent* ev);
	virtual GenericState* ReleaseJump(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent* ev);

};
