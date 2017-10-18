#ifndef _H_IDLESTATE
#define _H_IDLESTATE

#include "State.h"
#include "JumpingState.h"
#include "WaitingMoveState.h"
#include "WaitingJumpState.h"
#include "WormEvent.h"
#include "RefreshEvent.h"

class  IdleState : public GenericState
{
public:
	IdleState();
	virtual ~IdleState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
private:
	

};

#endif
