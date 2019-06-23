# OpenFrameworks Photo Editor

*Convert an image to portrait mode, increase or decrease contrast and brightness of the image*

1. User can choose to take a new photo or choose from a pre-saved image
	1. If user chooses to take a photo, application opens the webcam and takes a snapshot, saves it to the data folder
	2. Pre-saved images are loaded from the data folder of the application
3. User is then given the choice between altering the contrast, brightness, or converting to portrait mode
4. Portrait mode - foreground and background are separated and background is blurred
5. A trackbar is used to increase or decrease contrast and brightness


Libraries used : openCV, ofxGui

openCV is used for image manipulation and processing
ofxGui is used for accepting user input

https://openframeworks.cc/documentation/ofxGui/
https://docs.opencv.org/3.4.0/d9/df8/tutorial_root.html