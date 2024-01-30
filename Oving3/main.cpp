#include "std_lib_facilities.h"
#include "cannonball.h"
#include <cmath>
#include <vector>

void testDeviation(double compareOperand, double toOperand, double maxError);
double getDistanceTraveled(double velocityX, double velocityY);

int main() {
    
    testDeviation(posX(0.0,50.0,5.0), 250.0, 0.0001);

    //getVelocityVector();

    double distance = getDistanceTraveled(13.9, 7.2);
    cout << "Distanse: " << distance << endl;
    
    return 0;
}