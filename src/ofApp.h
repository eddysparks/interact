#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxImageSequence.h"
#include "ofxOsc.h"


#define HOST "192.168.1.10"
#define HOST2 "127.0.0.1"
#define PORT 9000
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


    ofxImageSequence seq;
    ofFbo seqFbo;
    ofPixels pixels;
    ofxCvColorImage seqColor;
    ofxCvGrayscaleImage seqGray, prevSeqGray, mvtImage;
    int mvtAmount;
    ofxOscMessage m;
    ofxOscSender sender, sender2;


};
