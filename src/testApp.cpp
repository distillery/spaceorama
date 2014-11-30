#include "testApp.h"
ofImage rocket;
float r_x=700.0;
float r_y=400.0;
float r_z=0.0;
float rotate_y=0.0;

void testApp::setup(){

    #if defined(TARGET_OSX)
        // SYPHON
        syphon.setName("SPACEORAMA");
    #endif

    //ofToggleFullscreen();
    background.loadImage("space.jpg");
    ofSetFrameRate(30);
    x=0.0;
godOfPlanets.setScenario(1);

//ofEnableDepthTest(); // enable depth test
ofEnableAlphaBlending();
    cout << "Setup complete!" << endl;
    ofBackground(0,0,0,0);
    //ofSetBackgroundColor(0,0,0);

}
void testApp::draw(){

    #if defined(TARGET_OSX)
        //SYPHON
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    #endif


    //glEnable(GL_DEPTH);
    //glEnableDepthTest();
//background.draw(0,0,-1);




    godOfPlanets.draw();

  /*  model.setRotation(0,x,0,0,1);
model.setScale(0.5, 0.5, 0.5);
model.setPosition(ofGetWidth()*2/6, (float)ofGetHeight() * 0.75 , 0);
model.drawFaces();
*/
    #if defined(TARGET_OSX)
        //SYPHON
        syphon.publishScreen();
    #endif

}

//--------------------------------------------------------------
void testApp::update(){

    godOfPlanets.update();

    ofGetElapsedTimef();
    x=x+0.5;

    //r_x-=1;
    //if (r_z <= 35.0)   {r_z = r_z + 0.1;}
    //if (r_z >= 35.0) { rotate_y+=-5;}
    rotate_y-=0.5;
    r_z = r_z + 0.1;
    //cout << r_z << endl;
    //while (rotate_y<90.0) {
     //   rotate_y+=0.1;
    //}





}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
cout << key << endl;
switch (key)    {

    case    '1':
        cout << "1 pressed" << endl;
        godOfPlanets.setScenario(1);
        break;
    case    '2':
        godOfPlanets.setScenario(2);
        cout << "2 pressed" << endl;
        break;

}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
