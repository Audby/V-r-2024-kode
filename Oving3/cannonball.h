#include <vector>
#include "std_lib_facilities.h"
#include <cmath>

//1a)
double acclY();

//1b)
double velY(double initVelocityY, double time);

//1c)
double posX(double initPositionX, double initVelocityX, double time);
double posY(double initPositionY, double initVelocityY, double time);

//1d)
void printTime(double time);

//1e)
double flightTime(double initVelocityY);

//3b)
void testDeviation(double compareOperand, double toOperand, double maxError);

//4a)
vector<double> getVelocityVector();

//4b)
double getDistanceTraveled(double velocityX, double velocityY);

//4c)
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

