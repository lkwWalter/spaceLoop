#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(255, 255, 255,0);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    int totalTrackNumber = 4;
    tracks.resize(totalTrackNumber);
    for (int i=0;i<totalTrackNumber;i++){
        tracks[i].setup(i);
    }
    selectedTrack = 0;
    newTrack();
    
}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::draw(){

   
    activeTracks[selectedTrack]->guiDraw();
    
     camView.begin();
    
    for (int i=0;i<activeTracks.size();i++){
        activeTracks[i]->draw();
    }
    camView.end();
    
}

//--------------------------------------------------------------


void ofApp::newTrack(){
    
   
    activeTracks.push_back(&tracks[trackNumber]);
    trackNumber = activeTracks.size()-1;
   // tracks[trackNumber].setup();
    
    
    
    cout << "trackNumber" << trackNumber << endl;
     cout << "trackSize" << activeTracks.size()<< endl;
}

