#pragma once

#include "ofMain.h"

class gpgpuLifeApp : public ofBaseApp{

public:
    static const int CELL_WIDTH=256;
    static const int CELL_HEIGHT=CELL_WIDTH;
    static const int SCALE=2;
    static const int BRUSH_RANGE=1;
    
    ofFbo mBuffers[2];
    ofFbo* mCurrentBuffer;
    ofFbo* mPrevBuffer;
    ofShader mLifeShader;
    int mouseX;
    int mouseY;
    bool pressed;
    
    
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
};
