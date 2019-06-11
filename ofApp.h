#pragma once

#include "ofMain.h"
#include "Track.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		
		void draw();

    
        void newTrack();
    
    private:
        vector<Track> tracks;
        vector<Track*> activeTracks;
        int trackNumber;
    
        int selectedTrack;
    
        ofEasyCam camView;
    
};
