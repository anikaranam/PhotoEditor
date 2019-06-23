# Development Log

**Library Used** 

*I am using openCV for image processing and manipulation. I am also using ofxGui for user input*

Week 1 - 
1. Used ofVideoGrabber to open webcam and setup the camera width and height.
2. Wrote code to save snapshot of openframeworks window
	1. When the 's' key is pressed, ofSaveFrame(true) saves a screenshot of the window to the bin/data folder of the project
3. Loaded a single image from file.
4. Having problems with setting up openCV.
	1. Crashes when running build files

Week 2 - 
1. Wrote code to load any image of user's choice
	1. Used *ofSystemLoadDialog()* to allow user to pick desired image.
2. Implemented rotation of image by any angle between 0 and 360 degrees.
3. Applied Gaussian blur on image and allowed user to choose the level of blur using a trackbar
4. Allowed user to choose between taking a photo or loading an image from file.
5. Implemented the grabcut algorithm to separate the foreground from the background for the portrait mode effect.

Week 3 -
1. Added sliders for contrast and brightness
2. Added Gaussian blur feature
3. Added slider for blurring
4. Added functionality to select a new photo
5. Added Grayscale feature
6. Added screenshot functionality

