// main.o in=input.txt  out=output.txt
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

#if 0

class CUARTConfig {
private:
    int m_baudRate;
    std::string m_parity;
    int m_stopBits;
    int m_slaveAddress;


public:
    int loadConfig(int argc, char* argv[]){
        std::string stream, value;
        for(int i=1; i<argc; i++){
            std::string arg(argv[i]);
            std::stringstream parser(arg);
            std::getline(parser, stream, '=');
            std::getline(parser, value);

            if (stream =="in"){
                
                std::ifstream inputFile(value);
                if (!inputFile) {
                    std::cerr << "Error: Could not open file " << value << std::endl;
                    return 1;
                }

                std::string line;

                std::string key, value;
                while(std::getline(inputFile, line))
                {
                    std::stringstream parser(line);
                    std::getline(parser, key, '=');
                    std::getline(parser, value);
                
                    
                
                };
            

            } else if (stream == "out") {
                std::ofstream outputFile(value);
                if (!outputFile) {
                    std::cerr << "Error: Could not open file " << value << std::endl;
                    return 1;
                }
            } else {
                std::cerr << "Error: Unsupported stream type!" << std::endl;
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




int main(int argc, char* argv[]) {
    CUARTConfig config;
    config.loadConfig(argc, argv);
    config.show();

    return 0;
}

#endif 

std::string inputFilePath = "input.txt";
std::string outputFilePath = "output.txt";
std::string key, value;

int main(int argc,char* argv[]){

    for(int i=0; i< argc;i++){
        std::string arg(argv[i]);
        std::stringstream parser(arg);
        std::getline(parser, key, '=');
        std::getline(parser, value);


        if(key == "in"){
            inputFilePath = value;
        } else if (key == "out") {
            outputFilePath = value;
        } else {
            std::cerr << "Error: Unsupported stream type!" << std::endl;
            return 1;
        }
    }

    std::ofstream outputFile(outputFilePath);
    std::ifstream inputFile(inputFilePath);

    std::string line;
    int i = 0;
    while(std::getline(inputFile, line))
    {
        i++;
        std::stringstream ss(line);
        int first_op = 0;
        int second_op = 0;
        char op;

        ss >> first_op >> op >> second_op;

        auto adder = [](int a, char op, int b) {
            switch (op)
            {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b != 0) {
                    return a / b;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0; 
                }
            default:
                std::cerr << "Error: Unsupported operator!" << std::endl;
                return 0; 
            }
        };
        outputFile << line << std::endl;
    }
}