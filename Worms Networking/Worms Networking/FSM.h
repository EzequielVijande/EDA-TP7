#ifndef FSM_H
#define FSM_H

#include "Event.h"
#include "State.h"

class fsm
{
public:
	fsm();
	~fsm();
	void dispatch(GenericEvent*);

private:
	GenericState *estado, *prox_estado;
};

#endif //FSM_H
