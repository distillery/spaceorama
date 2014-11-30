#include "xmlManager.h"
#include "ofBaseTypes.h"

xmlManager::xmlManager()  {


    file.open("SpaceOrama.xml"); // open a file
    ofBuffer buffer = file.readToBuffer(); // read to a buffer

    spaceLayout.loadFromBuffer( buffer.getText() );

    //nKomeetBanen = spaceLayout.getNumChildren();
    //cout << "Children - " << nTakeOffs << endl;
    //framePoints=new int[nTakeOffs];  // zie http://stackoverflow.com/questions/322086/c-array-declaration-in-a-header
/*
    for (int i=0;i<nTakeOffs;i++)  {  // steek alle framePoints uit xml in een array
        path="commercial["+ofToString(i)+"]/frame";
        //cout << commercials.getValue(path) << endl;
        framePoints[i]=ofToInt(commercials.getValue(path));
        //cout << framePoints[i] << endl;
    }
*/
}
baan * xmlManager::getBaan(string keyword, int i)   {

    float baanSpecs[7];
    spaceLayout.setTo(keyword);
    path = "baan["+ofToString(i)+"]/startx";
    baanSpecs[0]=ofToFloat(spaceLayout.getValue(path));
    path = "baan["+ofToString(i)+"]/starty";
    baanSpecs[1]=ofToFloat(spaceLayout.getValue(path));
    path = "baan["+ofToString(i)+"]/startz";
    baanSpecs[2]=ofToFloat(spaceLayout.getValue(path));
    path = "baan["+ofToString(i)+"]/offsetx";
    baanSpecs[3]=ofToFloat(spaceLayout.getValue(path));
    path = "baan["+ofToString(i)+"]/offsety";
    baanSpecs[4]=ofToFloat(spaceLayout.getValue(path));
    path = "baan["+ofToString(i)+"]/speed";
    baanSpecs[5]=ofToFloat(spaceLayout.getValue(path));
    path = "baan["+ofToString(i)+"]/outOfSpace";
    baanSpecs[6]=ofToFloat(spaceLayout.getValue(path));
    bn = new baan(baanSpecs[0],baanSpecs[1],baanSpecs[2],baanSpecs[3],baanSpecs[4],baanSpecs[5],baanSpecs[6]);
    spaceLayout.setTo("../");
    return bn;

}
