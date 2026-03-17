#include <iostream>
#include <cstring>
#include <vector>
#include <memory>

class IDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getStatus() = 0;
    virtual std::string getname() = 0;
    virtual ~IDevice() = default;
};

class IDimmable : public IDevice
{public:
    virtual void setLevel(int level) = 0;
    virtual int getLevel() = 0;
    virtual ~IDimmable() = default;
};

class Ilockable : public IDevice
{
    public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual bool isLocked() = 0;
    virtual ~Ilockable() = default;
};

class ITemperatureControl : public IDevice
{
public:
    virtual void setTemperature(double temperature) = 0;
    virtual double getTemperature() = 0;
    virtual ~ITemperatureControl() = default;
};

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

class SmartHomeController
{
public:
    void addDevice(std::shared_ptr<IDevice> device)
    {
        devices.push_back(device);
        std::cout << device->getname() << " added to Smart Home." << std::endl;
    }
    void activateAll()
    {
        for (auto device : devices)
        {
            device->turnOn();
        }
    }
    void deactivateAll()
    {
        for (auto device : devices)
        {
            device->turnOff();
        }
    }
    void printAllStatus()
    {
        for (auto device : devices)
        {
            std::cout << device->getStatus() << std::endl;
        }
    }
private:
    std::vector<std::shared_ptr<IDevice>> devices;
};

int main(){
    SmartHomeController controller;

    Light livingRoomLight;
    Fan bedroomFan;
    DoorLock frontDoorLock;
    AirConditioner ac;

    controller.addDevice(std::make_shared<Light>(livingRoomLight));
    controller.addDevice(std::make_shared<Fan>(bedroomFan));
    controller.addDevice(std::make_shared<DoorLock>(frontDoorLock));
    controller.addDevice(std::make_shared<AirConditioner>(ac));

    controller.activateAll();
    controller.printAllStatus();

    livingRoomLight.setLevel(75);
    bedroomFan.setLevel(3);
    frontDoorLock.lock();
    ac.setTemperature(22.5);

    controller.printAllStatus();

    controller.deactivateAll();
    controller.printAllStatus();

    return 0;
}