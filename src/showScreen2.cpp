//
//  showScreen2.cpp
//  170813_lit_add_hmw
//
//  Created by 狭間祐至 on 2017/08/13.
//
//

#include "showScreen2.hpp"


void showScreen2::setup(){
    
    //フォントの設定
    myFont.load("Arial Black.ttf",  72, true, true, true, 0.3, 0);
    //テキストの設定
    text = "Hello world!";
    //パーティクルの半径の設定
    radius = 2;
    
    //ofTTFCharacter型のベクター配列にして格納
    vector<ofTTFCharacter> str = myFont.getStringAsPoints(text);
    //文字列の中心座標を計算
    ofPoint center = ofPoint(myFont.stringWidth(text)/2, myFont.stringHeight(text)/2);
    //画面中央に文字列を出力する為にシフト量を計算
    ofPoint shift = ofPoint(ofGetWidth()/2, ofGetHeight()/2) - center;
    
    //文字列の１文字ずつのループ
    for(int i = 0; i < str.size(); i++){
        
        //文字の輪郭のループ
        for(int j = 0; j < str[i].getOutline().size(); j++){
            
            ofPoint first, prev;
            
            //文字の輪郭を形成する点のループ
            for(int k = 0; k <= str[i].getOutline()[j].size(); k++){
                
                ofVec2f pos;
                
                if(k < str[i].getOutline()[j].size()){
                    //点の位置座標を設定
                    pos = ofPoint(str[i].getOutline()[j].getVertices()[k].x,
                                  str[i].getOutline()[j].getVertices()[k].y);
                }else{
                    //輪郭が一周したら先頭の点に戻る
                    pos = first;
                }
                
                if(k == 0){
                    //先頭の点を記憶しておく
                    first = pos;
                    
                }else{
                    
                    //一つ前の点(prev)と現在の点(pos)の距離を計算する
                    float length = sqrt(pow((pos.x - prev.x),2) + pow((pos.y - prev.y),2));
                    
                    //前の点と現在の点をパーティクルで繋げるときに
                    //どのくらいの間隔でパーティクルを配置してゆくかを計算する
                    float addX = (pos.x - prev.x) * (radius / length);
                    float addY = (pos.y - prev.y) * (radius / length);
                    
                    //前の点の位置にパーティクルを置く
                    gpos.push_back(prev + shift);
                    
                    //前の点と現在の点との間に一定間隔でパーティクルを置く
                    for(int n = 0; n < (length / radius) - 1; n++){
                        prev.x += addX;
                        prev.y += addY;
                        gpos.push_back(prev + shift);
                    }
                }
                //現在の点の位置座標を記憶する
                prev = pos;
            }
        }
    }
    
    //パーティクルの目標位置の数と同じ数だけ
    //color(色情報),cpos(現在位置情報),vel(現在速度)の配列に要素を格納する
    for(int i  = 0; i < gpos.size(); i++){
        //色はx軸方向にグラデーション
        color.push_back(ofColor(120+gpos[i].x/8, 0, 122));
        //現在位置は画面内にランダムに配置
        cpos.push_back(ofPoint(ofRandom(0, ofGetHeight()), ofRandom(0, ofGetHeight())));
        //現在速度は-1から1の間でランダムに設定
        vel.push_back(ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1)));
    }
    
    isKeyPressed = false;
}


void showScreen2::update(){
    
    for( int i=0; i<cpos.size(); i++){
        
        if(isKeyPressed){
            if(abs(gpos[i].x - cpos[i].x) > abs(vel[i].x)){
                cpos[i].x += vel[i].x;
            }else{
                cpos[i].x = gpos[i].x;
                vel[i].x = 0;
            }
            
            if(abs(gpos[i].y - cpos[i].y) > abs(vel[i].y)){
                cpos[i].y += vel[i].y;
            }else{
                cpos[i].y = gpos[i].y;
                vel[i].y = 0;
            }
            
        }else{
            
            if(cpos[i].x > ofGetWidth()){
                cpos[i].x =ofGetWidth();
                vel[i].x *= (-1);
            }else if(cpos[i].x < 0){
                cpos[i].x = 0;
                vel[i].x *= (-1);
            }else{
                cpos[i].x += vel[i].x;
            }
            
            if(cpos[i].y > ofGetHeight()){
                cpos[i].y = ofGetHeight();
                vel[i].y *= (-1);
            }else if(cpos[i].y < 0){
                cpos[i].y = 0;
                vel[i].y *= (-1);
            }else{
                cpos[i].y += vel[i].y;
            }
            
        }
    }
}

void showScreen2::draw(){
    
    ofBackground(0, 0, 0);
    
    for(int i=0; i<cpos.size(); i++){
        ofSetColor(color[i]);
        ofDrawCircle(cpos[i].x, cpos[i].y, radius);
    }
}





//--------------------------------------------------------------
void showScreen2::keyPressed(int key){
    
    const static int ftime= 300;
    
    switch(key){
        case 'f':
            ofToggleFullscreen();
            break;
        case 'a':
            isKeyPressed = !isKeyPressed;
            for(int i=0; i<vel.size(); i++){
                vel[i].x = (isKeyPressed) ? (gpos[i].x-cpos[i].x)/ftime : ofRandom(-1, 1);
                vel[i].y = (isKeyPressed) ? (gpos[i].y-cpos[i].y)/ftime : ofRandom(-1, 1);
            }
            break;
    }
    
}
