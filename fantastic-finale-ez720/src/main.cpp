#include "ofMain.h"
#include "ofApp.h"
#include "gameEngine.hpp"

//========================================================================
int main( ){
	//ofSetupOpenGL(500,500,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
    
    GameEngine g;
    g.Run(8);

}
