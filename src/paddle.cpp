#include "Paddle.h"
#include "ofApp.h"


//--------------------------------------------------------------
Paddle::Paddle(float _x, float _y, float _w, float _h) {
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

//--------------------------------------------------------------
void Paddle::update() {

	(x > ofGetWidth()/2) ? y += step: y = ofGetMouseY();  
	if (y > ofGetHeight() - 10 - h/2) {
		y = ofGetHeight() - 10 - h/2;
	}
	else if (y < 10 + h/2) {
		y = 10 + h/2;
	}
}


//--------------------------------------------------------------
void Paddle::draw() {
	ofSetColor(255, 255, 0);
	ofFill();
	ofDrawRectangle(x, y, w, h);  
}

