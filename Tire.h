#include <iostream>
using namespace std;

class Tire
{
    private:
        float speed;
        float deterioration;
        float pressureLevel;
        char status;
    public:
        Tire()
        {
            speed = 0;
            deterioration = 0;
            pressureLevel = 35;     //in psi
            status = 'E';
        }

        void setSpeed(float value)
        {
            speed = value;
        }

        void use(float usage)
        {
            deterioration = usage;
            pressureLevel = 35 * (1 - usage);
        }

        bool pressureLow()
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

        bool changeTire()
        {
            if(deterioration > 0.5)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};