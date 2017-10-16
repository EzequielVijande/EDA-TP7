#ifndef STATE_H
#define STATE_H

//Modulo que contiene todos los estados posibles para la FSM.

class GenericState
{
public:
	GenericState();
	virtual ~GenericState();
	virtual GenericState* PressMove(WormEvent* ev)
	{
		GenericState* estado_actual = new GenericState;
		return estado_actual;
	}
	virtual GenericState* ReleaseMove(WormEvent*ev)
	{
		GenericState* estado_actual = new GenericState;
		return estado_actual;
	}
	virtual GenericState* PressJump(WormEvent*ev)
	{
		GenericState* estado_actual = new GenericState;
		return estado_actual;
	}
	virtual GenericState* ReleaseJump(WormEvent*ev)
	{
		GenericState* estado_actual = new GenericState;
		return estado_actual;
	}
	virtual	GenericState* Refresh(WormEvent*ev)
	{
		GenericState* estado_actual = new GenericState;
		return estado_actual;
	}
	virtual	GenericState* Quit(WormEvent*ev)
	{
		GenericState* estado_actual = new GenericState;
		return estado_actual;
	}
	virtual	GenericState* NoEvent(WormEvent*ev)
	{
		GenericState* estado_actual = new GenericState;
		return estado_actual;
	}

};

class  IdleState : public GenericState
{
public:
	IdleState();
	virtual ~IdleState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);


};

class  MovingState : public GenericState
{
public:
	MovingState();
	virtual ~MovingState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);


};

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

class  WaitingJumpState : public GenericState //Representa el intervalo entre el momento que se presiona
{											  //la tecla para iniciar el salto y el momento en el que inicia el salto.
public:
	WaitingJumpState();
	virtual ~WaitingJumpState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);


};

class  JumpingState : public GenericState
{
public:
	JumpingState();
	virtual ~JumpingState();
	virtual GenericState* PressMove(WormEvent* ev);
	virtual GenericState* ReleaseMove(WormEvent*ev);
	virtual GenericState* PressJump(WormEvent*ev);
	virtual GenericState* ReleaseJump(WormEvent*ev);
	virtual	GenericState* Refresh(WormEvent*ev);
	virtual	GenericState* Quit(WormEvent*ev);
	virtual	GenericState* NoEvent(WormEvent*ev);


};

#endif //STATE_H