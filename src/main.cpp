#include "ofMain.h"
#include "gpgpuLifeApp.h"

//========================================================================
int main( ){
    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
	ofSetupOpenGL(
      gpgpuLifeApp::CELL_WIDTH*gpgpuLifeApp::SCALE,
      gpgpuLifeApp::CELL_HEIGHT*gpgpuLifeApp::SCALE,
      OF_WINDOW);			// <-------- setup the GL context
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new gpgpuLifeApp());

}
