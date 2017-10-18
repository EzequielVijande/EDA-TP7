
#ifndef STATE_H
#define STATE_H

//Modulo que contiene todos los estados posibles para la FSM.
#include "WormEvent.h"
#include "RefreshEvent.h"

class GenericState
{
public:
	GenericState();
	virtual ~GenericState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual GenericState* Refresh(RefreshEvent*ev);
	virtual	GenericState* Quit(RefreshEvent*);
};


#endif //STATE_H