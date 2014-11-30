
#pragma once
#include "ofMain.h"
#include "ofBaseTypes.h"


class scenario  {

    public:
        scenario(int nModels);
        void loadModel(int i, string path);
        void drawStaticRaket(float scale);
        void drawOpstijgendeRaket(int i, float r_z);
        void drawMars(int i, int y);
        void drawMoon(int i, int y);
        void drawStar(int i, int y, float scale);
    private:
        ofImage * images;

        // star
        float starFloat;
};
