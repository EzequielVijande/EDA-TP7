#pragma once
#include "State.h"
#include "WaitingMoveState.h"
#include "IdleState.h"
#include "JumpingState.h"
#include "MovingState.h"

class EndJumpState : public GenericState
{
public:
	EndJumpState();
	virtual ~EndJumpState();
	virtual GenericState* PressJump(WormEvent*);
	virtual GenericState* Refresh(RefreshEvent* ev);

};