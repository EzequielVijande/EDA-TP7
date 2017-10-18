#ifndef _H_JUMPINGSATE
#define _H_JUMPINGSTATE

#include "GenericState.h"

class  JumpingState : public GenericState
{
public:
	JumpingState();
	virtual ~JumpingState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);

};

#endif // !_H_JUMPINGSATE
