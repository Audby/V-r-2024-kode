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

class SmilingFace : public EmptyFace {
private:
    Point mouthCentre;
    int mouthWidth;
    int mouthHeight;
    int startDegree;
    int endDegree;
public:
    SmilingFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre,
    int reRadius, Point mouthC, int mouthW, int mouthH, int sDegree, int eDegree)
    : EmptyFace(faceCentre, faceRadius, leCentre, leRadius, reCentre, reRadius), mouthCentre(mouthC),
    mouthWidth(mouthW), mouthHeight(mouthH), startDegree(sDegree), endDegree(eDegree) {}

    void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_arc(mouthCentre, mouthWidth, mouthHeight, startDegree, endDegree, Color::black);
    }
};

class SadFace : public EmptyFace {
private:
    Point mouthCentre;
    int mouthWidth;
    int mouthHeight;
    int startDegree;
    int endDegree;
public:
    SadFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre,
    int reRadius, Point mouthC, int mouthW, int mouthH, int sDegree, int eDegree)
    : EmptyFace(faceCentre, faceRadius, leCentre, leRadius, reCentre, reRadius), mouthCentre(mouthC),
    mouthWidth(mouthW), mouthHeight(mouthH), startDegree(sDegree), endDegree(eDegree) {}

    void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_arc(mouthCentre, mouthWidth, mouthHeight, startDegree, endDegree, Color::black);
    }
};

class AngryFace : public EmptyFace {
private:
    Point mouthCentre;
    int mouthWidth;
    int mouthHeight;
    int startDegree;
    int endDegree;
    Point leftEyeBrowStart;
    Point leftEyeBrowEnd;
    Point rightEyeBrowStart;
    Point rightEyeBrowEnd;
public:
    AngryFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre, 
    int reRadius, Point mouthC, int mouthW, int mouthH, int sDegree, int eDegree, Point lebStart, Point lebEnd, Point rebStart, Point rebEnd)
    : EmptyFace(faceCentre, faceRadius, leCentre, leRadius, reCentre, reRadius), mouthCentre(mouthC),
    mouthWidth(mouthW), mouthHeight(mouthH), startDegree(sDegree), endDegree(eDegree), leftEyeBrowStart(lebStart), leftEyeBrowEnd(lebEnd),
     rightEyeBrowStart(rebStart), rightEyeBrowEnd(rebEnd) {}

    void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_arc(mouthCentre, mouthWidth, mouthHeight, startDegree, endDegree, Color::black);
        win.draw_line(leftEyeBrowStart, leftEyeBrowEnd, Color::black);
        win.draw_line(rightEyeBrowStart, rightEyeBrowEnd, Color::black);
    }
};

class WinkingFace : public EmptyFace {
private:
    Point mouthCentre;
    int mouthWidth;
    int mouthHeight;
    int startDegree;
    int endDegree;
    Point leftBlinkStart;
    Point leftBlinkEnd;
public:
    WinkingFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre, 
    int reRadius, Point mouthC, int mouthW, int mouthH, int sDegree, int eDegree, Point lebStart, Point lebEnd)
    : EmptyFace(faceCentre, faceRadius, leCentre, leRadius, reCentre, reRadius), mouthCentre(mouthC),
    mouthWidth(mouthW), mouthHeight(mouthH), startDegree(sDegree), endDegree(eDegree), leftBlinkStart(lebStart), leftBlinkEnd(lebEnd) {}

    void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_arc(mouthCentre, mouthWidth, mouthHeight, startDegree, endDegree, Color::black);
        win.draw_line(leftBlinkStart, leftBlinkEnd, Color::black);
    }
};

class SurprisedFace : public EmptyFace {
private:
    Point mouthCentre;
    int mouthWidth;
    int mouthHeight;
    int startDegree;
    int endDegree;
    Point leftEyeBrowCentre;
    Point rightEyeBrowCentre;
    int browWidth;
    int browHeight;
    int LeftBrowDegreeStart;
    int LeftBrowDegreeEnd;
    int RightBrowDegreeStart;
    int RightBrowDegreeEnd;
public:
    SurprisedFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre,
    int reRadius, Point mouthC, int mouthW, int mouthH, int sDegree, int eDegree, Point lebC, Point rebC, int bW, int bH, int lbDS, int lbDE, int rbDS, int rbDE)
    : EmptyFace(faceCentre, faceRadius, leCentre, leRadius, reCentre, reRadius), mouthCentre(mouthC),
    mouthWidth(mouthW), mouthHeight(mouthH), startDegree(sDegree), endDegree(eDegree), leftEyeBrowCentre(lebC), rightEyeBrowCentre(rebC), browWidth(bW), browHeight(bH),
    LeftBrowDegreeStart(lbDS), LeftBrowDegreeEnd(lbDE), RightBrowDegreeStart(rbDS), RightBrowDegreeEnd(rbDE) {}

    void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_arc(mouthCentre, mouthWidth, mouthHeight, startDegree, endDegree, Color::black);
        win.draw_arc(leftEyeBrowCentre, browWidth, browHeight, LeftBrowDegreeStart, LeftBrowDegreeEnd, Color::black);
        win.draw_arc(rightEyeBrowCentre, browWidth, browHeight, RightBrowDegreeStart, RightBrowDegreeEnd, Color::black);
    }
};

    