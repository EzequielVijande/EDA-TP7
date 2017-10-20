#pragma once

//Modulo que contiene todos los estados posibles para la FSM.
#include "WormEvent.h"
#include "RefreshEvent.h"

class RefreshEvent; //foward declaration para que no haya problemas de referencia circular

class GenericState
{
public:
	virtual ~GenericState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent* ev);
	virtual GenericState* PressJump(WormEvent* ev);
	virtual GenericState* ReleaseJump(WormEvent* ev);
	virtual GenericState* Refresh(RefreshEvent* ev);
	virtual	GenericState* Quit(RefreshEvent* ev);
private:
	char * createWormPackage(Worm * p2worm);
};
