#include <iostream>
#include <thread>
#include <string>
#include "Car.h"
using namespace std;
/*
class Body
{
    private:
        float length;
        float width;
        float height;
        float wheelBase;
        float groundClearance;
        float aeroRatio;
    public:
        float getLength();
        float getWidth();
        float getHeight();
        float getWheelBase();
        float getGroundClearance();
        float getAeroRatio();
};*/

/*
class Tire
{
    private:
        char composition;       //Resists puncture
        float rimSize;
        float tyreBonding;      //Affects handling, stability and braking
        float tyreSize;
    public:
};



class Brake
{
    private:
        char brakeType;
        float fluidLevel;
        float fluidPressure;
        float brakeForce;
        float brakePedalRange;
    public:
};

class Environment
{
    private:
        float temperature;
        float humidity;
    public:
};

class Time
{
    private:
        int minutes;
        int seconds;
    public:
        void setTime();
        void getTime();
};
*/
int main()
{
    Car c;
    c.startCar();
    cout<<"SUCCESS"<<endl;
}