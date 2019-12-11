#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //initialize menu panel
    ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_LEFT);
    gui->addHeader(":: MENU ::");
    gui->getHeader()->setTheme(new ofxDatGuiThemeWireframe());
    
    //dropdown menu to pick player
    vector<string> strategy_options = {"Human", "Minimax"};
    strategy_menu = gui->addDropdown("Select player", strategy_options);
    strategy_menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    strategy_menu->setTheme(new ofxDatGuiThemeAqua());
    
    //slider to pick board size
    slider = gui->addSlider("Size", 6, 10, 8);
    slider->onSliderEvent(this, &ofApp::onSliderEvent);
    slider->setPrecision(0);
    slider->setTheme(new ofxDatGuiThemeAqua());
    
    //reset button
    reset_button = gui->addButton("Reset");
    reset_button->setTheme(new ofxDatGuiThemeAqua());
    reset_button->onButtonEvent(this, &ofApp::onButtonEvent);
    
    for (int i = 0; i < board_size; i++) {
        circles.push_back(-1);
    }
    
    board = Board(true_board_length);
    board.SetInitialBoard();
    
    black = Player('X');
    white = Player('O');
    current_player = black;
    
    minimax_white = MinimaxStrategy();
    minimax_white.minimax_player = white;
    
    minimax_black = MinimaxStrategy();
    minimax_black.minimax_player = black;
    
    human_player = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    //clear board and set it to initial state, start new game
    if (reset) {
        reset = false;
        
        circles.clear();
        
        for (int i = 0; i < board_size; i++) {
            circles.push_back(-1);
        }
        
        board.SetInitialBoard();
        current_player = black;
    }
    
    strategy_menu->update();
    
    if (current_player.GetMark() == 'X') {
        if (human_player) {
            //if player has clicked a valid tile
            if (clicked) {
                clicked = false;
                current_player = board.NextPlayer(current_player);
                
                //clear possible moves displayed on GUI
                for (int i = 0 ; i < circles.size(); i++) {
                    if (circles[i] == 100) {
                        circles[i] = -1;
                    }
                }
            }
            
            else {
                //display possible moves
                vector<int> moves = board.GetValidMoves(current_player);
                for (int move : moves) {
                    circles[move] = 100;
                }
            }
        }
        
        //if selected player (from dropdown) is minimax
        else {
            UpdateMinimaxMove(minimax_black);
        }

    }

    else if (current_player.GetMark() == 'O') {
        UpdateMinimaxMove(minimax_white);
    }
    
    const vector<char> &board_vector = board.GetBoard();
    
    //update circles vector for drawing
    for (int i = 0; i < board_vector.size(); i++) {
        if (board_vector[i] == 'X') {
            circles[i] = 0;
        }
        
        else if (board_vector[i] == 'O') {
            circles[i] = 255;
        }
        
        else if (board_vector[i] == '-') {
            circles[i] = 150;
        }
    }
}

//--------------------------------------------------------------
void ofApp::UpdateMinimaxMove(MinimaxStrategy strategy) {
    usleep(800000);
    int move = strategy.GetMove(current_player, board);
    board.MakeMove(move, current_player);
    current_player = board.NextPlayer(current_player);
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < circles.size(); i++) {
        std::pair<int, int> center = PlottingUtil::IndexToCenter(i, board_length, ofGetWidth());
        int color = circles[i];
        
        //drawing circles
        if (color != -1 && color != 150) {
            //drawing possible moves
            if (color == 100) {
                ofNoFill();
                ofSetColor(color, 0, 0);
            }
            
            else {
                ofSetColor(color, color, color);
            }
            
            ofDrawCircle(center.first, center.second, 300 / board_length);
            ofSetColor(255, 255, 255);
            ofFill();
        }
        
        //filling in boundaries
        else if (color == 150) {
            int scale = ofGetWidth() / board_length;
            ofSetColor(color, color, color);
            ofDrawRectangle(center.first - scale / 2, center.second - scale / 2, scale, scale);
            ofSetColor(255, 255, 255);
        }
    }
    
    //draw lines for board
    for (int i = 0; i < ofGetWidth(); i+=(ofGetWidth() / board_length)) {
        ofDrawLine(0, i, ofGetWidth(), i);
        ofDrawLine(i, 0, i, ofGetWidth());
    }
    
    strategy_menu->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    int index = PlottingUtil::ClickToIndex(x, y, board_length, ofGetWidth());
    
    //if is player's turn and they clicked a valid tile, update board with their move
    if (board.IsValidMove(index, black) && human_player) {
        board.MakeMove(index, Player('X'));
        clicked = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e){
    human_player = (e.child == 0) ? true : false;
    reset = true;
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e){
    reset = true;
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e){
    if ((int)e.value % 2 == 0) {
        board = Board(e.value);
        
        true_board_length = e.value;
        board_length = true_board_length + 2;
        board_size = board_length * board_length;
        
        reset = true;
    }
}
