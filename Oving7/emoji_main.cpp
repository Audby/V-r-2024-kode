#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;


int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/
	//SmilingFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre,
    //int reRadius, Point mouthC, int mouthW, int mouthH, int sDegree, int eDegree)
	
	SmilingFace mySmilingFace(Point{100,100}, 50, Point{85,90}, 10, Point{115,90}, 10, Point{100,120}, 20, 10, 360, 180);
	mySmilingFace.draw(win);

	SadFace mySadFace(Point{220,100}, 50, Point{205,90}, 10, Point{235,90}, 10, Point{220,120}, 20, 10, 0, 180);
	mySadFace.draw(win); 

	AngryFace myAngryFace(Point{340,100}, 50, Point{325,90}, 10, Point{355,90}, 10, Point{340,120}, 
	20, 10, 0, 180, Point{329,75}, Point{339,90}, Point{341,90}, Point{351,75});
	myAngryFace.draw(win);

	WinkingFace myWinkingFace(Point{460,100}, 50, Point{445,90}, 0, Point{475,90}, 10, Point{460,120}, 20, 10, 360, 180, Point{440,90}, Point{450,90});
	myWinkingFace.draw(win);

	/*SurprisedFace(Point faceCentre, int faceRadius, Point leCentre, int leRadius, Point reCentre,
    int reRadius, Point mouthC, int mouthW, int mouthH, int sDegree, int eDegree, Point lebC, Point rebC, int bW, int bH, int lbDS, int lbDE, int rbDS, int rbDE)*/

	SurprisedFace mySurprisedFace(Point{580,100}, 50, Point{565,90}, 10, Point{595,90}, 10, Point{580,120}, 20, 10, 0, 360, Point{565,80}, Point{595,80}, 20, 10, 180, 90, 0, 90);
	mySurprisedFace.draw(win);

	win.wait_for_close();

	return 0;
}
