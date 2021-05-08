/*
File: Engine.cpp
Authors: Agilan and Arjuna
Contains the definition for the Engine header file
*/

#include <iostream>
#include <time.h>
#include "Errors.h"
#include "Logger.h"
#include "Engine.h"

using namespace std;
using namespace CPlusPlusLogging;       //For the logger

Engine::Engine()
{
    airLevel = false;
    fuelLevel = false;
    piston = false;
    rpm = 0;
    engineOn = false;
    engineHeat = 1;
    heatRatio = 1.5;
    timeRunning = 0.0;
    usage = 0.01;
    handling = 0.0;
    t = new Transmission;
    b = new Battery;
}

void Engine::resetEngine()
{
    airLevel = false;
    fuelLevel = false;
    piston = false;
    rpm = 0;
    engineHeat = 1;
    heatRatio = 1.5;
    timeRunning = 0.0;
    t->setGear(0);
}

void Engine::start(float handling)
{
    getEnergy(b);
    engineOn = true;
    this->handling = handling;
    LOG_INFO("The engine has started\n");
    usage += 0.005;         //Each time the engine is started, its usage increases
    runEngine();    //The usage of the engine while running depends on the handling of the user
}

bool Engine::checkBattery()
{
    try
    {
        if(b->getBattery() < 5)
        {
            LOG_ALARM("Battery Level too low. Cannot start the car");
            BatteryLowAlarm e;
            throw e; 
        }
        else
        {
            return true;
        }
    }
    catch(exception& e)
    {
        LOG_ALARM(e.what());
        return false;
    }
    catch(...)
    {
        LOG_ERROR("***UNKNOWN ERROR IN checkBattery()***");
        return false;
    }
}

void Engine::runEngine()
{
    LOG_INFO("The engine is running...");
    srand(time(0));
    int random = rand();
    t->shiftGearUp(1);
    while(engineOn && timeRunning < random / (float)100)
    {
        timeRunning += 1;
        usage += 0.001;

        intake();           //Air and fuel are taken in
        compression();      //The mixture is compressed
        combustion();       //Combustion pushes the piston back and produces power
        exhaust();          //The exhaust is pumped out
        if(random % 3 == 0)
        {
            if(t->getCurrGear() < 5)
            {
                accelerate();
            }
            else
            {
                srand(time(0));
                if(rand() % 2 == 0 && handling < 40)
                {
                    accelerate();
                }
            }
        }
        else if(random & 3 == 1)        //Simulates sudden obstacles in the path
        {
            decelerate();
        }
        else
        {
            void(0);
        }
        
        checkRPM();         //Checks the RPM and handles it accordingly
        t->transmit(rpm);   //Transmits the energy from the engine to the wheels
        calcEngineHeat();
    }
}

void Engine::accelerate()
{
    rpm = rpm + 0.05 * MAX_RPM;
}

void Engine::decelerate()
{
    rpm = rpm - 0.05 * MAX_RPM;
}

void Engine::calcEngineHeat()
{
    engineHeat = timeRunning * heatRatio;
}

bool Engine::checkEngineHeat()
{
    if(engineHeat < 95)
    {
        return true;
    }
    else
    {
        LOG_ALARM("The engine is getting too hot!\n");
        return false;
    }
}

void Engine::getEnergy(Battery* ba)
{
    b->calcBattery();
}

void Engine::combustion()
{
    if(airLevel && fuelLevel && piston)
    {
        if(rpm < MAX_RPM)
        {
            rpm += 5;
        }
        piston = false;
    }
    else
    {
        LOG_ALARM("Combustion Error");
    }
}

void Engine::intake()
{
    airLevel = true;
}

void Engine::compression()
{
    if(piston == false)
    {
        piston = true;
        fuelLevel = true;
    }
    else
    {
        LOG_ALARM("Compression Error");
    }
}

void Engine::exhaust()
{
    airLevel = false;
    fuelLevel = false;
}

void Engine::checkRPM()
{
    try
    {
        if(rpm > MAX_RPM - 0.10 * MAX_RPM && t->getCurrGear() <= 4)
        {
            t->shiftGearUp(1);                  //RPM is too high, so shifts a gear up
            rpm = rpm - MAX_RPM * 0.5;
            HighRPMAlarm e;
            throw e;
        }
        else if(rpm > MAX_RPM - 0.10 * MAX_RPM && t->getCurrGear() == 5)
        {
            if(handling >= 65)                //RPM is too high and already at max gear. Depending upon the driver's handling, this situation is managed
            {
                decelerate();
            }
            else if(handling < 65 && handling > 45)
            {
                srand(time(0));
                if(rand() % 2 == 0)
                {
                    decelerate();
                }
                else
                {
                    usage += 0.005;
                    EngineOverloadAlarm e;
                    throw e;
                }
            }
            else
            {
                srand(time(0));
                if(rand() % 3 == 1)
                {
                    decelerate();
                }
                else
                {
                    usage += 0.005;
                    EngineOverloadAlarm e;
                    throw e;
                }
            }
        }
        else
        {
            ostringstream line;
            line<<"Current RPM : "<<rpm<<"\n"<<"Current Gear : "<<t->getCurrGear()<<endl;
            LOG_INFO(line);
        }
    }
    catch(exception& e)
    {
        LOG_ALARM(e.what());
    }
    catch(...)
    {
        LOG_ERROR("***UNKNOWN ERROR IN checkRPM()***");
    }
}

float Engine::getUsage()
{
    return usage;
}

float Engine::getTime()
{
    return timeRunning;
}

void Engine::affectUsage(float factor)
{
    usage = usage + factor / 100;
}

void Engine::stopEngine()
{
    affectUsage(engineHeat);
    affectUsage(usage);
    engineOn = false;
    resetEngine();
}