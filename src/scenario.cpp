#include "scenario.h"

#define ROCKET 0
#define MARS 1
#define MOON 2
#define STAR 3

scenario::scenario (int nModels)   {

    images = new ofImage[nModels];
    starFloat=0.5;

}

void scenario::loadModel(int i, string path)    {

    images[i].loadImage(path);

}
void scenario::drawStaticRaket(float scale) {

    ofPushMatrix();
           ofPushMatrix();
                ofTranslate(images[0].width/2+300, images[0].height/2 + 500, 0);
                ofScale(scale,scale,1);
                ofRotate(90, 0, 0,1 );
                ofPushMatrix();
                    images[0].draw(-images[0].width/2,-images[0].height/2);
           ofPopMatrix();
        ofPopMatrix();
    ofPopMatrix();

}
void scenario::drawOpstijgendeRaket(int fCounterRocket, float r_z)   {

    ofPushMatrix();
        ofTranslate(0, 500, 0);
        ofRotate(-fCounterRocket *0.1, 0, 0,1 );
        ofTranslate(0, -500, 0);
            ofPushMatrix();
                ofTranslate(images[0].width/2+300, images[0].height/2 + 500, 0);
                if ((90-(fCounterRocket*0.1)) > 50)    {
                    ofRotate(90-(fCounterRocket*0.1) , 0, 0,1 );
                }else{
                    ofRotate(50, 0, 0,1 );
                }

                //ofRotate(ofGetFrameNum()*0.1 , 0, 0,1 );
                ofScale(r_z,r_z,1);
                ofPushMatrix();
                    images[0].draw(-images[0].width/2,-images[0].height/2);
                ofPopMatrix();
        ofPopMatrix();
    ofPopMatrix();

}
void scenario::drawMars(int x, int y) {

    ofPushMatrix();
        ofTranslate(images[1].width/2-900+x, images[1].height/2 + 400+y, 0);
        ofRotate(ofGetFrameNum() * .03, 0, 0, 1);   // rotate rechts
        ofPushMatrix();
           images[1].draw(-(images[1].width/2),-(images[1].height/2)); // draw mars
        ofPopMatrix();
    ofPopMatrix();

}
void scenario::drawMoon(int x, int y) {

    ofPushMatrix();
        ofTranslate(images[MOON].width/2 + x, images[MOON].height/2 + y, 0);
        ofRotate(-ofGetFrameNum() * .05, 0, 0, 1);
        ofPushMatrix();
           images[2].draw(-(images[2].width/2),-(images[2].height/2)); // draw mars
        ofPopMatrix();
    ofPopMatrix();
    //moon->draw(700+ofMap(frameCounter,startScenario2,startScenario2+600,0,100),100);
}
void scenario::drawStar(int x, int y, float scale)   {

    ofPushMatrix();
        ofTranslate(images[STAR].width/2+400, images[STAR].height/2 + 200, 0);
        ofScale(scale,scale,1);
        ofPushMatrix();
        //if (starFloat > 0.0)    {
            images[STAR].draw(-(images[STAR].width/2),-(images[STAR].height/2)); // draw mars
        //}
        ofPopMatrix();
    ofPopMatrix();
    //starFloat-0.05;
    //if (starFloat < 5.0)    {


    //}
}

