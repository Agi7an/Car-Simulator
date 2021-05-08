/*
    CAR SIMULATOR
    
    File: main.cpp
    Authors: Agilan and Arjuna
    Date: 07/05/2021

    This program's main objective is to determine the lifetime of a car, by taking into consideration the various effects that 
    the environment, driver's experience and various other factors can have on the car. The program runs a number of simulation
    drives on the car and from the usage of the car in those drives, tries to predict the lifetime of the car. This program
    tries to recreate the complex mechanisms involved in a car as much as possible, by taking into consideration the engine,
    transmission, battery and tires. 

    This program can be useful to predict the lifetimes of different cars before buying them, by testing on them on specific
    external conditions.

    Compile Statement: g++ main.cpp Car.cpp Engine.cpp Battery.cpp Transmission.cpp Tire.cpp Environment.cpp Driver.cpp Logger.cpp Errors.cpp
*/


#include <iostream>
#include <string>
#include "Car.h"
#include "Environment.h"
#include "Logger.h"

using namespace std;
using namespace CPlusPlusLogging;       //For Logger

int main()
{
    ostringstream line;
    Car c;
    Environment E;
    LOG_ALWAYS("--------------------------------NEW SIMULATION--------------------------------");
    for(int i = 0; i < 10; i++)
    {
        if(c.functional())                      //If the car is functional, a new drive is started
        {
            LOG_ALWAYS("\n\n------------------------NEW DRIVE------------------------\n");
            c.startCar(E.getEnvRatio());
            E.simulateConditions();
            c.stopCar();
            LOG_ALWAYS("\n\n------------------------DRIVE ENDED------------------------\n");
        }
        else
        {
            cout<<"THE CAR IS NOT FUNCTIONAL ANYMORE"<<endl;
            LOG_ALARM("THE CAR IS NOT FUNCTIONAL ANYMORE");
            break;
        }
    }
    cout<<"Simulation Successfully Completed\n"<<endl;
    cout<<"The car ran for "<<c.getDuration()<<" units of time and has deteriorated "<<c.getUsage()<<"%"<<endl;
    cout<<"Following the above trend, the car will last for another "<<c.timeLeft()<<" units of time"<<endl;
    cout<<"\nTHANK YOU\n\n"<<endl;

    LOG_ALWAYS("------------SIMULATION SUMMARY------------");

    line<<"\n\nSimulation Duration: "<<c.getDuration()<<"units of time\nDeterioration: "<<c.getUsage()<<"%\nEstimated Duration Left: "<<c.timeLeft()<<" units of time"<<endl;
    LOG_INFO(line);

    LOG_ALWAYS("----------------------------------THANK YOU---------------------------------\n\n\n\n\n");
}