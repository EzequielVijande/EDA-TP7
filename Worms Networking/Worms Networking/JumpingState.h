#pragma once

#include "State.h"
#include "WaitingMoveState.h"
#include "IdleState.h"
#include "MovingState.h"
#include "EndJumpState.h"


class  JumpingState : public GenericState
{
public:
	JumpingState();
	virtual ~JumpingState();
	virtual GenericState* ReleaseJump(WormEvent* ev);

};

