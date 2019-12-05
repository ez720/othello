#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "circle.hpp"
#include "board.hpp"
#include "gameEngine.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    
        vector<Circle> circles;
        bool player_black = true;
        bool reset;
    
        ofxDatGuiDropdown* strategy_menu;
        void onDropdownEvent(ofxDatGuiDropdownEvent e);
        ofxDatGuiButton* button;
        void onButtonEvent(ofxDatGuiButtonEvent e);
		
};
