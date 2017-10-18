#ifndef _H_JUMPINGSATE
#define _H_JUMPINGSTATE

#include "State.h"
#include "WaitingMoveState.h"
#include "IdleState.h"
#include "MovingState.h"


class  JumpingState : public GenericState
{
public:
	JumpingState();
	virtual ~JumpingState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);

};

#endif // !_H_JUMPINGSATE
