#include <iostream>
#include <mutex>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string WHITE   = "\033[37m";
    const std::string BOLD    = "\033[1m";
}

void printHeader(const std::string& title) {
    std::cout << "\n" << Color::BOLD << Color::CYAN
              << "╔══════════════════════════════════════════════╗\n"
              << "║  " << title;
    int pad = 42 - static_cast<int>(title.size());
    for (int i = 0; i < pad; ++i) std::cout << " ";
    std::cout << "║\n"
              << "╚══════════════════════════════════════════════╝"
              << Color::RESET << "\n";
}

void printSection(const std::string& s) {
    std::cout << Color::BOLD << Color::YELLOW
              << "\n  ── " << s << " ──\n"
              << Color::RESET;
}

void printLine() {
    std::cout << Color::CYAN
              << "  ──────────────────────────────────────────────\n"
              << Color::RESET;
}

class DeviceConfig {
public:
    void setName(const std::string& name)               { this->name = name; }
    std::string getName() const                          { return name; }
    void setType(const std::string& type)               { this->type = type; }
    std::string getType() const                          { return type; }
    void setRoom(const std::string& room)               { this->room = room; }
    std::string getRoom() const                          { return room; }
    void setPower(int power)                             { this->power = power; }
    int getPower() const                                 { return power; }
    void setIP(const std::string& ip)                   { this->ip = ip; }
    std::string getIP() const                            { return ip; }
    void setOnline(bool isOnline)                        { this->online = isOnline; }
    bool getOnline() const                               { return online; }
    void setSchedule(bool schedule)                      { this->schedule = schedule; }
    bool getSchedule() const                             { return schedule; }
    void setScheduleOn(const std::string& scheduleOn)   { this->scheduleOn = scheduleOn; }
    std::string getScheduleOn() const                    { return scheduleOn; }
    void setScheduleOff(const std::string& scheduleOff) { this->scheduleOff = scheduleOff; }
    std::string getScheduleOff() const                   { return scheduleOff; }

    void print() const {
        std::cout << "Device Config:\n"
                  << "  Name: "     << name << "\n"
                  << "  Type: "     << type << "\n"
                  << "  Room: "     << room << "\n"
                  << "  Power: "    << power << "W\n"
                  << "  IP: "       << ip << "\n"
                  << "  Online: "   << (online ? "Yes" : "No") << "\n"
                  << "  Schedule: " << (schedule
                                        ? ("ON at " + scheduleOn + ", OFF at " + scheduleOff)
                                        : "No") << "\n";
    }

private:
    std::string name;
    std::string type;
    std::string room;
    int power        = 0;
    std::string ip   = "192.168.1.1";
    bool online      = true;
    bool schedule    = false;
    std::string scheduleOn;
    std::string scheduleOff;
};

class DeviceBuilder {
public:
    DeviceBuilder& setName(const std::string& name)   { config.setName(name);   return *this; }
    DeviceBuilder& setType(const std::string& type)   { config.setType(type);   return *this; }
    DeviceBuilder& setRoom(const std::string& room)   { config.setRoom(room);   return *this; }
    DeviceBuilder& setPower(int power)                { config.setPower(power); return *this; }
    DeviceBuilder& setIP(const std::string& ip)       { config.setIP(ip);       return *this; }
    DeviceBuilder& setOnline(bool isOnline)           { config.setOnline(isOnline); return *this; }

    DeviceBuilder& setSchedule(const std::string& on, const std::string& off) {
        config.setSchedule(true);
        config.setScheduleOn(on);
        config.setScheduleOff(off);
        return *this;
    }

    DeviceConfig build() { return config; }

private:
    DeviceConfig config;
};

class HomeSystemManager {
public:
    static HomeSystemManager& getInstance() {
        static HomeSystemManager instance;
        return instance;
    }

    void logEvent(const std::string& event) {
        std::lock_guard<std::mutex> lock(mutex_);
        eventLog.push_back(event);
        std::cout << "Event: " << event << "\n";
    }

    void incrementDevices() {
        std::lock_guard<std::mutex> lock(mutex_);
        ++totalDevices;
    }

    void incrementActions() {
        std::lock_guard<std::mutex> lock(mutex_);
        ++totalActions;
    }

    void printStatus() {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << "Home: " << homeName
                  << ", Total Devices: " << totalDevices
                  << ", Total Actions: " << totalActions << "\n";
    }

    void printLog() {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << "Event log for " << homeName << ":\n";
        for (const auto& e : eventLog)
            std::cout << "  [LOG] " << e << "\n";
    }

    void printConfig(const DeviceConfig& config) {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << "Device Config for " << config.getName() << ":\n";
        config.print();
    }

    void setHomeName(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex_);
        homeName = name;
    }

private:
    HomeSystemManager()
        : homeName("My Smart Home"), totalDevices(0), totalActions(0) {}
    ~HomeSystemManager() = default;
    HomeSystemManager(const HomeSystemManager&)            = delete;
    HomeSystemManager& operator=(const HomeSystemManager&) = delete;

    std::string              homeName;
    int                      totalDevices;
    int                      totalActions;
    std::vector<std::string> eventLog;
    std::mutex               mutex_;
};

class ISmartDevice {
public:
    virtual void        turnOn()          = 0;
    virtual void        turnOff()         = 0;
    virtual std::string getStatus()       = 0;
    virtual std::string getName()         = 0;
    virtual int         getPower() const  { return 0; }
    virtual ~ISmartDevice()               = default;
};

class OldThermometer {
public:
    void activate()   { std::cout << "Activating legacy device\n"; }
    void deactivate() { std::cout << "Deactivating legacy device\n"; }
    std::string readSensor()              { return "Legacy device sensor data"; }
    float readTemperatureCelsius()        { return 25.0f; }
    void simulateReading(float temp) {
        std::cout << "Simulating temperature reading: " << temp << "°C\n";
    }
};

class LegacyDeviceAdapter : public ISmartDevice {
public:
    LegacyDeviceAdapter(OldThermometer& legacyDevice,
                        const std::string& name,
                        const std::string& room)
        : legacyDevice(legacyDevice), deviceName(name), deviceRoom(room) {}

    void        turnOn()   override { legacyDevice.activate(); }
    void        turnOff()  override { legacyDevice.deactivate(); }
    std::string getStatus() override {
        return "Temperature: " + std::to_string(legacyDevice.readTemperatureCelsius());
    }
    std::string getName() override { return deviceName; }

private:
    OldThermometer& legacyDevice;
    std::string     deviceName;
    std::string     deviceRoom;
};

class SmartLight : public ISmartDevice {
public:
    SmartLight(const DeviceConfig& config)
        : config(config), brightness(100), color("White"), on(false) {}

    void turnOn()  override { on = true;  std::cout << "Turning on light: "  << config.getName() << "\n"; }
    void turnOff() override { on = false; std::cout << "Turning off light: " << config.getName() << "\n"; }
    std::string getStatus() override { return on ? "Light is on" : "Light is off"; }
    std::string getName()   override { return config.getName(); }
    int  getPower() const   override { return config.getPower(); }

    void setBrightness(int b) {
        brightness = b;
        std::cout << "  Brightness set to " << b << "% on " << config.getName() << "\n";
    }
    void setColor(const std::string& c) {
        color = c;
        std::cout << "  Color set to \"" << c << "\" on " << config.getName() << "\n";
    }

private:
    DeviceConfig config;
    int          brightness;
    std::string  color;
    bool         on;
};

class SmartAC : public ISmartDevice {
public:
    SmartAC(const DeviceConfig& config)
        : config(config), temperature(24.0), mode("Cool"), on(false) {}

    void turnOn()  override { on = true;  std::cout << "Turning on AC: "  << config.getName() << "\n"; }
    void turnOff() override { on = false; std::cout << "Turning off AC: " << config.getName() << "\n"; }
    std::string getStatus() override { return on ? "AC is on" : "AC is off"; }
    std::string getName()   override { return config.getName(); }
    int  getPower() const   override { return config.getPower(); }

    void setTemperature(double t) {
        temperature = t;
        std::cout << "  Temperature set to " << t << "°C on " << config.getName() << "\n";
    }
    void setMode(const std::string& m) {
        mode = m;
        std::cout << "  Mode set to \"" << m << "\" on " << config.getName() << "\n";
    }

private:
    DeviceConfig config;
    double       temperature;
    std::string  mode;
    bool         on;
};

class SmartLock : public ISmartDevice {
public:
    SmartLock(const DeviceConfig& config)
        : config(config), locked(true) {}

    void turnOn()  override { locked = true;  std::cout << "Locking: "   << config.getName() << "\n"; }
    void turnOff() override { locked = false; std::cout << "Unlocking: " << config.getName() << "\n"; }
    std::string getStatus() override { return locked ? "Lock is locked" : "Lock is unlocked"; }
    std::string getName()   override { return config.getName(); }

    void lock(const std::string& by) {
        locked = true;
        std::cout << "  " << config.getName() << " locked by " << by << "\n";
    }
    void unlock(const std::string& by) {
        locked = false;
        std::cout << "  " << config.getName() << " unlocked by " << by << "\n";
    }

private:
    DeviceConfig config;
    bool         locked;
};

class SmartCamera : public ISmartDevice {
public:
    SmartCamera(const DeviceConfig& config)
        : config(config), recording(false), on(false) {}

    void turnOn()  override { on = true;  std::cout << "Turning on camera: "  << config.getName() << "\n"; }
    void turnOff() override { on = false; recording = false;
                              std::cout << "Turning off camera: " << config.getName() << "\n"; }
    std::string getStatus() override {
        return on ? (recording ? "Camera recording" : "Camera is on") : "Camera is off";
    }
    std::string getName() override { return config.getName(); }

    void startRecording() {
        recording = true;
        std::cout << "  " << config.getName() << " started recording\n";
    }
    void detectMotion() {
        std::cout << "  Motion detected by " << config.getName() << "\n";
    }

private:
    DeviceConfig config;
    bool         recording;
    bool         on;
};

class IDeviceFactory {
public:
    virtual std::unique_ptr<ISmartDevice> createDevice(DeviceConfig config)      = 0;
    virtual std::unique_ptr<ISmartDevice> manufactureDevice(DeviceConfig config) = 0;
    virtual ~IDeviceFactory() = default;
};

class LightFactory : public IDeviceFactory {
public:
    std::unique_ptr<ISmartDevice> createDevice(DeviceConfig config)      override { return std::make_unique<SmartLight>(config); }
    std::unique_ptr<ISmartDevice> manufactureDevice(DeviceConfig config) override { return createDevice(config); }
};

class ACFactory : public IDeviceFactory {
public:
    std::unique_ptr<ISmartDevice> createDevice(DeviceConfig config)      override { return std::make_unique<SmartAC>(config); }
    std::unique_ptr<ISmartDevice> manufactureDevice(DeviceConfig config) override { return createDevice(config); }
};

class LockFactory : public IDeviceFactory {
public:
    std::unique_ptr<ISmartDevice> createDevice(DeviceConfig config)      override { return std::make_unique<SmartLock>(config); }
    std::unique_ptr<ISmartDevice> manufactureDevice(DeviceConfig config) override { return createDevice(config); }
};

class CameraFactory : public IDeviceFactory {
public:
    std::unique_ptr<ISmartDevice> createDevice(DeviceConfig config)      override { return std::make_unique<SmartCamera>(config); }
    std::unique_ptr<ISmartDevice> manufactureDevice(DeviceConfig config) override { return createDevice(config); }
};

class IDeviceObserver {
public:
    virtual void        onDeviceChanged(ISmartDevice&, const std::string&) = 0;
    virtual std::string getObserverName()                                   = 0;
    virtual ~IDeviceObserver() = default;
};

class SmartHomeHub {
public:
    void addDevice(std::unique_ptr<ISmartDevice> device) {
        devices.push_back(std::move(device));
        HomeSystemManager::getInstance().incrementDevices();
    }

    void subscribe(IDeviceObserver* observer)   { observers.push_back(observer); }

    void unsubscribe(IDeviceObserver* observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end());
    }

    void controlDevice(const std::string& name, const std::string& action) {
        for (auto& device : devices) {
            if (device->getName() == name) {
                bool on = (action == "ON");
                if (on) device->turnOn();
                else    device->turnOff();
                notifyAll(*device, on ? "turned on" : "turned off");
                HomeSystemManager::getInstance().incrementActions();
                return;
            }
        }
        std::cout << "  [Hub] Device not found: " << name << "\n";
    }

    void notifyAll(ISmartDevice& device, const std::string& event) {
        for (auto* observer : observers)
            observer->onDeviceChanged(device, event);
    }

    int getObserverCount() const { return static_cast<int>(observers.size()); }

    void printAllStatus() {
        for (auto& device : devices)
            std::cout << "  " << device->getName() << ": " << device->getStatus() << "\n";
    }

private:
    std::vector<std::unique_ptr<ISmartDevice>> devices;
    std::vector<IDeviceObserver*>              observers;
};

class MobileAppObserver : public IDeviceObserver {
public:
    MobileAppObserver(const std::string& name) : userName(name) {}

    void onDeviceChanged(ISmartDevice& device, const std::string& event) override {
        std::cout << "  Mobile App [" << userName << "]: "
                  << device.getName() << " has been " << event << "\n";
    }
    std::string getObserverName() override { return "Mobile App Observer (" + userName + ")"; }

private:
    std::string userName;
};

class EnergyMonitorObserver : public IDeviceObserver {
public:
    void onDeviceChanged(ISmartDevice& device, const std::string& event) override {
        std::cout << "  Energy Monitor: " << device.getName() << " has been " << event << "\n";
        if (event == "turned on") {
            totalPower += device.getPower();
            ++activeDevices;
        } else if (event == "turned off") {
            totalPower -= device.getPower();
            if (activeDevices > 0) --activeDevices;
        }
    }
    std::string getObserverName() override { return "Energy Monitor Observer"; }
    int getTotalPower()    const { return totalPower; }
    int getActiveDevices() const { return activeDevices; }

private:
    int totalPower    = 0;
    int activeDevices = 0;
};

class SecurityObserver : public IDeviceObserver {
public:
    void onDeviceChanged(ISmartDevice& device, const std::string& event) override {
        std::string entry = device.getName() + " has been " + event;
        securityLog.push_back(entry);
        std::cout << "  Security System: " << entry << "\n";
    }
    std::string getObserverName() override { return "Security Observer"; }

    void printSecurityLog() {
        std::cout << "  Security log (" << securityLog.size() << " entries):\n";
        for (const auto& e : securityLog)
            std::cout << "    [SEC] " << e << "\n";
    }

private:
    std::vector<std::string> securityLog;
};

class VoiceAssistantObserver : public IDeviceObserver {
public:
    void onDeviceChanged(ISmartDevice& device, const std::string& event) override {
        std::cout << "  Voice Assistant: " << device.getName() << " has been " << event << "\n";
    }
    std::string getObserverName() override { return "Voice Assistant Observer"; }
};

int main() {

    std::cout << Color::BOLD << Color::CYAN
              << "\n╔═════════════════════════════════════════════════╗\n"
              << "║       🏠 Smart Home System                      ║\n"
              << "║       Five Design Patterns in Action            ║\n"
              << "╚═════════════════════════════════════════════════╝\n"
              << Color::RESET;

    printHeader("1. SINGLETON — System Manager");

    HomeSystemManager& mgr1 = HomeSystemManager::getInstance();
    HomeSystemManager& mgr2 = HomeSystemManager::getInstance();
    mgr1.setHomeName("Palm Villa Smart Home");

    std::cout << Color::GREEN
              << "  Same instance? "
              << (&mgr1 == &mgr2 ? "✅ YES — Single instance" : "❌ NO") << "\n"
              << Color::RESET;

    printHeader("2. BUILDER — Device Configurations");

    printSection("Building: Living Room Light config");
    DeviceConfig lightCfg = DeviceBuilder()
        .setName("Living Room Light")
        .setRoom("Living Room")
        .setType("Light")
        .setIP("192.168.1.10")
        .setPower(10)
        .setSchedule("19:00", "23:00")
        .build();
    lightCfg.print();

    printSection("Building: Bedroom AC config");
    DeviceConfig acCfg = DeviceBuilder()
        .setName("Bedroom AC")
        .setRoom("Master Bedroom")
        .setType("AC")
        .setIP("192.168.1.20")
        .setPower(1500)
        .setSchedule("22:00", "07:00")
        .build();
    acCfg.print();

    printSection("Building: Front Door Lock config");
    DeviceConfig lockCfg = DeviceBuilder()
        .setName("Front Door Lock")
        .setRoom("Entrance")
        .setType("Lock")
        .setIP("192.168.1.30")
        .setPower(5)
        .build();
    lockCfg.print();

    printSection("Building: Garden Camera config");
    DeviceConfig camCfg = DeviceBuilder()
        .setName("Garden Camera")
        .setRoom("Garden")
        .setType("Camera")
        .setIP("192.168.1.40")
        .setPower(8)
        .build();
    camCfg.print();

    printHeader("3. FACTORY METHOD — Manufacturing Devices");

    LightFactory  lightFactory;
    ACFactory     acFactory;
    LockFactory   lockFactory;
    CameraFactory cameraFactory;

    auto smartLight  = lightFactory.manufactureDevice(lightCfg);
    auto smartAC     = acFactory.manufactureDevice(acCfg);
    auto smartLock   = lockFactory.manufactureDevice(lockCfg);
    auto smartCamera = cameraFactory.manufactureDevice(camCfg);

    auto* lightPtr  = dynamic_cast<SmartLight*>(smartLight.get());
    auto* acPtr     = dynamic_cast<SmartAC*>(smartAC.get());
    auto* lockPtr   = dynamic_cast<SmartLock*>(smartLock.get());
    auto* cameraPtr = dynamic_cast<SmartCamera*>(smartCamera.get());

    printHeader("4. ADAPTER — Legacy Device Integration");

    OldThermometer      oldThermo;
    LegacyDeviceAdapter thermoAdapter(oldThermo, "Kitchen Thermometer", "Kitchen");

    std::cout << Color::YELLOW
              << "  Legacy device interface:\n"
              << "    activate() / deactivate() / readSensor()\n"
              << "  New system expects:\n"
              << "    turnOn() / turnOff() / getStatus()\n"
              << "  Adapter translates transparently:\n"
              << Color::RESET;

    thermoAdapter.turnOn();
    oldThermo.simulateReading(26.3f);
    std::cout << "  Thermometer status: " << thermoAdapter.getStatus() << "\n";
    thermoAdapter.turnOff();

    printHeader("5. OBSERVER — Control Hub & Notifications");

    SmartHomeHub hub;

    printSection("Registering devices with the hub");
    hub.addDevice(std::move(smartLight));
    hub.addDevice(std::move(smartAC));
    hub.addDevice(std::move(smartLock));
    hub.addDevice(std::move(smartCamera));
    hub.addDevice(std::make_unique<LegacyDeviceAdapter>(
        oldThermo, "Kitchen Thermometer", "Kitchen"
    ));

    MobileAppObserver      ownerApp("John");
    MobileAppObserver      guestApp("Sarah");
    EnergyMonitorObserver  energyMonitor;
    SecurityObserver       securitySystem;
    VoiceAssistantObserver voiceAssistant;

    printSection("Subscribing to notifications");
    hub.subscribe(&ownerApp);
    hub.subscribe(&guestApp);
    hub.subscribe(&energyMonitor);
    hub.subscribe(&securitySystem);
    hub.subscribe(&voiceAssistant);

    printSection("Scenario 1: Morning — Wake Up Routine");
    hub.controlDevice("Living Room Light", "ON");
    hub.controlDevice("Bedroom AC",        "ON");
    hub.controlDevice("Garden Camera",     "ON");

    if (lightPtr)  lightPtr->setBrightness(70);
    if (lightPtr)  lightPtr->setColor("Warm White");
    if (acPtr)     acPtr->setTemperature(22.0);
    if (acPtr)     acPtr->setMode("Cool");
    if (cameraPtr) cameraPtr->startRecording();

    printSection("Scenario 2: Visitor Arrives");
    if (lockPtr) {
        lockPtr->unlock("John");
        hub.notifyAll(*lockPtr, "Door Unlocked");
    }
    if (lockPtr) {
        lockPtr->lock("Auto System");
        hub.notifyAll(*lockPtr, "Door Locked");
    }

    printSection("Scenario 3: Motion Detected");
    if (cameraPtr) {
        cameraPtr->detectMotion();
        hub.notifyAll(*cameraPtr, "Suspicious motion detected!");
    }

    printSection("Scenario 4: Sarah Unsubscribes");
    hub.unsubscribe(&guestApp);
    std::cout << "  [Notifications now going to "
              << hub.getObserverCount() << " parties]\n";
    hub.controlDevice("Living Room Light", "OFF");

    printSection("Scenario 5: Night — Shut Down Routine");
    hub.controlDevice("Bedroom AC",    "OFF");
    hub.controlDevice("Garden Camera", "OFF");

    printHeader("Final Summary");
    hub.printAllStatus();

    printSection("System Statistics");
    HomeSystemManager::getInstance().printStatus();

    printSection("Energy Report");
    std::cout << Color::YELLOW
              << "  Current consumption: " << energyMonitor.getTotalPower()    << "W\n"
              << "  Active devices:      " << energyMonitor.getActiveDevices() << "\n"
              << Color::RESET;

    printSection("Security Log");
    securitySystem.printSecurityLog();

    printSection("Full System Event Log");
    HomeSystemManager::getInstance().printLog();

    std::cout << "\n" << Color::BOLD << Color::CYAN
              << "╔══════════════════════════════════════════════════╗\n"
              << "║          Design Patterns Used in This Project    ║\n"
              << "╠══════════════════════════════════════════════════╣\n"
              << "║  🔵 Singleton  → HomeSystemManager               ║\n"
              << "║     One manager tracks the entire system         ║\n"
              << "╠══════════════════════════════════════════════════╣\n"
              << "║  🟢 Builder    → DeviceBuilder                   ║\n"
              << "║     Build device configs step by step            ║\n"
              << "╠══════════════════════════════════════════════════╣\n"
              << "║  🟡 Factory    → LightFactory / ACFactory ...    ║\n"
              << "║     Create devices without if/else chains        ║\n"
              << "╠══════════════════════════════════════════════════╣\n"
              << "║  🟠 Adapter    → LegacyDeviceAdapter             ║\n"
              << "║     Integrate old thermometer transparently      ║\n"
              << "╠══════════════════════════════════════════════════╣\n"
              << "║  🔴 Observer   → SmartHomeHub                    ║\n"
              << "║     Notify app, energy, security automatically   ║\n"
              << "╚══════════════════════════════════════════════════╝\n"
              << Color::RESET;

    return 0;
}
