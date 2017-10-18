#ifndef EVENT_H
#define EVENT_H

//Modulo que contiene la estructura general de un evento.

enum event{PRESS_MOVE, RELEASE_MOVE, PRESS_JUMP, RELEASE_JUMP, REFRESH, QUIT};

class GenericEvent
{
public:
	GenericEvent();
	virtual ~GenericEvent();
	virtual event GetEvent(void);
	virtual void SetEvent(event);
	virtual char GetUd(void);
	virtual void SetUd(char);

private:
	event eventType;
	char ud;
	

};

#endif //EVENT_H