#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include "Battery.h"
using namespace std;

class Engine
{
    private:
        string type;
        int cylindersCount;
        float maxPower;
        float horsepower;
        float torque;
        bool airLevel;
        bool fuelLevel;
        bool piston;
        int rpm;
        bool engineOn;
        float engineHeat;
        float heatRatio;
        double timeRunning;
    public:
        Engine()
        {
            type = "ic";
            cylindersCount = 8;
            maxPower = 1200;
            horsepower = 0;
            torque = 0;
            airLevel = false;
            fuelLevel = false;
            piston = false;
            rpm = 0;
            engineOn = false;
            engineHeat = 0.01;
            heatRatio = 0.01;
            timeRunning = 0.0;
        }

        void start(Battery* ba)
        {
            if(ba->batteryLevel < 0.05)
            {
                cout<<"Battery Level too low\nCannot start the car"<<endl;
            }
            else
            {
                getEnergy(ba);
                engineOn = true;
            }
        }

        void runEngine()
        {
            while(engineOn && engineHeat < 0.9)
            {
                timeRunning += 0.1;
                cout<<"Engine running..."<<endl;
                intake();
                compression();
                combustion();
                exhaust();
                calcEngineHeat();
            }
        }

        void calcEngineHeat()
        {
            engineHeat = timeRunning * heatRatio;
            cout<<engineHeat<<endl;
        }

        void getEnergy(Battery* ba)
        {
            srand(time(0));
            ba->batteryLevel -= rand() % 5 / 1000 * ba->batteryLevel;
            torque = 1;
        }

        float getTorque()
        {
            return torque;
        }

        void combustion()
        {
            if(airLevel && fuelLevel && piston)
            {
                torque += rand() % 5 / 1000 * torque;
                horsepower = torque * rpm / 5.252;
                piston = false;
            }
            else
            {
                cout<<"Combustion Error"<<endl;
            }
        }

        void intake()
        {
            airLevel = true;
        }

        void compression()
        {
            if(piston == false)
            {
                piston = true;
                fuelLevel = true;
            }
            else
            {
                cout<<"Compression Error"<<endl;
            }
        }

        void exhaust()
        {
            airLevel = false;
            fuelLevel = false;
        }

        void stopEngine()
        {
            engineOn = false;
        }
};