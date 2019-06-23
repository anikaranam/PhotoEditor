#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void buttonPressed();
		void guiSetup();
		void modify();
		void addBlur();
		
		Mat image;
		Mat new_image;
		Mat image3;
		Mat image4;
		ofxFloatSlider contrastValue;
		ofxFloatSlider brightnessValue;
		ofxFloatSlider angleVal;
		ofxFloatSlider blurVal;
		ofParameter<bool> blurBool;
		ofParameter<bool> switcher;
		ofxButton button;

		ofVideoGrabber cam;
		ofTrueTypeFont text;

		ofxPanel gui;
		
};
