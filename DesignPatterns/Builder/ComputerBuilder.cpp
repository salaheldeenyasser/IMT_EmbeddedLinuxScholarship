#include <iostream>

/*
** Builder Design Pattern
** Definition: The Builder pattern separates the construction of a complex object from its representation, allowing the same construction process to create different representations.
** Key Concepts:
- Builder: An interface that defines the methods for creating the different parts of the product.
- Concrete Builder: A class that implements the Builder interface to construct and assemble the parts of the product.
- Director: A class that constructs the object using the Builder interface.
- Product: The complex object that is being built.
** Benefits:
- Separation of Concerns: The Builder pattern separates the construction of a complex object from its representation, allowing for more flexible and maintainable code.
- Reusability: The same construction process can be used to create different representations of the product, making it easier to reuse code.
- Fluent Interface: The Builder pattern often uses a fluent interface, which allows for more readable and intuitive code when constructing complex objects.
** Example: A computer assembly process where the builder pattern can be used to create different configurations of a computer (e.g., gaming PC, office PC) by using the same construction process but different implementations of the builder interface to specify the components of the computer.
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