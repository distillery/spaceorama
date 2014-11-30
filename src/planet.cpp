#include "planet.h"

planet::planet(string path)    {

    outOfSpace=false;
    image.loadImage(path);
    image.resize(320,320);

}

void planet::setBaan (baan * b) {
        bn=b;
        cout << "SETBAAN:" << bn->startY << endl;
        x=bn->startX;
        y=bn->startY;
        z=bn->startZ;
        counter=z;
}
void planet::draw() {

// scaling van z -> 1

    //cout << "GOD: drawing" << endl;
    //cout << bn.getStartX() << endl;

    ofPushMatrix();
    //ofEnableDepthTest();
        ofTranslate(image.getWidth()/2+x,image.getHeight()/2+y);
        if (bn->speed != 0) {

            ofScale(z,z,1);
            //cout << "z -> " << z << endl;
        }
        //ofPushMatrix();
        //    ofTranslate(bn->offsetX,bn->offsetY);
        //ofPopMatrix();
        //image.draw(-image.getWidth()/2,-image.getHeight()/2);
        image.draw(-(image.getWidth()/2)+bn->offsetX,-(image.getHeight()/2)+bn->offsetY);
ofDisableDepthTest();
    ofPopMatrix();

}
void planet::draw(int _x, int _y) {

    ofPushMatrix();

        ofTranslate(image.getWidth()/2+_x,image.getHeight()/2+_y);
        if (bn->speed != 0) {

            ofScale(z,z,1);
            //cout << "z -> " << z << endl;
        }

        image.draw(-(image.getWidth()/2),-(image.getHeight()/2));

    ofPopMatrix();

}
void planet::update()   {

//counter=counter+0.01;
//if (counter > 1.0){counter=0.0;}
    //cout << "z-> " << z << endl;
    //x=x+bn->directionX;
    //y=y+bn->directionY;
/*

    if (z < 0.2)  {
    z=z+(bn->speed);
}
if (z < 0.3)  {
    z=z+(bn->speed/10);
}
if (z < 0.4)  {
    z=z+(bn->speed*10);
}
if (z < 0.5)  {
    z=z+(bn->speed);
}
if (z > 0.7)  {
    z=z+(bn->speed);
}
*/
    z=z+(bn->speed);
//cout << "Counter -> " << z << endl;
    if (z > bn->outOfSpace) { outOfSpace=true;}
    //cout << "x->" << x << endl;
    //cout << "y->" << y << endl;
    //cout << "z->" << z << endl;

}
void planet::reset()    {
    z=bn->startZ;
}
bool planet::isOutOfSpace (){

    return outOfSpace;

}
void planet::setSpeed(float s) {



}


