//
//  showScreen1.hpp
//  170813_lit_add_hmw
//
//  Created by 狭間祐至 on 2017/08/13.
//
//


#pragma once

#include "ofMain.h"
#include "BaseScreen.hpp"

#include "ofxPDF.h"

class showScreen1 : public BaseScreen{
public:
    
    void setup();
    void update();
    void draw();
    
    //pathのアニメーションを描画
    void drawAnimation();
    
    ofxPDF mPDF;
    vector<ofPolyline> polys;
    
};
