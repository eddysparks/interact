#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);

    seq.loadSequence("blink/", "jpg", 0, 28);
    seq.preloadAllFrames();
    seq.setFrameRate(13);
    seqFbo.allocate(seq.getWidth(), seq.getHeight(), GL_RGB);

    seqColor.allocate(seq.getWidth(), seq.getHeight());
    seqGray.allocate(seq.getWidth(), seq.getHeight());
    prevSeqGray.allocate(seq.getWidth(), seq.getHeight());
    mvtImage.allocate(seq.getWidth(), seq.getHeight());


    m.setAddress("/TRIG");
    m.addIntArg(1);
    sender.setup(HOST, PORT);
    sender2.setup(HOST2, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){


    seqFbo.begin();
        seq.getFrameForTime(ofGetElapsedTimef())->draw(0, 0);
    seqFbo.end();
    seqFbo.readToPixels(pixels);
    seqColor.setFromPixels(pixels);
    seqGray = seqColor;
    mvtImage.absDiff(prevSeqGray, seqGray);
    mvtImage.blur();
    mvtImage.dilate();
    mvtImage.threshold(80);

    mvtAmount = mvtImage.countNonZeroInRegion(0, 0, mvtImage.getWidth(), mvtImage.getHeight());
    cout<<mvtAmount<<endl;
    prevSeqGray = seqGray;

    if(mvtAmount >= 400){

        cout<<"TRIG"<<endl;


        sender.sendMessage(m);

        sender2.sendMessage(m);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    seqColor.draw(0, 0, ofGetWidth(), ofGetHeight());

    //mvtImage.draw(seq.getWidth(), 0);
    /*
    ofPushStyle();
        ofSetColor(255, 0 ,0);
        ofDrawBitmapString(ofToString(mvtAmount), 10, 500);
    ofPopStyle();
    */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
