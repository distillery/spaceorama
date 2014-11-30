#include "ofBaseTypes.h"
#include "ofMain.h"
#include "baan.h"

class planet {

    public:

        //planet();
        planet(string path);
        ofImage image;
        baan * bn;
        bool outOfSpace;
        float x;
        float y;
        float z;
        void setBaan(baan * b);
        void draw();
        void draw(int x, int y);
        void update();
        void setSpeed(float s);
        bool isOutOfSpace ();
        void reset();
    private:
        unsigned int counter;

};
