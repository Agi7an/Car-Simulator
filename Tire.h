/*
File: Tire.h
Authors: Agilan and Arjuna
Tire Header File
*/

#include <iostream>

using namespace std;

class Tire
{
    private:
        float speed;            //Speed of the tire
        float deterioration;    //Deterioration of the tire
        float pressureLevel;    //Pressure level of the air in the tire
    public:
        Tire();
        void setSpeed(float value);     //Sets the tire's speed. Transmission transmits the energy from the engine to the wheels
        void use(float usage);          //The usage of the tires
        bool pressureLow();             //Checks if the air pressure is too low
        bool changeTire();              //Returns true if the tire has to be changed
};