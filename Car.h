#include "Engine.h"
#include <thread>
using namespace std;

class Car
{
    private:
        float weight;
        char driveTrainType;
        float axleRatio;
        bool isOn;
        Engine* e;
        Battery* ba;
        friend class Engine;
        
    public:
        Car() 
        {
            axleRatio = 3.73;
            e = new Engine;
            ba = new Battery;
        }

        void startCar()
        {
            e->start(ba);
            thread engine(&Engine::runEngine, e);
            engine.join();
            isOn = true;
        }

        void stopCar()
        {
            while(isOn)
            {
                if(e->getTorque() > 1.1)
                {
                    e->stopEngine();
                }
            }
        }
        void accelerate();
        void decelerate();
        void reverse();
};