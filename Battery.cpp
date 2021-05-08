/*
File: Battery.cpp
Authors: Agilan and Arjuna
.cpp file for defining the member functions of the Battery.h class
*/


#include <iostream>
#include "Battery.h"        //File specific header
using namespace std;

Battery::Battery()
{
    batteryLevel = 100;     //Starting with a battery level of 1
}

float Battery::getBattery()
{
    return batteryLevel;
}

void Battery::calcBattery()
{
    batteryLevel = batteryLevel - rand() % 5 / (float)100;     //Each time the engine is started, this function is called and the bettery level reduces a bit
}