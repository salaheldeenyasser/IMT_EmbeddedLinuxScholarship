#include <iostream>

/*

*/

class Computer
{
public:
    void setCPU(const std::string &cpu)
    {
        this->cpu = cpu;
    }
    void setRAM(const std::string &ram)
    {
        this->ram = ram;
    }
    void setStorage(const std::string &storage)
    {
        this->storage = storage;
    }
    void setGPU(const std::string &gpu)
    {
        this->gpu = gpu;
    }

    void setWiFi(bool wifi)
    {
        this->wifi = wifi;
    }

    void displaySpecs()
    {
        std::cout << "CPU: " << cpu << std::endl;
        std::cout << "RAM: " << ram << std::endl;
        std::cout << "Storage: " << storage << std::endl;
        std::cout << "GPU: " << gpu << std::endl;
        std::cout << "WiFi: " << (wifi ? "Yes" : "No") << std::endl;
    }

private:
    std::string cpu;
    std::string ram;
    std::string storage;
    std::string gpu;
    bool wifi;
};

class ComputerBuilder
{
public:
    ComputerBuilder &setCPU(const std::string &cpu)
    {
        computer.setCPU(cpu);
        return *this;
    }
    ComputerBuilder &setRAM(const std::string &ram)
    {
        computer.setRAM(ram);
        return *this;
    }
    ComputerBuilder &setStorage(const std::string &storage)
    {
        computer.setStorage(storage);
        return *this;
    }
    ComputerBuilder &setGPU(const std::string &gpu)
    {
        computer.setGPU(gpu);
        return *this;
    }
    ComputerBuilder &setWiFi(bool wifi)
    {
        computer.setWiFi(wifi);
        return *this;
    }
    Computer build()
    {
        return computer;
    }

private:
    Computer computer;
};


int main()
{
    ComputerBuilder builder;
    Computer myComputer = builder.setCPU("Intel i7")
                                .setRAM("16GB")
                                .setStorage("512GB SSD")
                                .setGPU("NVIDIA RTX 3060")
                                .setWiFi(true)
                                .build();

    myComputer.displaySpecs();

    return 0;
}