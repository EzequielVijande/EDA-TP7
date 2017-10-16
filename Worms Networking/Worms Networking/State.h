#ifndef STATE_H
#define STATE_H


class GenericState
{
public:
	GenericState();
	virtual ~GenericState();
	void virtual RunRoutine(GenericEvent*)=0;
};

#endif //STATE_H