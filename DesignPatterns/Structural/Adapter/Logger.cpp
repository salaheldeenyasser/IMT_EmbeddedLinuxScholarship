#include <iostream>

/*
** Adapter Pattern
** Definition: The Adapter pattern allows incompatible interfaces to work together by converting the interface of one class into another interface that clients expect.
** Key Concepts:
- Target Interface: The interface that the client expects to work with.
- Adaptee: The existing class with an incompatible interface that needs to be adapted.
- Adapter: The class that implements the Target Interface and holds an instance of the Adaptee, translating requests from the Target Interface to the Adaptee.
** Benefits:
- Reusability: The Adapter pattern allows existing classes to be reused without modification, even if their interfaces are incompatible with the client code.
- Flexibility: It provides a way to integrate new functionality into existing code without changing the existing code, adhering to the Open/Closed Principle.
- Separation of Concerns: The Adapter pattern separates the concerns of the client code and the existing code, allowing them to evolve independently.
** Example: A logging system that needs to write log messages to a file, but the existing logging interface does not support file writing. The Adapter pattern can be used to create an adapter class that implements the logging interface and uses a file writer to write log messages to a file, allowing the logging system to work with the new file writing functionality without modifying the existing logging code.
*/

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