#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <any>
#include <fstream>
#include <sstream>
#include <variant>
#include <memory>
#include <utility>

using namespace std;

class CUART{
    private:
    int m_baudRate;
    std::string m_parity;
    int m_stopBits;
    int m_slaveAddress;


public:
    int loadConfig(){
        std::string line;

        std::string key, value;
        while(std::getline(std::cin, line))
        {
            std::stringstream parser(line);
            std::getline(parser, key, '=');
            std::getline(parser, value);

            if (key == "baudrate") {
                m_baudRate = std::stoi(value);
            } else if (key == "parity") {
                m_parity = value;
            } else if (key == "stopbits") {
                m_stopBits = std::stoi(value);
            } else if (key == "slaveaddress") {
                m_slaveAddress = std::stoi(value);
            } else {
                std::cerr << "Error: Unsupported configuration!" << std::endl;
                return 1;
            }

        };

        return 0;
    }


    int show(){
        std::cout<<"Baud Rate= " << m_baudRate << std::endl;
        std::cout<<"Parity= " << m_parity << std::endl;
        std::cout<<"Stop Bits= " << m_stopBits << std::endl;
        std::cout<<"Slave Address= " << m_slaveAddress << std::endl;
        return 0;
    }


};

class CDeviceManager{
    unique_ptr<CUART> UART_ptr;
public:
    void communicate(){
        UART_ptr = make_unique<CUART>();
        UART_ptr->loadConfig();
        UART_ptr->show();
    }
};


int main() {
    CDeviceManager manager;
    manager.communicate();
    return 0;
}