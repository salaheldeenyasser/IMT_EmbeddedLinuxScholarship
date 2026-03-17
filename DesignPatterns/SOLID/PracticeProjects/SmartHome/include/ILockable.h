#include "IDevice.h"

class Ilockable : public IDevice
{
    public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual bool isLocked() = 0;
    virtual ~Ilockable() = default;
};