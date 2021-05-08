/*
File: Driver.h
Authors: Agilan and Arjuna
Driver Header File
*/

#include <iostream>
#include <string>
using namespace std;

class Driver
{
    private:
        string name;        //Driver's name
        float handling;     //Driver's handling rating/experience
    public:
        Driver();
        Driver(string, float);
        float getHandling();        //Returns the driver's handling
};