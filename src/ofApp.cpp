#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    
   // vidGrabber.initGrabber(320, 240);
    colorImg.allocate(320, 240);
    grayImg.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);
    
    threshold = 80;
    mLearnBackground = true;
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
   // vidGrabber.update();
    
      if(kinect.isFrameNew()){
        brightPoints.clear();
        kinect.getPixels().mirror(false, true);
        ofVec2f point = ofVec2f(0,0);
          ofxCvColorImage temp;
          temp.setFromPixels(kinect.getPixels());
          temp.resize(320, 240);
          colorImg = temp;
        
        grayImg = colorImg;
        brightness = 245;
        for(int i = 0 ; i < grayImg.width; i+=10){
            for(int j = 0 ; j < grayImg.height; j+=10){
                float tempBrt = grayImg.getPixels().getColor(i, j).getBrightness();
                if(tempBrt >= brightness){
                    brightness = tempBrt;
                    point.x = i;
                    point.y = j;
                    brightPoints.push_back(point);
                    cout << brightness <<endl;
                }
            }
        }
}
    
    
    //contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    kinect.draw(20, 20);
    
    ofSetColor(30);
    ofDrawRectangle(0,500 , 320, 240);
    for(int i = 0; i < brightPoints.size();i++){
        ofSetColor(255, 0, 0);
        ofDrawCircle(brightPoints[i]+ofVec2f(0, 500), 3);
    }
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
