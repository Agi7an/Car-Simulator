/*
File: Transmission.h
Authors: Agilan and Arjuna
Transmission Header File
*/

#include <iostream>
#include "Tire.h"

using namespace std;

class Transmission
{
    private:
        bool clutchPressed;
        int currGear;
        const float gearRatio;
        float speed;
        bool engage;
        Tire* ti[4];            //Transmission HAS 4 tires(Aggregation)

    public:
        Transmission();
        void setGear(int);          //Resets the gear to a specific gear
        void clutch();              //Activates the clutch and disengages the engine from the transmission
        void releaseClutch();       //Releases the clutch and engages the engine with the transmission
        void transmit(int);         //Transmits power from engine to the wheels
        void shiftGearUp(int);      //Shifts the gear up by the specified count
        void shiftGearDown(int n);  //Shifts the gear down by the specified count
        int getCurrGear();          //Returns the current gear the car is on
        float getSpeed();           //Returns the speed
};