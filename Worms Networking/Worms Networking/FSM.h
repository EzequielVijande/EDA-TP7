#ifndef FSM_H
#define FSM_H
//Modulo que se encarga del manejo de la maquina de estados.

#include "Event.h"
#include "State.h"

class fsm
{
public:
	fsm();
	~fsm();
	void dispatch(GenericEvent*); //Funcion que pasa los eventos a la maquina.
								  //se encarga de pasar al proximo estado
								  //y ejecutar la rutina correspondiente.

private:
	GenericState *estado, *prox_estado;
};

#endif //FSM_H
