/*
File: Environment.h
Authors: Agilan and Arjuna
Environment Header File
*/

#include <iostream>
#include <time.h>

using namespace std;

class Environment
{
    private:
        float weatherRatio;         //Weather rating
        float temperatureRatio;     //Temperature rating
        float roadCondition;        //Road conditions
        float envRatio;             //Overall environment ratio
    public:
        Environment();          
        void calcEnvRatio();        //Calculates 'envRatio'
        void simulateConditions();  //Randomly changes the weather, temperature and road conditions
        void logConditions();       //Logs the environment conditions
        float getEnvRatio();        //Returns 'envRatio'
        float randomize(float);     //Randomly affects the input and returns it
};