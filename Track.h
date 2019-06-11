#pragma once

#include "Dimension.h"

#include "Element.h"
#include "ofMain.h"
#include "ofxGui.h"



class Track {
    public:
    
    
        void setup(int _trackNumber);
    
        void draw();
        void guiDraw();
        void setElementNumber(float &_v);
    
    
        void testRect(ofColor _c);

    
        
    
    private:
        int trackNumber, activeParameter, elementNumber;
    
    
        vector<TrackDimension> dimensions;
    
        vector<Element> elements;
        ofxPanel gui;
        ofParameterGroup parameters;
    
};
