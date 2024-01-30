#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#include <cmath>
#include <vector>
#include <random>

void testDeviation(double compareOperand, double toOperand, double maxError);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
int randomWithLimits(int nedre, int ovre);
void playTargetPractice();

int main() {
    
    testDeviation(posX(0.0,50.0,5.0), 250.0, 0.0001);

    //getVelocityVector();

    double distance = getDistanceTraveled(13.9, 7.2);
    cout << "Distanse: " << distance << endl;

    double avvik = targetPractice(25.00, 13.9,7.2);
    cout << "Avvik: " << avvik << endl;
    
    int tilftall = randomWithLimits(0,10);
    cout << tilftall << endl;

    playTargetPractice();

    return 0;
}