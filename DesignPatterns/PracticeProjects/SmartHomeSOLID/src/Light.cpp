#include "../include/IDimmable.h"

class Light : public IDimmable
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
        return name + " is " + (On ? "On" : "Off") + " at level " + std::to_string(level) + ".";
    }
    std::string getname() override
    {        return name;
    }
    void setLevel(int level) override   {
        this->level = level;
        std::cout << name << " brightness set to " << level << "." << std::endl;
    }
    int getLevel() override
    {
        return level;
    }


private:
    std::string name;
    bool On;
    int level;

};