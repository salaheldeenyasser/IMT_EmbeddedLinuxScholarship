#include <iostream>

class ILogger
{
public:
    virtual void log(const std::string message) = 0;
    virtual ~ILogger() = default;
};

class FileWriter
{
public:
    void writeToFile(const std::string message)
    {
        std::cout << "Writing to file: " << message << std::endl;
    }
};

class LoggerAdapter : public ILogger
{
public:
    void log(const std::string message) override
    {
        fileWriter->writeToFile(message);
    }

private:
    FileWriter *fileWriter;
};

int main()
{
    ILogger *logger = new LoggerAdapter();
    logger->log("This is a log message.");

    return 0;
}