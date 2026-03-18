#include "../include/ITemperatureControl.h"

class AirConditioner : public ITemperatureControl
{
public:
    void turnOn() override
    {
        On = true;
        std::cout << name << " is turned on." << std::endl;
    }
    void turnOff() override
    {
        On = false;
        std::cout << name << " is turned off." << std::endl;
    }
    std::string getStatus() override
    {
        return name + " is " + (On ? "On" : "Off") + " at " + std::to_string(temperature) + " degrees.";
    }
    std::string getname() override
    {        return name;
    }
    void setTemperature(double temperature) override
    {
        this->temperature = temperature;
        std::cout << name << " temperature set to " << temperature << " degrees." << std::endl;
    }
    double getTemperature() override
    {
        return temperature;
    }
private:
    std::string name;
    bool On;
    double temperature;
};
