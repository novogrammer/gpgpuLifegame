#include "gpgpuLifeApp.h"



//--------------------------------------------------------------
void gpgpuLifeApp::setup(){
    mCurrentBuffer=&mBuffers[0];
    mPrevBuffer=&mBuffers[1];
    mouseX=0;
    mouseY=0;
    pressed=false;
    ofFbo::Settings s = ofFbo::Settings();
    s.width=CELL_WIDTH;
    s.height=CELL_HEIGHT;
    s.internalformat=GL_RGBA;
    s.useDepth=false;
    s.depthStencilAsTexture=false;
    for(int i=0;i<2;++i){
        mBuffers[i].allocate(s);
        mBuffers[i].begin();
        ofBackground(0, 0, 0);
        mBuffers[i].end();
    }
    mLifeShader.load("shaders/life.vs","shaders/life.fs");
}

//--------------------------------------------------------------
void gpgpuLifeApp::update(){

}

//--------------------------------------------------------------
void gpgpuLifeApp::draw(){
    swap(mCurrentBuffer, mPrevBuffer);
    mCurrentBuffer->begin();
    mLifeShader.begin();
    mLifeShader.setUniform2f("cellsize",CELL_WIDTH,CELL_WIDTH);
    mLifeShader.setUniform2f("mouse",mouseX/SCALE,mouseY/SCALE);
    mLifeShader.setUniform1f("range",BRUSH_RANGE);
    mLifeShader.setUniform1f("pressed",pressed);
    mPrevBuffer->draw(0,0);
    mLifeShader.end();
    mCurrentBuffer->end();
    ofScale(SCALE,SCALE);
    mCurrentBuffer->draw(0, 0);
}

//--------------------------------------------------------------
void gpgpuLifeApp::keyPressed(int key){

}

//--------------------------------------------------------------
void gpgpuLifeApp::keyReleased(int key){

}

//--------------------------------------------------------------
void gpgpuLifeApp::mouseMoved(int x, int y ){
    mouseX=x;
    mouseY=y;
    pressed=false;
}

//--------------------------------------------------------------
void gpgpuLifeApp::mouseDragged(int x, int y, int button){
    mouseX=x;
    mouseY=y;
    pressed=true;
}

//--------------------------------------------------------------
void gpgpuLifeApp::mousePressed(int x, int y, int button){
    mouseX=x;
    mouseY=y;
    pressed=true;
}

//--------------------------------------------------------------
void gpgpuLifeApp::mouseReleased(int x, int y, int button){
    mouseX=x;
    mouseY=y;
    pressed=false;
}

//--------------------------------------------------------------
void gpgpuLifeApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void gpgpuLifeApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void gpgpuLifeApp::dragEvent(ofDragInfo dragInfo){ 

}
