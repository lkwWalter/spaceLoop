
#include "Element.h"


Element::Element(){
   
        dimensions.resize(3);
  
}


void Element::draw(){
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(dimensions[0].position*100,dimensions[1].position*100,dimensions[2].position*100);
  
    testRect();
    
    ofPopStyle();
    ofPopMatrix();
    
    
    
}



void Element::testRect(){
    ofPushStyle();
    ofFill();
    
    ofSetColor(255,0,0);
    ofDrawRectangle(0, 0, 10,10);
    ofPopStyle();
}

