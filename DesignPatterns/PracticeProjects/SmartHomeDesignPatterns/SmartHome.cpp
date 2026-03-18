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
public:
    void setName(const std::string &name)
    {
        this->name = name;
    }

    void setType(const std::string &type)
    {
        this->type = type;
    }

    void setRoom(const std::string &room)
    {
        this->room = room;
    }

    void setPower(int power)
    {
        this->power = power;
    }

    void setIP(const std::string &ip)
    {
        this->ip = ip;
    }

    void setOnline(bool isOnline)
    {
        this->isOnline = isOnline;
    }

    void setSchedule(bool schedule)
    {
        this->schedule = schedule;
    }

    void setScheduleOn(const std::string &scheduleOn)
    {
        this->scheduleOn = scheduleOn;
    }

    void setScheduleOff(const std::string &scheduleOff)
    {
        this->scheduleOff = scheduleOff;
    }

private:
    std::string name;
    std::string type;
    std::string room;
    int power = 0;
    std::string ip = "192.168.1.1";
    bool isOnline = true;
    bool schedule = false;
    std::string scheduleOn;
    std::string scheduleOff;
};
