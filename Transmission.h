#include <string>
#include <iostream>
#include <thread>
#include "Tire.h"
using namespace std;

class Transmission
{
    private:
        string type;      //Automatic or Manual
        bool clutchPressed;
        float maxSpeed[6];
        int currGear;
        float gearRatio;
        float speed;
        bool engage;
        Tire* ti[4];
    public:
        Transmission()
        {
            type = "man";
            maxSpeed[0] = 130;
            maxSpeed[1] = 40;
            maxSpeed[2] = 60;
            maxSpeed[3] = 80;
            maxSpeed[4] = 100;
            maxSpeed[5] = 130;
            maxSpeed[6] = -20;
            currGear = 0;
            gearRatio = 0.02;
            for(int i = 0; i < 4; i++)
            {
                ti[i] = new Tire;
            }
        }

        int getCurrGear()
        {
            return currGear;
        }

        void clutch()
        {
            clutchPressed = true;
            engage = !clutchPressed;
        }

        void releaseClutch()
        {
            clutchPressed = false;
            engage = !clutchPressed;
        }

        void transmit(int rpm)     //Transmits power from engine to the wheels
        {
            speed = gearRatio * rpm;
            for(int i = 0; i < 4; i++)
            {
                ti[i]->setSpeed(speed);
            }
        }

        void shiftGearUp(int n)
        {
            clutch();
            if(engage == false && n <= 2 && currGear + n <= 5)
            {
                currGear += n;
                clutchPressed = false;
                engage = !clutchPressed;
                cout<<"The gear now is "<<currGear<<endl;
            }
            else if(n > 2)
            {
                cout<<"Cannot change gears from "<<currGear<<" to "<<currGear + n<<endl;
            }
            else if(engage == true)
            {
                cout<<"Press the clutch to disengage the engine from the transmission"<<endl;
            }
            //else if(currGear + n > 5)
            else
            {
                cout<<"Cannot change gears higher than 5!"<<endl;
            }
        }

        float shiftGearDown(int currGear, int gear)
        {
            if(currGear - gear <= 2 && engage == false)
            {
                this->currGear = currGear;
                return currGear;
            }
            else if(currGear - gear > 2)
            {
                cout<<"Cannot change gears from "<<currGear<<" to "<<gear<<endl;
                return INT_MIN;
            }
            else
            {
                cout<<"Press the clutch to disengage the engine from the transmission"<<endl;
                return INT_MIN;
            }
        }
};