//
//  showScreen1.cpp
//  170813_lit_add_hmw
//
//  Created by 狭間祐至 on 2017/08/13.
//
//
//
#include "showScreen1.hpp"

//--------------------------------------------------------------
void showScreen1::setup(){
    
    
    mPDF.load("ma.pdf");
    
    // PDFのパスを順番に取り出し、細かく分けたやつをpolysにpush_backしていく
    for (int i = 0; i < mPDF.getNumPath(); i++){
        ofPath& path = mPDF.getPathAt(i);
        const vector<ofPolyline > &tmpPoly = path.getOutline();
        for (int k = 0; k < tmpPoly.size(); k++){
            polys.push_back(tmpPoly[k]);
        }
    }
    
}

//--------------------------------------------------------------
void showScreen1::update(){
    
}

//--------------------------------------------------------------
void showScreen1::draw(){
    ofSetColor(255,255,255);
    //mPDF.draw();
    drawAnimation();
    
}

//--------------------------------------------------------------

void showScreen1::drawAnimation(){
    ofPolyline tmpPoly;
    float animation_time = fmodf(ofGetElapsedTimef(), 1) * 4.5;
    for (int k = 0; k < polys.size(); k++){
        tmpPoly = polys.at(k).getResampledByCount(100);
        int target_size = polys.size() * animation_time;
        tmpPoly.resize(target_size);
        tmpPoly.draw();
    }
}
