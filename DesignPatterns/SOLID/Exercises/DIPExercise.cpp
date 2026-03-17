#include <iostream>

// Dependency Inversion Principle (DIP)
/*
** Definition: High-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions.
** Problem: A high-level class "LogManager" directly depends on a low-level class "FileLogger". If we want to change the logging mechanism (e.g., to a remote logger), we would need to modify the "LogManager" class, which violates the DIP.
** Solution: Introduce an abstraction (e.g., an interface "ILogger") that both the high-level module (LogManager) and the low-level modules (FileLogger, RemoteLogger) depend on. This way, we can easily switch between different logging implementations without modifying the high-level module.
*/  

class ILogger
{
public:
    virtual void log(const std::string &message) = 0;
    virtual ~ILogger() = default;
};

class FileLogger : public ILogger
{
public:
    void log(const std::string &message) override
    {        std::cout << "Logging to file: " << message << std::endl;
    }
};

class RemoteLogger : public ILogger
{
public:
    void log(const std::string &message) override
    {        std::cout << "Logging to remote server: " << message << std::endl;
    }
};

class reportGenerator
{private:
    ILogger *logger;
public:
    reportGenerator(ILogger *logger) : logger(logger) {}
    void generateReport()
    {        // Report generation logic
        logger->log("Report generated successfully.");
    }
};

int main()
{
    FileLogger fileLogger;
    reportGenerator report(&fileLogger);
    report.generateReport();

    RemoteLogger remoteLogger;
    reportGenerator report2(&remoteLogger);
    report2.generateReport();

    return 0;
}
