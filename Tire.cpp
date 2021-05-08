/*
File: Tire.cpp
Authors: Agilan and Arjuna
Contains the definition for the Tire header file
*/

#include "Tire.h"
#include <iostream>

using namespace std;

Tire::Tire()
{
    speed = 0;
    deterioration = 0;
    pressureLevel = 35;     //in psi
}

void Tire::setSpeed(float value)
{
    speed = value;
}

void Tire::use(float usage)
{
    deterioration = usage;
    pressureLevel = 35 * (1 - usage);
}

bool Tire::pressureLow()
{
    if(pressureLevel < 30)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tire::changeTire()
{
    if(deterioration > 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}