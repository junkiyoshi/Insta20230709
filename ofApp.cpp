#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239);
	
	ofSetLineWidth(3);
	ofNoFill();
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int span = 60;
	for (int x = -300; x <= 300; x += span) {

		for (int y = -300; y <= 300; y += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			int deg = ofMap(ofNoise(x * 0.0005, y * 0.0005, ofGetFrameNum() * 0.001), 0, 1, 0, 360 * 3);
			int deg_param = deg % 45;
			deg = deg / 45 * 45;
			if (deg_param > 40) {

				deg += ofMap(deg_param, 40, 45, 0, 45);
			}
			ofRotate(deg);

			ofBeginShape();
			for(int circle_deg = 20; circle_deg <= 360 - 20; circle_deg += 1) {
			
				ofVertex(span * 0.35 * cos(circle_deg * DEG_TO_RAD), span * 0.35 * sin(circle_deg * DEG_TO_RAD));
			}
			ofEndShape();

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}