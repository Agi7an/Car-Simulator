/*
File: Transmission.cpp
Authors: Agilan and Arjuna
Contains the definition for the Transmission header file
*/

#include <string>
#include <iostream>
#include <thread>
#include "Transmission.h"
#include "Logger.h"
#include "Errors.h"

using namespace std;
using namespace CPlusPlusLogging;

Transmission::Transmission():gearRatio(0.03)
{
    currGear = 0;
    for(int i = 0; i < 4; i++)
    {
        ti[i] = new Tire;
    }
}

void Transmission::setGear(int val)
{
    try
    {
        if(val >= 0 && val <= 6)
        {
            currGear = val;
        }
        else
        {
            GearRangeAlarm e;
            throw e;
        }
    }
    catch(exception& e)
    {
        LOG_ALARM(e.what());
    }
    
    
}

float Transmission::getSpeed()
{
    return speed;
}

int Transmission::getCurrGear()
{
    return currGear;
}

void Transmission::clutch()
{
    clutchPressed = true;
    engage = !clutchPressed;
}

void Transmission::releaseClutch()
{
    clutchPressed = false;
    engage = !clutchPressed;
}

void Transmission::transmit(int rpm)     //Transmits power from engine to the wheels
{
    speed = gearRatio * rpm;
    for(int i = 0; i < 4; i++)
    {
        ti[i]->setSpeed(speed);
    }
}

void Transmission::shiftGearUp(int n)
{
    clutch();
    try
    {
        if(engage == false && n <= 2 && currGear + n <= 5)
        {
            currGear += n;
            ostringstream line;
            line<<"The gear now is "<<currGear<<endl;
            LOG_INFO(line);
        }
        else if(n > 2)
        {
            GearRangeAlarm e;
            throw e;
        }
        else if(engage == true)
        {
            LOG_ALARM("Press the clutch to disengage the engine from the transmission");
        }
        else
        {
            LOG_ALARM("Cannot change gears higher than 5!");
        }
    }
    catch(exception& e)
    {
        LOG_ALARM(e.what());
    }
    
    
    releaseClutch();
}

void Transmission::shiftGearDown(int n)
{
    clutch();
    try
    {
        if(n <= 2 && engage == false)
        {
            currGear -= n;
            ostringstream line;
            line<<"The gear now is "<<currGear<<endl;
            LOG_INFO(line);
        }
        else if(n > 2)
        {
            GearRangeAlarm e;
            throw e;
        }
        else
        {
            LOG_ALARM("Press the clutch to disengage the engine from the transmission");
        }
    }
    catch(exception& e)
    {
        LOG_ALARM(e.what());
    }
    releaseClutch();
}