#include <iostream>
#include <string>
#include <array>
using namespace std;


#if 1

template<const int sz>
class Sensor{
    int m_unit;
    double *m_readings;
    SerialInterface* m_communication;
public:
    Sensor(int unit):m_unit(unit), m_readings(0){}

};

class TemperatureSensor : public Sensor<10>{
    array<double, 10> m_tempReadings;
public:  
    TemperatureSensor(int unit):Sensor(unit), m_tempReadings(){}
};


class CSerial
{
protected:
    
    u_int8_t data;
public:
    virtual void send(u_int8_t data)  = 0;
    virtual  u_int8_t receive() = 0;
    virtual void init() = 0;
};

class CUART : public CSerial
{
private:
    int m_rx;
    int m_tx;
public:
    void send(u_int8_t data) override{
        cout<<"Sending data: "<<data<<endl;
    }
    u_int8_t receive() override{
        cout<<"Receiving data..."<<endl;
        return 0;
    }
    void init() override{
        cout<<"Initializing UART..."<<endl;
    }
};

class CSPI : public CSerial
{
private:
    int m_clk;
    int m_mosi;
    int m_miso;
public:
    void send(u_int8_t data) override{
        cout<<"Sending data: "<<data<<endl;
    }
    u_int8_t receive() override{
        cout<<"Receiving data..."<<endl;
        return 0;
    }
    void init() override{
        cout<<"Initializing SPI..."<<endl;
    }
};

class CI2C : public CSerial
{
private:
    int m_scl;
    int m_sda;
public:
    void send(u_int8_t data) override{
        cout<<"Sending data: "<<data<<endl;
    }
    u_int8_t receive() override{
        cout<<"Receiving data..."<<endl;
        return 0;
    }
    void init() override{
        cout<<"Initializing I2C..."<<endl;
    }
};

#endif

#if 0

template<const int sz>
class Sensor{
    int m_unit;
    double *m_readings;
    SerialInterface* m_communication;
public:
    Sensor(int unit):m_unit(unit), m_readings(0){}

};

class TemperatureSensor : public Sensor<10>{
    array<double, sz> m_temp;
public:  
    TemperatureSensor(int unit):Sensor(unit, m_temp){}
};

class SerialInterface{
public:
    virtual void send(u_int8_t *arr = nullptr,int size = 0) = 0;
    virtual int receive(u_int8_t *arr,int size) = 0;
    virtual void init() = 0;
};

#endif