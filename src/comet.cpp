#include "comet.h"

comet::comet()  {

    nCircles=40;
    alfa=255;

}
void comet::setBaan(baan * _b)   {

        b=_b;
        x=b->startX;
        y=b->startY;
        z=b->startZ;
        speed=b->speed;
        counter=z;

}
void comet::setSpeed(float s)   {   speed=s;    }

void comet::update(){

    counter=counter+speed;
    //cout << counter << endl;
    if (counter > b->outOfSpace){counter=0.0;}
    if (counter < -(b->outOfSpace)){counter=0.0;}

}

void comet::draw()  {

if (z == 0) {

        for (int i=0;i<nCircles;i++)  {

                ofSetColor(255,255,175,alfa-((i+1)*(255/nCircles)));
                ofPushMatrix();
                    ofTranslate(x,y,0);
                    ofScale(counter-(counter*i*0.009),counter-(counter*i*0.009),1);
                    //cout << "scaling factor -> " << mouse-(i*0.005) << endl;
                    ofFill();
                    float map = 1-(ofMap(i,0,nCircles,0,1));
                    ofCircle(b->offsetX,b->offsetY,map);
                    ofSetColor(255,0,0,50);
                    ofNoFill();
                    ofCircle(b->offsetX,b->offsetY,map);
                    //ofCircle(x,y,10-(ofMap(i,0,nCircles,0,10)));
                    //ofCircle(400,120,2);
                ofPopMatrix();
        }
        ofSetColor(255,255,255);
} else  {

    for (int i=0;i<nCircles;i++)  {

                ofSetColor(255,255,175,alfa+((i+1)*(255/nCircles)));
                ofPushMatrix();
                ofTranslate(x,y,0);
                    ofScale(counter-(counter*i*0.002),counter-(counter*i*0.002),1);
                    //cout << "scaling factor -> " << mouse-(i*0.005) << endl;
                    ofFill();
                    float map = 10-(ofMap(i,0,nCircles,0,10));
                    ofCircle(30,20,map);
                    ofSetColor(255,0,0,50);
                    ofNoFill();
                    ofCircle(30,20,map);
                    //ofCircle(x,y,10-(ofMap(i,0,nCircles,0,10)));
                    //ofCircle(400,120,2);
                ofPopMatrix();
        }
        ofSetColor(255,255,255);

}


}

