#include "JumpingState.h"
#include<iostream>
#define LAST_JUMP_FRAME 50

JumpingState::JumpingState() {};
JumpingState::~JumpingState() {};


GenericState* JumpingState::ReleaseJump(WormEvent* ev)
{
	(ev->worm)->stopJumping();
	EndJumpState* estado = new EndJumpState;
	return estado;
	
}

