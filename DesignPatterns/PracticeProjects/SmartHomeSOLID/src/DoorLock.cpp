#include "../include/ILockable.h"

class DoorLock : public Ilockable
{
public:
    void turnOn() override
    {
        std::cout << name << " is ready to lock." << std::endl;
    }
    void turnOff() override
    {
        std::cout << name << " is ready to unlock." << std::endl;
    }
    std::string getStatus() override
    {
        return name + " is " + (isLocked ? "Locked" : "Unlocked") + ".";
    }
    std::string getname() override
    {        return name;
    }
    void lock() override
    {
        Locked = true;
        std::cout << name << " is locked." << std::endl;
    }
    void unlock() override
    {
        Locked = false;
        std::cout << name << " is unlocked." << std::endl;
    }
    bool isLocked() override
    {
        return Locked;
    }

private:
    std::string name;
    bool Locked;
};