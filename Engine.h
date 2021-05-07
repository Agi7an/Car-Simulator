#include <iostream>
#include <string>
#include <time.h>
#include "Battery.h"
#include "Transmission.h"
using namespace std;

#define MAX_RPM 1000
#define MAX_TORQUE 120
#define MAX_HP 80

class Engine
{
    private:
        string type;
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
        float usage;
        Battery* b;
        Transmission* t;
    public:
        Engine()
        {
            type = "ic";
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
            usage = 0.0;
            t = new Transmission;
            b = new Battery;
        }

        void start()
        {
            if(b->calcBattery(usage) < 0.05)
            {
                cout<<"Battery Level too low\nCannot start the car"<<endl;
            }
            else
            {
                getEnergy(b);
                engineOn = true;
                usage += 0.01;
            }
        }

        void runEngine(float handling)
        {
            //while(engineOn && engineHeat < 0.9)
            while(engineOn)
            {
                timeRunning += 0.1;
                usage += 0.0001;
                cout<<"Engine running..."<<endl;
                intake();
                compression();
                combustion();
                exhaust();
                switch(checkRPM())
                {
                    case 1:
                        t->shiftGearUp(1);
                        rpm -= MAX_RPM * 0.25;
                        break;
                    case 0:
                        cout<<"The engine is being pushed too much!"<<endl;
                        if(handling >= 0.75)
                        {
                            decelerate();
                        }
                        else if(handling < 0.75 && handling > 0.5)
                        {
                            srand(time(0));
                            if(rand() % 2 == 0)
                            {
                                decelerate();
                            }
                        }
                        else
                        {
                            srand(time(0));
                            if(rand() % 3 == 1)
                            {
                                decelerate();
                            }
                        }
                        usage += 0.1;
                        break;
                    case -1:
                        cout<<"Current RPM : "<<rpm<<endl;
                        cout<<"Current Gear : "<<t->getCurrGear()<<endl;
                }
                t->transmit(rpm);
                calcEngineHeat();
            }
        }

        void decelerate()
        {
            rpm -= 0.25 * MAX_RPM;
        }

        void calcEngineHeat()
        {
            engineHeat = timeRunning * heatRatio;
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
                if(rpm < MAX_RPM)
                {
                    rpm += 1;
                }
                if(torque < MAX_TORQUE)
                {
                    torque += rand() % 5 / 1000 * torque;
                }
                horsepower = torque * rpm / 7120.5;
                piston = false;
                //cout<<"Combustion"<<endl;
            }
            else
            {
                cout<<"Combustion Error"<<endl;
            }
        }

        void intake()
        {
            airLevel = true;
            //cout<<"Intake"<<endl;
        }

        void compression()
        {
            if(piston == false)
            {
                piston = true;
                fuelLevel = true;
                //cout<<"Compression"<<endl;
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
            //cout<<"Exhaust"<<endl;
        }

        int checkRPM()
        {
            if(rpm > MAX_RPM - 0.25 * MAX_RPM && t->getCurrGear() <= 4)
            {
                cout<<"TOO MUCH RPM, Please change gear"<<endl;
                return 1;
            }
            else if(rpm > MAX_RPM - 0.25 * MAX_RPM && t->getCurrGear() == 5)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        float getUsage()
        {
            return usage;
        }

        void stopEngine()
        {
            engineOn = false;
        }
};