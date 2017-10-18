#ifndef _H_WAITINGMOVESTATE
#define _H_WAITINGMOVESTATE

#include "GenericState.h"

class  WaitingMoveState : public GenericState //Representa el intervalo entre el momento que se presiona
{											  //la tecla para comenzar el movimiento y el momento en el
public:									      //efectivamente se inicia el movimiento.
	WaitingMoveState();
	virtual ~WaitingMoveState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);

};

#endif // !_H_WAITINGMOVESTATE

