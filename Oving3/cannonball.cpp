#include "cannonball.h"
#include "std_lib_facilities.h"
#include <cmath>
#include <vector>
#include <random>

//2a)
double acclY() {
    double aksY = -9.81;
    return aksY;
}

//2b)
double velY(double initVelocityY, double time) {
    double FartY = initVelocityY + acclY() * time;
    return FartY;

}

//2c)
double posX(double initPositionX, double initVelocityX, double time) {
    double posisjonX = initPositionX + (initVelocityX * time);
    return posisjonX;
}
double posY(double initPositionY, double initVelocityY, double time) {
    double posisjonY = initPositionY + (initVelocityY * time) + (acclY()*pow(time,2))/2;
    return posisjonY;
}

//2d)
void printTime(double time) {
    double tid = time;
    double timer=0;
    double minutter=0;
    double sekunder=0;
    while (tid>=3600) {
        timer += 1;
        tid -= 3600;
    }
    while (tid>=60) {
        minutter += 1;
        tid -= 60;
    }
    sekunder = tid;
    cout << timer << " timer, " << minutter << "minutter og " << sekunder << "sekunder." << endl;
}


//2e)
double flightTime(double initVelocityY) {
    double flytid = (-2*initVelocityY)/acclY();
    return flytid;
}

//3b)
void testDeviation(double compareOperand, double toOperand, double maxError) {
    if (compareOperand - toOperand <= maxError) {
        cout << "Tilnaermet like" << endl;
    }
    else {
        cout << "Ikke tilnaermet like" << endl;
    }
}

//4a)

//Ber brukeren om en vinkel i grader
double getUserInputTheta() {
    double theta;
    cout <<  "Oppgi verdi for teta: " << endl;
    cin >> theta;
    return theta;
}

//4b)

//Ber brukeren om en startfart
double getUserInputInitVelocity() {
    double vel;
    cout << "Oppgi en verdi for fart " << endl;
    cin >> vel;
    return vel;
}

// Konverterer fra grader til radianer
double degToRad() {
    double grad = getUserInputTheta();
    return grad * (M_PI/180);
}
// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocity() {
    double startfart = getUserInputInitVelocity();
    return startfart;
}

/*
double getVelocityX() {
    double stfart = getVelocity();
    double degr = degToRad();
    return stfart * cos(degr);
}
double getVelocityY() {
    double stfart = getVelocity();
    double degr = degToRad();
    return stfart * cos(degr);
}
*/

// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector() {
    double startfart = getVelocity();
    double degr = degToRad();
    double hastX = startfart * cos(degr);
    double hastY = startfart * sin(degr);
    cout << "X:" << hastX << " Y: " << hastY << endl;
    return {hastX, hastY};
}

double getDistanceTraveled(double velocityX, double velocityY) {
    double flight_time = flightTime(velocityY);
    return posX(0, velocityX, flight_time);
}

//4c)
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double posisjonX = getDistanceTraveled(velocityX, velocityY);
    return distanceToTarget - posisjonX;
}

