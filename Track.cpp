#include "Track.h"



void Track::setup(int _trackNumber){
    
   
    trackNumber = _trackNumber;
    
    activeParameter = 0;
    
    gui.setup("track" + ofToString(trackNumber));
    parameters.setName("all");
   
    
   
    dimensions.resize(3);
    string dimensionName[3] = {" X"," Y"," Z"};
    for( int i=0; i<3 ; i++){
       dimensions[i].setup(dimensionName[i]);
        parameters.add(dimensions[i].offset);
        parameters.add(dimensions[i].layerNumber);
     }
 
    gui.add(parameters);
    gui.setPosition(300,0);
    gui.setDefaultWidth(200);
    
    for(int i=0;i<3;i++){
        dimensions[i].layerNumber.addListener(this, &Track::setElementNumber);
    }
    
    float v =0;
    setElementNumber(v);
}





void Track::guiDraw(){
    gui.draw();
    
}


void Track::draw(){
    
    for (int i=0;i<elements.size();i++){
        elements[i].draw();
        
        
    }
}


void Track::setElementNumber(float &_v){
   
  
    elements.clear();
    int layerNumber[3] = {(int)dimensions[0].layerNumber,(int)dimensions[1].layerNumber,(int)dimensions[2].layerNumber};
    int x,y,z;
  //  vector<int> *index = {&x,&y,&z};
    int *index[3] = {&x,&y,&z};
  //for all dimensions in space
    for(x= 0;x<layerNumber[0];x++){
        for(y = 0;y<layerNumber[1];y++){
            for(z= 0;z<layerNumber[2];z++){
                Element e;
               
                for( int i=0; i<3 ; i++){//for all dimensions of the element
                 e.dimensions[i].setup(dimensions[i],*index[i]);
                }
                elements.push_back(e);
                
                
                
            }
        }
    }
    
}


