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