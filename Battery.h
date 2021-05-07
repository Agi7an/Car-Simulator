class Battery
{
    private:
        float batteryLevel;
        friend class Engine;
    public:
        Battery();
};

Battery::Battery()
{
    batteryLevel = 1.0;
}