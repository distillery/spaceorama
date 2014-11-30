#pragma once
#include "ofMain.h"
#include "baan.h"
#include "ofBaseTypes.h" // Nodig voor string

class xmlManager {

    public:

        xmlManager();

        baan * getBaan(string keyword, int i);
        unsigned int nBanen;

        ofXml spaceLayout;
        ofFile file;
        string basePath;
        string path;
        int * framePoints;
        //int * test[];
        int * counter;
        void checkWithFramePoints();
    private:
        baan * bn;

};

