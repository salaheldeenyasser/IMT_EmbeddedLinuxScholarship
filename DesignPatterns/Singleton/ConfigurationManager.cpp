#include <iostream>
#include <map>

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
        config[key] = value;
    }

    std::string get(const std::string &key)
    {
        return config[key];
    }

private:
    static ConfigurationManager *instance;
    ConfigurationManager()
    {
        std::cout << "ConfigurationManager instance created." << std::endl;
    }

    std::map<std::string, std::string> config;
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