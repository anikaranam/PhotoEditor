#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

// Sources
//  http://opencvexamples.blogspot.com/2014/01/rotate-image.html
//  https://docs.opencv.org/3.4.2/d3/dc1/tutorial_basic_linear_transform.html

double contrast; // contrast value
int brightness;  // brightness value+
int rotateAngle; // angle of rotation

int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

std::string path = "messi1.jpg";

// function to rotate by specified angle
Mat rotate(Mat src, double angle) {
    Mat dst;
    Point2f pt(src.cols/2., src.rows/2.);    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(src, dst, r, Size(src.cols, src.rows));
    return dst;
}

void ofApp::guiSetup() {

    // font size and type
    text.load("arial.ttf", 16);

    // setting up gui
    gui.setup();

    // contrast slider
    gui.add(contrastValue.setup("contrast", 1.0, 0.1, 3.0));

    // brightness slider
    gui.add(brightnessValue.setup("brightness", 0, 10, 100));

    // angle slider
    gui.add(angleVal.setup("rotate angle", 0, 10, 360));
    
    // grayscale button
    gui.add(switcher.set("Black and white", false));
    
    // blur slider
    gui.add(blurVal.setup("extent of blur", 0, 1, 50));
    
    // blur button
    gui.add(blurBool.set("Blur image", false));

    // take Photo button
    gui.add(button.setup("take new photo"));

}

void ofApp::modify() {
    // change contrast and brightness
    for( int y = 0; y < image.rows; y++ ) { 
        for( int x = 0; x < image.cols; x++ ) {
            for( int c = 0; c < 3; c++ ) {
                new_image.at<Vec3b>(y,x)[c] =
                saturate_cast<uchar>( contrast*( image.at<Vec3b>(y,x)[c] ) + brightness );
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::setup(){

    guiSetup();

    // loading initial image
    ofFileDialogResult result = ofSystemLoadDialog("Load image file");
        if (result.bSuccess) {
            path = result.getPath();
            image = imread(path);
        }

    new_image = Mat::zeros( image.size(), image.type() );

    // setting initial values of contrast and brightness
    contrast = 1.0;
    brightness = 50;
    rotateAngle = 0;
     
    modify();

}

void ofApp::addBlur() {

    // adding Gaussian blur
    if (blurBool == true) {
        MAX_KERNEL_LENGTH = blurVal;
        for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ) { 
            GaussianBlur( image3, image4, Size( i, i ), 0, 0 ); 
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){

    contrast = contrastValue;
    brightness = brightnessValue;
    rotateAngle = angleVal;

    modify();

    new_image = rotate(new_image, rotateAngle);

    // converting to grayscale
    if (switcher == true) {
        cvtColor(new_image, image3, CV_BGR2GRAY);
    } else {
        image3 = new_image;
    }
    

    image4 = image3;
    
    addBlur();

    // adding functionality to take photo button
    button.addListener(this, &ofApp::buttonPressed);

}

//--------------------------------------------------------------
void ofApp::draw(){
    // load desired image
    drawMat(image4, 0, 0, 1024, 768);
    
    // add gui elements
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // take screenshot and save to bin/data folder
    if (key == 's') {
        ofSaveFrame(true);
    }
}

void ofApp::buttonPressed() {
    // recall setup to load new image
    setup();
}
