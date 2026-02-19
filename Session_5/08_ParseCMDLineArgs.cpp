#include<iostream>
#include<string>
#include<sstream>


class CUARTConfig {
private:
    int m_baudRate;
    std::string m_parity;
    int m_stopBits;
    int m_slaveAddress;


public:
    int loadConfig(int argc, char* argv[]){
        std::string key, value;
        for(int i=1; i<argc; i++){
            std::string arg(argv[i]);
            std::stringstream parser(arg);
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
        }

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




int main(int argc, char* argv[]) {
    CUARTConfig config;
    config.loadConfig(argc, argv);
    config.show();

    return 0;
}