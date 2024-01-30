#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball.h"
#include <cmath>
#include <vector>
#include <random>

//5b)
int randomWithLimits(int nedre, int ovre) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(nedre,ovre);
    int tilf = distribution(generator);
    return tilf;
}

//5c)
void playTargetPractice() {
    int blinkpos = randomWithLimits(100,1000);
    cout << "Målets avstand: " << blinkpos << endl;
    double angle = 0;
    double sf;
    double avst;
    double avvik;
    int i=0;
    for (i=0; i<10; i++) {
        angle = degToRad();
        sf = getUserInputInitVelocity();
        vector<double> velocityVector = getVelocityVector();
        avst = getDistanceTraveled(velocityVector[0],velocityVector[1]);
        avvik = targetPractice(blinkpos, velocityVector[0], velocityVector[1]);
        cout << "Kula landet ved: " << avst << " meter." <<endl;
        i += 1;
        if (avvik <= 5) {
            cout << "Treff!" << endl;
        }else {
            cout << "Bom!" <<endl;
        }
        
    }

}