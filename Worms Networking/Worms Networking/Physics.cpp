#include "Physics.h"
#include "Worm.h"

#include <cmath>

#define MOV 9

Physics::Physics(double gravity_, double jumpAngle_, double velocity_, double Xmax_ , double Xmin_ )
{
	gravity = gravity_;
	jumpAngle = jumpAngle_;
	velocity = velocity_;
	Xmax = Xmax_;
	Xmin = Xmin_;

}

double Physics::getGravity(void)
{
	return gravity;
}

double Physics::getJumpAngle(void)
{
	return jumpAngle;
}

double Physics::getVelocity(void)
{
	return velocity;
}

double Physics::getxMax(void)
{
	return Xmax;
}

double Physics::getxMin(void)
{
	return Xmin;
}
