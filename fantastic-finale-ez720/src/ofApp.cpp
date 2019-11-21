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
}

//--------------------------------------------------------------
void ofApp::update(){
    strategy_menu->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (Circle c : circles) {
        ofDrawCircle(c.x, c.y, 20);
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
    Circle c = Circle(x, y, 1);
    circles.push_back(c);
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
    GameEngine::SetupNewGame();
}