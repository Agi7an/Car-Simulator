#include <string>
using namespace std;

class Transmission
{
    private:
        string type;      //Automatic or Manual
        bool clutchPressed;
        float gearRatio;
        float firstGearRatio;
        float secondGearRatio;
        float thirdGearRatio;
        float fourthGearRatio;
        float fifthGearRatio;
        float revGearRatio;
        float speedRatio;
        float torqueRatio;
        int RPM;
        float speed;
        bool engage;
    public:
        Transmission()
        {
            type = "auto";
            firstGearRatio = 2.97;      //For every 2.97 rotations of the gear, the wheel completes one rotation
            secondGearRatio = 2.07;
            thirdGearRatio = 1.43;
            fourthGearRatio = 1.00;
            fifthGearRatio = 0.84;
            revGearRatio = -3.38;
        }
        void clutch();
        int calcRPM()
        {
            RPM = / gearRatio;
        }
        void transmission();        //Transmits power from engine to the wheels
        void shiftGearUp();
        void shiftGearDown();
};