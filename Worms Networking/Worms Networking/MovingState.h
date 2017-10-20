#pragma once

#include "State.h"
#include "WaitingMoveState.h"
#include "IdleState.h"
#include "JumpingState.h"

class  MovingState : public GenericState
{
public:
	MovingState();
	virtual ~MovingState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent* ev);
	virtual GenericState* PressJump(WormEvent* ev);

};
