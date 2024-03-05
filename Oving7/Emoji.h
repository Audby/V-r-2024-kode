#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

//Oppgave 3)
class Face : public Emoji {
private:
    Point centre;
    int radius;
public:
    Face(Point c, int r) : centre(c), radius(r) {}
    void draw(AnimationWindow& win) override {
        win.draw_circle(centre, radius, Color::yellow);
    }
    virtual ~Face(){};
};

class EmptyFace : public Face {
private:
    Point leftEyeCentre;
    int leftEyeRadius;
    Point rightEyeCentre;
    int rightEyeRadius;
public:
    EmptyFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre, int reRadius)
    : Face(faceCentre, faceRadius), leftEyeCentre(leCentre), leftEyeRadius(leRadius),
    rightEyeCentre(reCentre), rightEyeRadius(reRadius) {}
    void draw(AnimationWindow& win) override {
        Face ::draw(win);
        win.draw_circle(leftEyeCentre, leftEyeRadius, Color::black);
        win.draw_circle(rightEyeCentre,rightEyeRadius, Color::black);
    }
};
