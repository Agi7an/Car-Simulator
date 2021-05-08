/*
File: Battery.h
Authors: Agilan and Arjuna
Battery Header File
*/


class Battery
{
    private:
        float batteryLevel;     //Indicates the current battery level
    public:
        Battery();
        void calcBattery();     //To calculate the battery drained and battery level left
        float getBattery();     //Getter to access the battery level in the battery
};