/*
File: Driver.cpp
Authors: Agilan and Arjuna
Contains the defintion for the Driver header file
*/

#include <iostream>
#include <string>
#include "Errors.h"
#include "Driver.h"
using namespace std;

Driver::Driver()
{
    name = "ANONYMOUS";          //By default the name is 'ANONYMOUS'
    handling = 90;             //By default the handling is 0.5
}

Driver::Driver(string name, float handling)
{
    try
    {
        this->name = name;
        this->handling = handling;
        if(handling < 0 || handling > 100)
        {
            InputValueAlarm e;
            throw e;
        }
    }
    catch(exception& e)
    {
        std::cerr << e.what() << '\n';
        cout<<"Enter the new handling for the driver: ";
        cin>>handling;
    }
}
    
float Driver::getHandling()
{
    return handling;
}