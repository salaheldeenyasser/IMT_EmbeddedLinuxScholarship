#include "IDevice.h"

class ITemperatureControl : public IDevice
{
public:
    virtual void setTemperature(double temperature) = 0;
    virtual double getTemperature() = 0;
    virtual ~ITemperatureControl() = default;
};