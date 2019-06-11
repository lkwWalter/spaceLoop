#pragma once
#include "ofMain.h"




class TrackDimension{
    
public:
    
    void setup(string _dimensionName);
    ofParameter<float> offset;
    ofParameter<float> valueChange;
    ofParameter<float> layerNumber;
    string dimensionName;
   
    void offsetChange(float &v);
    float lastValue;
};


class ElementDimension{
    public:
        void setup(TrackDimension & _usedTrackDimension, int _index);
    
        void updatePosition(float &_pos);
        void factorPosition(float &_pos);
        void setTotalPosition(float &_pos);
        float  & getPosition();
    
        
      
        void setupPosition(int &_index);
    
    
    
        float relIndex, position;
        TrackDimension * trackDimension;
    

    
};
