#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(90);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetWindowTitle("Pong game");
	font.load("arial.ttf", 20);
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetFrameRate(60);
}

// --------------------------------------------------------------
void ofApp::update() {
	paddleLeft.update();
	paddleRight.update();
	ball.update();

	if (ball.isOut(1)) {
		ball.setup();
		scoreRight++;
	}

	if (collide(ball, paddleLeft)) {
		ball.direction(-1, 1);
	}

	if (ball.isOut(2)) {
		ball.setup();
		scoreLeft++;
	}

	if (collide(ball, paddleRight)) {
		ball.direction(-1, 1);
	}

}

// --------------------------------------------------------------
void ofApp::draw() {
	drawScene();
	paddleLeft.draw();
	paddleRight.draw();

	ball.draw();
	drawStats();
}

//--------------------------------------------------------------
void ofApp::drawScene() {
	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth() - 20, ofGetHeight() - 20);
	ofDrawLine(ofGetWidth() / 2, 10, ofGetWidth() / 2, ofGetHeight() - 10);
	// to do : how to draw ciscle with outline over the line (here not satisfying solution)
	ofFill();
	ofSetColor(0);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 36);
	ofSetColor(90);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 35);
}

//--------------------------------------------------------------
void ofApp::drawStats() {
	ofSetColor(255);

	//ofDrawBitmapString(ofToString(scoreLeft), ofGetWidth()/4, 30);
	font.drawString(ofToString(scoreLeft), ofGetWidth() / 4, 35);
	font.drawString(ofToString(scoreRight), 3 * ofGetWidth() / 4, 35);
	//font.drawString(ofToString(score), 0.90*ofGetWidth(), 20);
}


// --------------------------------------------------------------
bool ofApp::collide(Ball b, Paddle p) {
	float dx = abs(b.x - p.x);
	float dy = abs(b.y - p.y);
	return ((dx <= p.w / 2) && (dy <= p.h / 2));
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		ball.inMotion = true;
	}
	else if (key == 'z') {
		paddleRight.step = -3;
	}
	else if (key == 's') {
		paddleRight.step = 3;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if ((key == 'z') || (key == 's')) {
		paddleRight.step = 0;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	// update mouse x and y percent when the mouse moves
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
