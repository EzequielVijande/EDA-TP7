#ifndef STATE_H
#define STATE_H

enum State{IDLE, W_WAIT, J_WAIT, WALKING, JUMPING, LISTENING};

class GenericState
{
public:
	GenericState();
	virtual ~GenericState();
	virtual GenericState* OnEvent0(ev0*)
	{
		return this;
	}
	virtual GenericState* OnEvent1(ev1*)
	{
		return this;
	}
	virtual GenericState* OnEvent2(ev2*)
	{
		return this;
	}
	virtual GenericState* OnEvent3(ev3*)
	{
		return this;
	}
	virtual	GenericState* OnEvent4(ev4*)
	{
		return this;
	}

};

#endif //STATE_H