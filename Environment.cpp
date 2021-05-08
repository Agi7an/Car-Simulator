/*
File: Environment.cpp
Authors: Agilan and Arjuna
Contains the definition for the Environment header file
*/

#include <iostream>
#include <time.h>
#include "Environment.h"
#include "Logger.h"

using namespace std;
using namespace CPlusPlusLogging;

Environment::Environment()
{
    weatherRatio = 50;
    temperatureRatio = 80;
    roadCondition = 90;
    calcEnvRatio();
}

void Environment::calcEnvRatio()
{
    envRatio = (weatherRatio + temperatureRatio + roadCondition) / 3;
}

float Environment::getEnvRatio()
{
    return envRatio;
}

void Environment::logConditions()
{
    if(weatherRatio < 50)
    {
        LOG_INFO("The weather is pleasant and suitable for driving");
    }
    else if(weatherRatio < 75)
    {
        LOG_INFO("The weather is not great, but it is okay to drive");
    }
    else
    {
        LOG_ALARM("The weather is bad, driving now will greatly affect the car!");
    }

    if(temperatureRatio < 50)
    {
        LOG_INFO("The temperature is optimal and does not affect the car");
    }
    else if(temperatureRatio < 75)
    {
        LOG_INFO("The temperature is a bit harsh and has some effect on the car's usage");
    }
    else
    {
        LOG_ALARM("The temperature is extreme! Driving now will greatly affect the car");
    }

    if(roadCondition < 25)
    {
        LOG_INFO("The road is great!");
    }
    else if(roadCondition < 75)
    {
        LOG_INFO("The road is okay. Has affected the car a bit");
    }
    else
    {
        LOG_ALARM("The road is very bad! The car has received a lot of damage");
    }
}

void Environment::simulateConditions()
{
    srand(time(0));
    int random = rand();
    switch(random % 4)
    {
        case 0:
            weatherRatio = randomize(weatherRatio);
            break;

        case 1:
            temperatureRatio = randomize(temperatureRatio);
            break;
        case 2:
            roadCondition = randomize(roadCondition);
            break;

        default:
            weatherRatio = randomize(weatherRatio);
            temperatureRatio = randomize(temperatureRatio);
            roadCondition = randomize(roadCondition);
    }
    calcEnvRatio();
    logConditions();
}

float Environment::randomize(float value)
{
    int random2 = rand();
    if(random2 % 2 == 0 && value <= 75)
    {
        value += 25;
    }
    else if(random2 % 2 == 1 && value >= 25)
    {
        value -= 25;
    }
    return value;
}