#pragma once
#include "State.h"
#include "WaitingMoveState.h"
#include "IdleState.h"
#include "JumpingState.h"
#include "MovingState.h"

class EndMovingState : public GenericState
{
public:
	EndMovingState();
	   virtual ~EndMovingState();
	   virtual GenericState* PressMove(WormEvent* ev);
	   virtual GenericState* Refresh(RefreshEvent* ev);
};

