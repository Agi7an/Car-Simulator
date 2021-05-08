/*
File: Car.cpp
Authors: Agilan and Arjuna
Contains the definition for Car.h
*/




#include <iostream>
#include <string>
#include <time.h>
#include <exception>
#include "Logger.h"
#include "Car.h"
//#include <thread>

using namespace std;
using namespace CPlusPlusLogging;       //For the Logger class members

Car::Car() 
{
    totalDuration = 0.0;
    e = new Engine;
    d = new Driver;
}

void Car::startCar(float conditions)
{
    isOn = true;
    LOG_INFO("The car has started\n");
    e->start(d->getHandling());         //The driver's handling rating is passed to the Engine::start(float) function
    e->affectUsage(conditions);         //The environment conditions are factored into the car's usage
    calcDuration();

    /*
    thread engine(&Engine::runEngine, e, d->getHandling());
    thread conditions(&Environment::simulateConditions);
    thread stop(&Car::stopCar, this);
    e->runEngine(d->getHandling());
    stop.join();
    engine.join();
    */
}

void Car::stopCar()
{
    LOG_INFO("The car has stopped\n");
    e->stopEngine();        //Calls the Engine::stopEngine()
    isOn = false;
}

bool Car::functional()
{
    if(e->checkBattery() && e->checkEngineHeat() && e->getUsage() < 97)
    {
        LOG_INFO("The car is functional\n");
        return true;
    }
    else
    {
        LOG_ALARM("The car is not functional anymore\n");
        return false;
    }
}

float Car::getUsage()
{
    return e->getUsage();
}

void Car::calcDuration()
{
    totalDuration += e->getTime();
}

float Car::getDuration()
{
    return totalDuration;
}

float Car::timeLeft()
{
    float usage = e->getUsage();
    float lifeLeft = (100 - usage) * totalDuration / usage;
    return lifeLeft;
}