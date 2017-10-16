#include "FSM.h"

	fsm::fsm()
{ 
}

void fsm:: dispatch(GenericEvent* ev)
{
	switch (ev->GetEventValue())
	{
		case EV0:
			prox_estado = estado->OnEvent0((ev0*)ev);
			break;

		case EV1:
			prox_estado = estado->OnEvent1((ev1*)ev);
			break;

		case EV2:
			prox_estado = estado->OnEvent2((ev2*)ev);
			break;

		case EV3:
			prox_estado = estado->OnEvent3((ev3*)ev);
			break;

		case EV4:
			prox_estado = estado->OnEvent4((ev4*)ev);
			break;
	}
	if (prox_estado != nullptr)
	{
		delete estado;
		estado = prox_estado;
		prox_estado= nullptr
	}
}