#ifndef _H_GENERICSTATE
#define _H_GENERICSTATE

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

#endif