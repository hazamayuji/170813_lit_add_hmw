#pragma once

#include "ofMain.h"
#include "ofxPDF.h"
#include "BaseScreen.hpp"
#include "showScreen1.hpp"
#include "showScreen2.hpp"

#define Screen_NUM 5

enum class AppScreen{
    showScreen1 = 0,
    showScreen2,
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
//        //pathのアニメーションを描画
//        void drawAnimation();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void changeScreen(AppScreen screen);
    
private:
    BaseScreen *getCurrentScreen();
    
    int currentScreen = 0;

    
};
