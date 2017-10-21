#include "FSM.h"
#include <iostream>
	fsm::fsm()
{ 
		estado = new IdleState; //Pone la FSM en su estado inicial.
		prox_estado = nullptr;
}

void fsm:: dispatch(GenericEvent* evt)
{
	event p = evt->GetEvent();
	if (p!=REFRESH)
	{
		std::cout << p << endl;
	}
	switch (evt->GetEvent())
	{
		case PRESS_MOVE:
			prox_estado = estado->PressMove((WormEvent*)evt);
			break;

		case RELEASE_MOVE:
			prox_estado = estado->ReleaseMove((WormEvent*)evt);
			break;

		case PRESS_JUMP:
			prox_estado = estado->PressJump((WormEvent*)evt);
			break;

		case RELEASE_JUMP:
			prox_estado = estado->ReleaseJump((WormEvent*)evt);
			break;

		case REFRESH:
			prox_estado = estado->Refresh((RefreshEvent*)evt);
			break;

	}
	if (prox_estado != nullptr)
	{
		delete estado;
		estado = prox_estado;
		prox_estado = nullptr;
	}
	delete evt;
}