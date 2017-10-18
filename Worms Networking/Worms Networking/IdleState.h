#ifndef _H_IDLESTATE
#define _H_IDLESTATE

#include "GenericState.h"

class  IdleState : public GenericState
{
public:
	IdleState();
	virtual ~IdleState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);

};

#endif
