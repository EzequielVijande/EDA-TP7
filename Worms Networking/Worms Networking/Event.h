#pragma once

//Modulo que contiene la estructura general de un evento.

enum event{PRESS_MOVE, RELEASE_MOVE, PRESS_JUMP, RELEASE_JUMP, REFRESH, QUIT};

class GenericEvent
{
public:
	virtual event GetEvent(void);
	virtual void SetEvent(event);
	virtual char GetUd(void);
	virtual void SetUd(char);

private:
	event eventType;
	char ud;
	

};