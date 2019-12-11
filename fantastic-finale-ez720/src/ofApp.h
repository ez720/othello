#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "minimaxStrategy.hpp"
#include "player.hpp"
#include "plottingUtil.hpp"
#include <unistd.h>

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
    
        bool clicked;
        bool reset;
        bool human_player;
    
        int true_board_length = 8;
        int board_length = true_board_length + 2;
        int board_size = board_length * board_length;
    
        Board board;
        Player black;
        Player white;
        Player current_player;
    
        /*
         Dropdown menu to select player
         */
        ofxDatGuiDropdown* strategy_menu;
    
        /*
         Creates new game where the selected player (human or minimax) plays against minimax
         */
        void onDropdownEvent(ofxDatGuiDropdownEvent e);
    
        /*
         Reset button
         */
        ofxDatGuiButton* reset_button;
    
        /*
         Clears board and starts new game
         */
        void onButtonEvent(ofxDatGuiButtonEvent e);
    
        /*
         Slider to pick board size
         */
        ofxDatGuiSlider* slider;
    
        /*
         Creates new board and updates GUI according to chosen size
         */
        void onSliderEvent(ofxDatGuiSliderEvent e);
    
        vector<int> circles;
        MinimaxStrategy minimax_white;
        MinimaxStrategy minimax_black;
    
        /*
         Gets move from minimax according to current board and updates board
         */
        void UpdateMinimaxMove(MinimaxStrategy strategy);
		
};
