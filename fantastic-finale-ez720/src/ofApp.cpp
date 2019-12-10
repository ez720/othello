#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_LEFT);
    gui->addHeader(":: MENU ::");
    gui->getHeader()->setTheme(new ofxDatGuiThemeWireframe());
    
    vector<string> strategy_options = {"Human", "Minimax"};
    strategy_menu = gui->addDropdown("Select player", strategy_options);
    strategy_menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    strategy_menu->setTheme(new ofxDatGuiThemeAqua());
    
    button = gui->addButton("Reset");
    button->setTheme(new ofxDatGuiThemeAqua());
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    
    slider = gui->addSlider("Size", 6, 10, 8);
    slider->onSliderEvent(this, &ofApp::onSliderEvent);
    slider->setPrecision(0);
    slider->setTheme(new ofxDatGuiThemeAqua());
    
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
    //clear board and set it to initial state
    if (reset) {
        reset = false;
        
        for (int i = 0; i < board_size; i++) {
            circles[i] = -1;
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
                
                //clear possible moves on board
                for (int i = 0 ; i < circles.size(); i++) {
                    if (circles[i] == 2) {
                        circles[i] = -1;
                    }
                }
            }
            
            else {
                //display possible moves
                vector<int> moves = board.GetValidMoves(current_player);
                for (int move : moves) {
                    circles[move] = 2;
                }
            }
        }
        
        else {
            usleep(800000);
            int move = minimax_black.GetMove(current_player, board);
            board.MakeMove(move, current_player);
            current_player = board.NextPlayer(current_player);
        }

    }

    else if (current_player.GetMark() == 'O') {
        usleep(800000);
        int move = minimax_white.GetMove(current_player, board);
        board.MakeMove(move, current_player);
        current_player = board.NextPlayer(current_player);
    }
    
    const vector<char> &board_vector = board.GetBoard();
    
    //update circles vector for drawing
    for (int i = 0; i < board_vector.size(); i++) {
        if (board_vector[i] == 'X') {
            circles[i] = 1;
        }
        
        if (board_vector[i] == 'O') {
            circles[i] = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < circles.size(); i++) {
        std::pair<int, int> center = PlottingUtil::IndexToCenter(i, board_length, ofGetWidth());
        
        //set color to white
        if (circles[i] == 0) {
            ofSetColor(255, 255, 255);
        }
        
        //set color to black
        else if (circles[i] == 1) {
            ofSetColor(0, 0, 0);
        }
        
        //possible move
        else if (circles[i] == 2) {
            ofNoFill();
            ofSetColor(255, 0, 0);
        }
        
        //draw circles
        if (circles[i] != -1) {
            ofDrawCircle(center.first, center.second, 300 / board_length);
            ofSetColor(255, 255, 255);
            ofFill();
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
    
    if (board.IsValidMove(index, black) && human_player) {
        circles[index] = 1;
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
