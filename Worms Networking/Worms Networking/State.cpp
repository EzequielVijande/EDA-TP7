#include "State.h"

void Refresh(RefreshEvent*ev)
{
	(ev->p2graphic)->flip_backgroundwoalpha();
	(ev->p2graphic)->flip_background();

	(ev->p2worm)->update();					//realizo refresh del worm propio de la maquina.
	(ev->p2graphic)->do_walking_step(ev->p2worm);
	(ev->p2graphic)->do_jumping_step(ev->p2worm);


	for (unsigned int i = 0; i < cant; i++, it++) //cant representa la cantidad de worms controlados desde otras maquinas (externos)
	{												//it recorre la lista de WormInfo FALTA DEFINIR BIEN ESTE ITERADOR.
		(ev->p2graphic)->do_walking_step(it);
		(ev->p2graphic)->do_jumping_step(it);

	}
	al_flip_display();

	//no hago return (refresh no cambia ningún estado).
}