#include <iostream>
#include <string>
using namespace std;

class Driver
{
    private:
        string name;
        float handling;
    public:
        Driver()
        {
            name = "ANONYMOUS";
            handling = 0.75;
        }

        float getHandling()
        {
            return handling;
        }
};