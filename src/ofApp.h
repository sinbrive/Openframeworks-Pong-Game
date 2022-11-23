#pragma once

#include "ofMain.h"
#include "ball.h"
#include "paddle.h"

class ofApp : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	bool collide(Ball b, Paddle p);
	void drawScene();
	void drawStats();

	int scoreLeft = 0;
	int scoreRight = 0;

	Ball ball = Ball(ofGetWidth()/2, ofGetHeight()/2, 10.0);
	Paddle paddleLeft = Paddle(25, ofGetHeight() / 2, 10, 80);
	Paddle paddleRight = Paddle(ofGetWidth() - 10 - 10 - 5, ofGetHeight() / 2, 10, 80);

	ofTrueTypeFont font;
};