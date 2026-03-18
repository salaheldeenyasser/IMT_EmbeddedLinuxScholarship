#include "../include/IDimmable.h"

class Fan : public IDimmable
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
        return name + " is " + (On ? "On" : "Off") + " at level " + std::to_string(speed) + ".";
    }
    std::string getname() override
    {        return name;
    }
    void setLevel(int speed) override   {
        this->speed = speed;
        std::cout << name << " speed set to " << speed << "." << std::endl;
    }
    int getLevel() override
    {
        return speed;
    }
private:
    std::string name;
    bool On;
    int speed;
};