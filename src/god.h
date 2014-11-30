#include "planet.h"
#include "comet.h"
#include "xmlManager.h"
#include "scenario.h"

#define NPLANETS 6
#define NOBJECTS 3
#define NCOMETS 6
#define NMODELS 3  // statische modellen. Eigenlijk een soort container wiens image kan veranderen

class god {

    public:

        // Constructor (singleton)
        god();

        planet * planetManager[NPLANETS];
        comet * cometManager[NCOMETS];

        // XML stuff
        xmlManager xmlman;
        // sceanrio drawing
        scenario * _scenario;

        void fillBuffer();
        void draw();
        void update();
        void getNewPlanet(int i);
        void setScenario (int s);
        void drawScenario_1();
        void drawScenario_2();
        void drawScenario_3();

    private:

        ofDirectory * dir;
        ofDirectory * moonDir;
        int filePointer;
        int whichScenario;
        int startScenario1;
        int startScenario2;
        int startScenario3;
        int fCounterRocket;
        int currentMoon;
        int nMoons;
        float r_z;
        int frameCounter;
        baan * banen[NPLANETS];
        baan * komeetBanen[NCOMETS];
        void buildBanen();
        void loadStaticModels();

};
