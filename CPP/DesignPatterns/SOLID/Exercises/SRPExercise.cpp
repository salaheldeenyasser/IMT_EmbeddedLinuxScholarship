#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class FileLogger {
public:
    void log(const std::string& message) {
        std::ofstream file("log.txt", std::ios::app);
        file << "INFO: " << message << std::endl;
        file.close();
    }
};

class MessageFormatter {
public:
    std::string formatMessage(const std::string& message) {
        return "[Formatted] " + message;
    }
};

class RemoteLogSender {
public:
    void sendMessage(const std::string& message) {
        std::cout << "Sending: " << message << std::endl;
    }
};

class LogCompressor {
public:
    std::string compressMessage(const std::string& message) {
        return "Compressed(" + message + ")";
    }
};
