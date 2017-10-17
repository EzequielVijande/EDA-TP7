#ifndef _H_MOVINGSTATE
#define _H_MOVINGSTATE

#include "GenericState.h"

class  MovingState : public GenericState
{
public:
	MovingState();
	virtual ~MovingState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);

};

#endif