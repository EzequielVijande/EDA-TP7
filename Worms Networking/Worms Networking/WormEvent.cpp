#include "WormEvent.h"

WormEvent::WormEvent()
{
}

WormEvent::WormEvent(GenericEvent evnt)
{
	SetUd(evnt.GetUd());
	SetEvent(evnt.GetEvent());
}
