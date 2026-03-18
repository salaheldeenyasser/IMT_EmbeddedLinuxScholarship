#include <iostream>
#include <map>
#include <mutex>

/*
    Singleton pattern implementation for configuration management.
    Key Concepts:
    - Single Instance: Only one instance of ConfigurationManager can exist.
    - Global Access: Provides a global point of access to the instance.
    - Thread Safety: Ensures that the instance is created in a thread-safe manner.
    - Lazy Initialization: The instance is created only when it is first needed.
*/

class ConfigurationManager
{
public:
    static ConfigurationManager &getInstance()
    {
        static ConfigurationManager instance;
        return instance;
    }

    void set(const std::string &key, const std::string &value)
    {
        std::lock_guard<std::mutex> lock(mutex);
        config[key] = value;
    }

    std::string get(const std::string &key)
    {
        std::lock_guard<std::mutex> lock(mutex);
        return config[key];
    }

private:
    static ConfigurationManager *instance;
    ConfigurationManager()
    {
        std::cout << "ConfigurationManager instance created." << std::endl;
    }

    ~ConfigurationManager() = default;

    std::map<std::string, std::string> config;

    std::mutex mutex;
};

int main()
{
    ConfigurationManager &config1 = ConfigurationManager::getInstance();
    config1.set("database", "localhost");
    config1.set("port", "5432");

    ConfigurationManager &config2 = ConfigurationManager::getInstance();
    std::cout << "Database: " << config2.get("database") << std::endl;
    std::cout << "Port: " << config2.get("port") << std::endl;

    return 0;
}