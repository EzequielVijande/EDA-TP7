#include "FSM.h"

	fsm::fsm()
{ 
}

void fsm:: dispatch(GenericEvent* ev)
{
	switch (ev->GetEventValue())
	{
		case EV0:
			prox_estado = estado->RunRoutine((ev0*)ev);
			break;

		case EV1:
			prox_estado = estado->RunRoutine((ev1*)ev);
			break;

		case EV2:
			prox_estado = estado->RunRoutine((ev2*)ev);
			break;

		case EV3:
			prox_estado = estado->RunRoutine((ev3*)ev);
			break;

		case EV4:
			prox_estado = estado->RunRoutine((ev4*)ev);
			break;
	}
	if (prox_estado != nullptr)
	{
		delete estado;
		estado = prox_estado;
		prox_estado= nullptr
	}
}