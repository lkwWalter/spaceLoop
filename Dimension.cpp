
#include "Dimension.h"





void TrackDimension::setup(string _dimensionName){

    dimensionName = _dimensionName;
    offset.set("offset2 " + dimensionName,0,0,1);
    layerNumber.set("layerNumber2" + dimensionName,1.0,1.0,20.0);
   
    valueChange.addListener(this, &TrackDimension::offsetChange);
  
}
void TrackDimension::offsetChange(float &v){
    valueChange = v - lastValue;
    lastValue = v;
    
}



//ElementDimension//////////////////////////////////////////////////////////////////////////////////////////







void ElementDimension::setup(TrackDimension & _usedTrackDimension, int _index)

{
    trackDimension  = &_usedTrackDimension;
    setupPosition(_index);
   
    trackDimension->offset.addListener(this, &ElementDimension::updatePosition);
    
    
}




void ElementDimension::setupPosition(int &_index){
    relIndex = _index / trackDimension->layerNumber;
    updatePosition(relIndex);
    
};







void ElementDimension::updatePosition(float &_pos){
   cout << "updatePos" <<_pos <<endl;
    position += _pos;
}
void ElementDimension::factorPosition(float &_pos){
    cout << "FactoruUpdatePos" <<_pos <<endl;
    position += _pos * relIndex;
}

void ElementDimension::setTotalPosition(float &_pos){
    position = _pos;
       cout << "setPos" <<_pos <<endl;
}



float  & ElementDimension::getPosition(){
    return  position;
}
