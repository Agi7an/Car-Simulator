#include "Errors.h"

const char* BatteryLowAlarm::what() const throw()
{
    return "Battery level too low, Please recharge battery";
}

const char* EngineOverloadAlarm::what() const throw()
{
    return "Engine is being pushed too much!";
}

const char* HighRPMAlarm::what() const throw()
{
    return "The RPM is too high!";
}

const char* InputValueAlarm::what() const throw()
{
    return "The value passed is not suitable";
}

const char* GearRangeAlarm::what() const throw()
{
    return "The driver is trying to switch to an unavailable gear!";
}