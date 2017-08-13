//
//  BaseScreen.hpp
//  170813_lit_add_hmw
//
//  Created by 狭間祐至 on 2017/08/13.
//
//

#pragma once
#include "ofMain.h"



class BaseScreen{
    
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void keyPressed(int key){};
    virtual void keyReleased(){};
    virtual void mouseMoved(int x, int y){};
    virtual void mouseDragged(){};
    virtual void mousePressed(int x, int y, int button){};
    virtual void mouseReleased(){};
    
};
