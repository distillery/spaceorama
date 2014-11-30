#include "baan.h"
#include "ofMain.h"

class comet {

    public:
        comet();

        baan * b;

        float x;
        float y;
        float z;
        float speed;
        void setBaan(baan * b);
        void draw();
        void update();
        void setSpeed(float s);

    private:
        float counter;
        unsigned int nCircles;
        unsigned int alfa;

};




