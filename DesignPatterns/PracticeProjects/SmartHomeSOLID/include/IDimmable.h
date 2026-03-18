#include "IDevice.h"

class IDimmable : public IDevice
{public:
    virtual void setLevel(int level) = 0;
    virtual int getLevel() = 0;
    virtual ~IDimmable() = default;
};