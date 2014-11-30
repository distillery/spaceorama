#include "god.h"
#include "ofxXmlSettings.h"


god::god()  {

    cout << "Creating God..." << endl;
    // Scenario drawing
    fCounterRocket=0;
    frameCounter=0;
    startScenario1=0;
    startScenario2=200;
    r_z = 3.0;
    currentMoon=0;

    // DIRECTORY MET SCANS
    string path = "planets/"; // bin/data
    dir=new ofDirectory(path);
    dir->allowExt("png");
    filePointer=0; // pointer naar bepaalde png in directory. Om te tracken welke files nieuw zijn in de directory

    // DIRECTORY MET MANEN
    moonDir=new ofDirectory("objects/moons/");
    moonDir->allowExt("png");
    nMoons = moonDir->listDir();

    // initialisatie
    _scenario = new scenario(NMODELS);
    buildBanen();
    fillBuffer();
    loadStaticModels();

    cout << "Done creating god!" << endl;
}

void god::fillBuffer()  {

    int l = dir->listDir();

        for (int i=0;i<NPLANETS;i++)   { // neem telkens de laatste NPLANETS

            planetManager[i] = new planet (dir->getPath(l-1-i));
            cout << dir->getPath(l-1-i) << endl;
            planetManager[i]->setBaan(banen[i]);

            cout << "Set baan voor planet " << i << endl;
            filePointer++;

        }
        for (int i=0;i<NCOMETS;i++)   {
            cometManager[i] = new comet();
            cometManager[i]->setBaan(komeetBanen[i]);
        }

}
void god::getNewPlanet   (int i)  {
// 2DO: check of er wel nieuwe zijn
    dir->listDir();

        planetManager[i] = new planet (dir->getPath(filePointer));
        planetManager[i]->setBaan(banen[i]);
        filePointer++;

}
void god::buildBanen()  {

    for (int i=0;i<NPLANETS;i++)    {

        banen[i] = xmlman.getBaan("planeetbanen", i);

    }
    for (int i=0;i<NCOMETS;i++)    {

        komeetBanen[i] = xmlman.getBaan("komeetbanen", i);

    }
    cout << "Banen built." << endl;

}
void god::draw()   {

    if (whichScenario == 1)  { drawScenario_1();   }
    if (whichScenario == 2)  { drawScenario_2();   }
    if (whichScenario == 3)  { drawScenario_3();   }

}
void god::update()  {

    frameCounter++;
    cout << "Frame -> " << frameCounter << endl;
    if (frameCounter == startScenario2)    {
        setScenario(2);
    }
    //cout << "Updating planet coordinates.. " << endl;
    for (int i=0;i<NPLANETS;i++)    {
        planetManager[i]->update();
        if (planetManager[i]->isOutOfSpace()) {getNewPlanet(i);}
    }
    for (int i=0;i<NCOMETS;i++)    {
        cometManager[i]->update();
    }
    fCounterRocket+=1;
    r_z = r_z - 0.0005;

}
void god::setScenario (int s)   {

    whichScenario=s;
    fCounterRocket=0;
    if (whichScenario==1)   {
        frameCounter=0;
	fillBuffer();
        //_scenario->loadModel(2, "objects/venus.png");
        for (int i=0;i<NPLANETS;i++){
                planetManager[i]->reset();
        }
        if (currentMoon == nMoons-1)    {
            currentMoon = 0;
        }
        else    {
            currentMoon++;
        }
        _scenario->loadModel(2, moonDir->getPath(currentMoon));


    }


    //r_x=350.0;
    //r_y=0.0;
    r_z=1.0;

}
void god::drawScenario_1    ()  {

    _scenario->drawMoon(700,100);
    for (int i=0;i<NPLANETS;i++){
                planetManager[i]->draw();
    }
    for (int i=0;i<3;i++)    { // eerste 3 kometen
        cometManager[i]->draw();
    }
}
void god::drawScenario_2    ()  {


    for (int i=0;i<NPLANETS;i++){
                planetManager[i]->draw();
    }

    if (frameCounter <= startScenario2+600) {  // maan schuift op, mars komt er in

        _scenario->drawMoon(700+ofMap(frameCounter,startScenario2,startScenario2+600,0,100),100);
        _scenario->drawMars(-(800-frameCounter), 0);
        //moon->draw(700+ofMap(frameCounter,startScenario2,startScenario2+600,0,100),100);
        for (int i=0;i<3;i++)    { // kometen
            cometManager[i]->draw();
        }
    }

    if ((frameCounter > startScenario2+600) && (frameCounter <= startScenario2+2000)){ // maan en mars vast

        if (frameCounter == startScenario2 + 1000) {fCounterRocket=0;}
        if (frameCounter < startScenario2 + 1000)   {_scenario->drawStaticRaket(r_z);}
        else {_scenario->drawOpstijgendeRaket(fCounterRocket,r_z);}

        _scenario->drawMoon(800,100);
        _scenario->drawMars(0, 0);

        for (int i=2;i<NCOMETS;i++)    { // kometen
            cometManager[i]->draw();
        }

    }
    if (frameCounter==startScenario2+2001) {
        setScenario(1);
    }

    /*
    if (frameCounter <= startScenario1+1500)  { // maan en mars verdwijnen

        moon->draw(800+((frameCounter-800)/2),100);
        //for (int i=1;i<2;i++)    { // kometen
            cometManager[3]->draw();
            if (frameCounter > 1000)   {cometManager[4]->draw();}

        //}
        ofPushMatrix();
        ofTranslate((mars.width/2)-(900-(frameCounter-800)/4), (mars.height/2) + 400+((frameCounter-800)/4), 0);


    }
    */


}
void god::drawScenario_3    ()  {

}
void god::loadStaticModels()    {

    // aantal aanpassen in god.h
    _scenario->loadModel(0, "objects/rocket.png");
    _scenario->loadModel(1, "objects/mars.png");
    _scenario->loadModel(2, moonDir->getPath(currentMoon));


}



