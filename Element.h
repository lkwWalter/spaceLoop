#pragma once
#include "ofMain.h"
#include "Dimension.h"

class Element{
    public:
        Element();
       
        void draw();
        vector<ElementDimension> dimensions;
    
    private:
        void testRect();
    
    
    
};
