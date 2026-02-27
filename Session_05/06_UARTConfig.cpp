#include<iostream>
#include<string>
#include<sstream>

#if 0

class UARTConfig {
private:
    int m_baudRate;
    std::string m_parity;
    int m_stopBits;
    int m_slaveAddress;


public:

    UARTConfig(int baudRate, std::string parity, int stopBits, int slaveAddress) 
        : m_baudRate(baudRate), m_parity(parity), m_stopBits(stopBits), m_slaveAddress(slaveAddress) {}

    int parseConfig(std::string line){
        
        int i = 0;
        while(std::getline(std::cin, line))
        {
            i++;
            std::string first_op = "";
            std::string second_op = "";
            std::string op = "";
            std::stringstream ss(line);
            ss >> first_op >> op >> second_op;
            if (first_op == "baudrate") {
                m_baudRate = std::stoi(second_op);
            } else if (first_op == "parity") {
                if (second_op == "even") {
                    m_parity = "even";
                } else if (second_op == "odd") {
                    m_parity = "odd";
                } else {
                    std::cerr << "Error: Unsupported parity!" << std::endl;
                }
            } else if (first_op == "stopbits") {
                m_stopBits = std::stoi(second_op);
            } else if (first_op == "slaveaddress") {
                m_slaveAddress = std::stoi(second_op);
            } else {
                std::cerr << "Error: Unsupported configuration!" << std::endl;
            }

        };
        return 0;
    }


    void printConfig() {
        std::cout << "Baud Rate: " << m_baudRate << std::endl;
        std::cout << "Parity: " << m_parity << std::endl;
        std::cout << "Stop Bits: " << m_stopBits << std::endl;
        std::cout << "Slave Address: " << m_slaveAddress << std::endl;
    }

};


int main() {
    std::string line;
    UARTConfig config(0, "", 0, 0);
    config.parseConfig(line);
    config.printConfig();

    return 0;
}
#endif

/* Eng Mazen Solution */

#if 1


class CUARTConfig {
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




int main() {
    CUARTConfig config;
    config.loadConfig();
    config.show();

    return 0;
}

#endif 