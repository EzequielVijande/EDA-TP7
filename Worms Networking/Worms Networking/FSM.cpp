#include "FSM.h"

	fsm::fsm()
{ 
		estado = new IdleState; //Pone la FSM en su estado inicial.
		prox_estado = nullptr;
}

void fsm:: dispatch(GenericEvent* ev)
{
	switch (ev->GetEvent())
	{
		case PRESS_MOVE:
			prox_estado = estado->PressMove((WormEvent*)ev);
			break;

		case RELEASE_MOVE:
			prox_estado = estado->ReleaseMove((WormEvent*)ev);
			break;

		case PRESS_JUMP:
			prox_estado = estado->PressJump((WormEvent*)ev);
			break;

		case RELEASE_JUMP:
			prox_estado = estado->ReleaseJump((WormEvent*)ev);
			break;

		case REFRESH:
			estado->Refresh((RefreshEvent*)ev);
			break;
		case QUIT:
			prox_estado = estado->Quit((RefreshEvent*)ev);
			break;

	}
	if (prox_estado != nullptr)
	{
		delete estado;
		estado = prox_estado;
		prox_estado = nullptr;
	}
}