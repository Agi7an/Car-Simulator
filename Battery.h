class Battery
{
    private:
        float batteryLevel;
        friend class Engine;
    public:
        Battery();
        float calcBattery(float);
};

Battery::Battery()
{
    batteryLevel = 1.0;
}

float Battery::calcBattery(float usage)
{
    batteryLevel = 1 - usage;
    return batteryLevel;
}