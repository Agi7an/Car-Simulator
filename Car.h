/*
File: Car.h
Authors: Agilan and Arjuna
Car Header File
*/

#include "Engine.h"
#include "Driver.h"
using namespace std;

class Car
{
    private:
        bool isOn;          //True if  the car is on, otherwise false
        float totalDuration;
        Engine* e;          //The car HAS A engine(Composition)
        Driver* d;          //The car HAS A driver(Association)
        
    public:
        Car();
        void startCar(float);   //Starts the car and makes 'isOn' true
        void stopCar();         //Stops the car and makes 'isOn' false
        void calcDuration();    //Adds the duration of each run
        float getUsage();       //Returns how much the car has been used
        float timeLeft();       //Returns the lifetime of the car left
        float getDuration();    //Returns the duration of the simulation
        bool functional();      //Checks if the car is still functional
};