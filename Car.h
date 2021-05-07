#include "Engine.h"
#include "Driver.h"
#include <thread>
using namespace std;

class Car
{
    private:
        float weight;
        
        bool isOn;
        Engine* e;
        Driver* d;
        friend class Engine;
        
    public:
        Car() 
        {
            weight = 1524;
            e = new Engine;
            d = new Driver;
        }

        void startCar()
        {
            e->start();
            isOn = true;
            thread engine(&Engine::runEngine, e, d->getHandling());
            thread stop(&Car::stopCar, this);
            stop.join();
            engine.join();
        }

        void stopCar()
        {
            if(isOn)
            {
                cin.get();
                e->stopEngine();
                isOn = false;
            }
        }
        void accelerate();
        void decelerate();
        void reverse();
};