#include "ball.h"
#include "ofApp.h"


//--------------------------------------------------------------

Ball::Ball(float _x, float _y, float _r){
	x = _x;
	y = _y;
	radius = _r;
}

//--------------------------------------------------------------
void Ball::setup() {
	x = ofGetWidth() / 2;
	y = ofGetHeight() / 2;
	vx = abs(vx);
	inMotion = false;
}
//--------------------------------------------------------------
void Ball::draw() {
	ofSetColor(255, 130, 0);
	ofFill();
	ofDrawCircle(x, y, radius);
}

//--------------------------------------------------------------
void Ball::update() {

	if (!inMotion) return;

	x += vx * dx;
	y += vy * dy;

	if ((y >= ofGetHeight() - 10 - radius) || (y <= 0 + 10 + radius)) {
		dy *= -1;
	}

}

bool Ball::isOut(int i) {
	bool ret;
	(i == 1) ? ret=(x < 10) : ret=(x > ofGetWidth() - 10);
	return ret;
}

//--------------------------------------------------------------
void Ball::direction(int i, int j) {
	dx *= i;
	dy *= j;
}

