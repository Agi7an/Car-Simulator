#include <exception>
using namespace std;

class BatteryLowAlarm: public exception
{
    virtual const char* what() const throw();
};

class EngineOverloadAlarm: public exception
{
    virtual const char* what() const throw();
};

class HighRPMAlarm: public exception
{
    virtual const char* what() const throw();
};

class InputValueAlarm: public exception
{
    virtual const char* what() const throw();
};

class GearRangeAlarm: public exception
{
    virtual const char* what() const throw();
};