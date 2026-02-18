#include <iostream>


class CSensor{
private:
    int m_SensorID;
    int m_LastReading;
    static int sensorCount;



public:
    CSensor(int id, int reading) : m_SensorID(id), m_LastReading(reading) {
        sensorCount++;
    }

    int getSensorID() const {
        return m_SensorID;
    }

    int getLastReading() const {
        return m_LastReading;
    }

    static int getSensorCount() {
        return sensorCount;
    }


    ~CSensor() {
        sensorCount--;
    }
};


int CSensor::sensorCount = 0;


int main() {
    CSensor sensor1(1, 100);
    CSensor sensor2(2, 200);
    CSensor sensor3(3, 300);

    std::cout << "Sensor ID: " << sensor1.getSensorID() << ", Last Reading: " << sensor1.getLastReading() << std::endl;
    std::cout << "Sensor ID: " << sensor2.getSensorID() << ", Last Reading: " << sensor2.getLastReading() << std::endl;
    std::cout << "Sensor ID: " << sensor3.getSensorID() << ", Last Reading: " << sensor3.getLastReading() << std::endl;

    std::cout << "Sensors Count: " << CSensor::getSensorCount() << std::endl;

    {
        CSensor sensor4(4, 100);
        CSensor sensor5(5, 200);
        CSensor sensor6(6, 300);

        std::cout << "Sensor ID: " << sensor4.getSensorID() << ", Last Reading: " << sensor4.getLastReading() << std::endl;
        std::cout << "Sensor ID: " << sensor5.getSensorID() << ", Last Reading: " << sensor5.getLastReading() << std::endl;
        std::cout << "Sensor ID: " << sensor6.getSensorID() << ", Last Reading: " << sensor6.getLastReading() << std::endl;

        std::cout << "Sensors Count in scope: " << CSensor::getSensorCount() << std::endl;
    }

    std::cout << "Sensors Count: " << CSensor::getSensorCount() << std::endl;

    return 0;
}