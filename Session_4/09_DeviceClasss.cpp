#include<iostream>
#include<cstring>

class CDevice{
private:
    int m_DeviceID;
    char* m_DeviceName;
    

public:
    CDevice(int id, const char* name) : m_DeviceID(id) {
        m_DeviceName = new char[std::strlen(name) + 1];
        std::strcpy(m_DeviceName, name);
    }

    ~CDevice() {
        delete[] m_DeviceName;
    }

    void printInfo() const {
        std::cout << "Device ID: " << m_DeviceID << ", Device Name: " << m_DeviceName << std::endl;
    }
};


int main(){


    CDevice device1(1, "Sensor");
    CDevice device2(2, "Actuator");

    device1.printInfo();
    device2.printInfo();

    {
        CDevice device3(3, "Controller");
        device3.printInfo();
    }

    return 0;

}