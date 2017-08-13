//
//  showScreen2.hpp
//  170813_lit_add_hmw
//
//  Created by 狭間祐至 on 2017/08/13.
//
//

#pragma once

#include "ofMain.h"

#include "BaseScreen.hpp"

class showScreen2 : public BaseScreen{
    
public:
    void setup();
    void update();
    void draw();
    
//        //pathのアニメーションを描画
//        void drawAnimation();
    
    void keyPressed(int key);
    
    
    ofTrueTypeFont myFont;        //文字のフォント情報
    string text;                  //出力する文字列
    
    vector<ofColor> color; //パーティクルの色
    vector<ofPoint> cpos;  //パーティクルの現在位置
    vector<ofPoint> gpos;  //パーティクルの目標位置
    vector<ofVec2f> vel;   //パーティクルの速度
    
    bool isKeyPressed;           //キーを押下した/していない
    int radius;                  //パーティクルの半径
};



