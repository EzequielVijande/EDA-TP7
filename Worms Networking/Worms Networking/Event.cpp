#include "Event.h"


//Getters y Setters
event GenericEvent:: GetEvent(void)
{
	return eventType;
}

void GenericEvent::SetEvent(event type)
{
	eventType = type;
}
char GenericEvent::GetUd(void)
{
	return ud;
}
void GenericEvent::SetUd(char dir)
{
	ud = dir;
}
