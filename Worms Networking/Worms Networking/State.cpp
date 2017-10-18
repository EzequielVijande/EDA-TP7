#include "State.h"


GenericState* GenericState::PressMove(WormEvent* ev)
{
	return nullptr;
}
GenericState* GenericState::ReleaseMove(WormEvent*ev)
{
	return nullptr;
}
GenericState* GenericState::PressJump(WormEvent*ev)
{
	return nullptr;
}
GenericState* GenericState::ReleaseJump(WormEvent*ev)
{
	return nullptr;
}

GenericState* GenericState::Refresh(RefreshEvent*ev)
{
	(ev->p2graphic)->flip_backgroundwoalpha();
	(ev->p2graphic)->flip_background();

	(ev->p2worm)->update();					//realizo refresh del worm propio de la maquina.
	(ev->p2graphic)->do_walking_step(*(ev->p2worm));
	(ev->p2graphic)->do_jumping_step(*(ev->p2worm));
	

	for (unsigned int i = 0; i < (ev->worm_number); i++, (ev->it)++) //worm_number es la cantidad de worms controlados por otras maquinas
	{												//it recorre la lista de WormInfo FALTA DEFINIR BIEN ESTE ITERADOR.
		(ev->p2graphic)->do_walking_step(*(ev->it));
		(ev->p2graphic)->do_jumping_step(*(ev->it));

	}
	
	//luego, informo a las demas maquinas sobre mi worm

	al_flip_display();

	return nullptr; //Como no cambia el estado devuelve nullptr.
}