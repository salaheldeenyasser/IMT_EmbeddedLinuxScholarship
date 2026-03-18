#include <iostream>
#include <mutex>

// Smart Home System Manager (singleton pattern)

class HomeSystemManager
{
    public:
    static HomeSystemManager &getInstance()
    {
        static HomeSystemManager instance;
        return instance;
    }

    void logEvent(const std::string &event)
    {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Event: " << event << std::endl;
    }

    void printStatus()
    {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Home: " << homeName << ", Total Devices: " << totalDevices << ", Total Actions: " << totalActions << std::endl;
    }

    void printLog()
    {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Event log for " << homeName << ":" << std::endl;
    }

    private:
    static HomeSystemManager *instance;
    HomeSystemManager() : homeName("My Smart Home"), totalDevices(0), totalActions(0) {}
    ~HomeSystemManager() = default;
    std::string homeName;
    int totalDevices;
    int totalActions;
    std::mutex mutex;

};

// Device Config (Builder pattern)

class DeviceConfig
{

