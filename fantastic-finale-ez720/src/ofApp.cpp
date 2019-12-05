#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_LEFT);
    gui->addHeader(":: MENU ::");
    gui->getHeader()->setTheme(new ofxDatGuiThemeWireframe());
    
    vector<string> strategy_options = {"Human", "Minimax"};
    strategy_menu = gui->addDropdown("Select opponent", strategy_options);
    strategy_menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    strategy_menu->setTheme(new ofxDatGuiThemeAqua());
    
    button = gui->addButton("Reset");
    button->setTheme(new ofxDatGuiThemeAqua());
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    
    for (int i = 0; i < 100; i++) {
        circles.push_back(-1);
    }
    
    board = Board(8);
    board.SetInitialBoard();
    
    /*Player black = Player('X');
    MinimaxStrategy minimax_black = MinimaxStrategy();
    minimax_black.minimax_player = black;
    Player player = black;
    vector<int> moves = board.GetValidMoves(player);
    
    for (int m : moves) {
        std::pair<int, int> center = PlottingUtil::IndexToCenter(m);
        circles.push_back(Circle(center.first, center.second, 2));
    }
    
    int move = minimax_black.GetMove(player, board);
    board.MakeMove(move, player);
    board.PrintBoard(std::cout);
    
    std::pair<int, int> center = PlottingUtil::IndexToCenter(move);
    circles.push_back(Circle(center.first, center.second, 1));*/
}

//--------------------------------------------------------------
void ofApp::update(){
    strategy_menu->update();
    
    const vector<char> &board_vector = board.GetBoard();
    
    for (int i = 0; i < board_vector.size(); i++) {
        std::pair<int, int> center = PlottingUtil::IndexToCenter(i);
        
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
    if (reset) {
        reset = false;
        for (int i = 0; i < 100; i++) {
            circles[i] = -1;
        }
        board.SetInitialBoard();
        update();
    }
    
    for (int i = 0; i < circles.size(); i++) {
        std::pair<int, int> center = PlottingUtil::IndexToCenter(i);
        
        if (circles[i] == 0) {
            ofSetColor(255, 255, 255);
        }
        
        else if (circles[i] == 1) {
            ofSetColor(0, 0, 0);
        }
        
        else if (circles[i] == 2) {
            ofNoFill();
            ofSetColor(255, 0, 0);
        }
        
        if (circles[i] != -1) {
            ofDrawCircle(center.first, center.second, 35);
            ofSetColor(255, 255, 255);
            ofFill();
        }
    }
    
    for (int i = 0; i < 1000; i+=100) {
        ofDrawLine(0, i, 1000, i);
        ofDrawLine(i, 0, i, 1000);
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
    int index = PlottingUtil::ClickToIndex(x, y);
    circles[index] = 1;
    board.MakeMove(index, Player('X'));
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
    if (e.child == 0) {
        cout << "Human";
    }
    else {
        cout << "Minimax";
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e){
    //GameEngine::SetupNewGame();
    reset = true;
    
}
