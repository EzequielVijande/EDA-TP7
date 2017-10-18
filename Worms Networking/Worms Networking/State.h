#ifndef STATE_H
#define STATE_H

//Modulo que contiene todos los estados posibles para la FSM.

class GenericState
{
public:
	GenericState();
	virtual ~GenericState();
	virtual GenericState* PressMove(WormEvent* ev) = 0;
	virtual GenericState* ReleaseMove(WormEvent*ev) = 0;
	virtual GenericState* PressJump(WormEvent*ev) = 0;
	virtual GenericState* ReleaseJump(WormEvent*ev) = 0;
	virtual	GenericState* Refresh(WormEvent*ev) = 0;
	virtual	GenericState* Quit(WormEvent*ev) = 0;
	virtual	GenericState* NoEvent(WormEvent*ev) = 0;
};


#endif //STATE_H