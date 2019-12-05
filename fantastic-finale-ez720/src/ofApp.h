#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "board.hpp"
#include "gameEngine.hpp"
#include "player.hpp"
#include "plottingUtil.hpp"

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
    
        bool player_black = true;
        bool reset;
    
        Board board;
        Player black;
        Player white;
        Player current_player;
    
        ofxDatGuiDropdown* strategy_menu;
        void onDropdownEvent(ofxDatGuiDropdownEvent e);
        ofxDatGuiButton* button;
        void onButtonEvent(ofxDatGuiButtonEvent e);
    
        vector<int> circles;
        MinimaxStrategy minimax_white;
        bool clicked;
		
};
