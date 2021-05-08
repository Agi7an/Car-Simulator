/*
File: Engine.h
Authors: Agilan and Arjuna
Engine Header File
*/

#include <string>
#include "Battery.h"
#include "Transmission.h"
using namespace std;

#define MAX_RPM 100     //Limiting the maximum rpm

class Engine
{
    private:
        bool airLevel;      //Indicates if there is enough air for combustion
        bool fuelLevel;     //Indicates if there is enough fuel for combustion
        bool piston;        //Indicates the position of the piston(true->up; false->down)
        bool engineOn;      //True if the engine is on
        int rpm;            //Rotations Per Minute of the Engine
        float engineHeat;   //Indicates the heat level of the engine
        float heatRatio;    //Indicates the rate at which the engine heat increases
        float usage;        //Measures the engine's usage
        float handling;
        double timeRunning; //Measures how long the engine has been running
        Battery* b;         //Engine HAS A Battery(Composition)
        Transmission* t;    //Engine HAS A transmission(Composition)

    public:
        Engine();
        void resetEngine();         //Resets the data members of the engine between each drive
        void start(float);          //To start the engine
        void runEngine();           //To run the engine
        void accelerate();          //To increase the rpm
        void decelerate();          //To reduce the rpm
        void calcEngineHeat();      //To calculate the engine heat
        void getEnergy(Battery*);   //To obtain energy from the battery
        void combustion();          //Imitates the combustion step in an Internal Combustion engine
        void intake();              //Imitates the intake step in an Internal Combustion engine
        void compression();         //Imitates the compression step in an Internal Combustion engine
        void exhaust();             //Imitates the exhaust step in an Internal Combustion engine
        void affectUsage(float);    //Calculates the effect of a factor on the usage
        void stopEngine();          //Stops the engine
        bool checkBattery();        //Checks the battery level
        bool checkEngineHeat();     //Checks if the engine is overheated
        void checkRPM();             //Checks if the RPM is too high and handles it
        float getUsage();           //Returns the usage of the engine
        float getTime();            //Returns the duration of the run
};