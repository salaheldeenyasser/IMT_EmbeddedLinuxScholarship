#include<iostream>
#include<cstring>

class SensorReading {
private:
    float timestamp;
    float value;
    std::string unit;
    
public:
    SensorReading(float t, float v, std::string u) : timestamp(t), value(v), unit(u) {}
};

class SensorNode {
private:
    int id;
    std::string location;
    int size ;
    SensorReading Readings[];

public:
    SensorNode(int i, std::string loc, SensorReading r[], int readingsNum) {
        id = i;
        location = loc;
        size = readingsNum;
        for(int j = 0; j < size; j++) {
            Readings[j] = r[j];
        }
    }
};

class Gateway {
private:
    int size;
    SensorNode nodes[];

public:
    Gateway(SensorNode n[], int nodesNum) {
        size = nodesNum;
        for(int i = 0; i < size; i++) {
            nodes[i] = n[i];
        }
    }

};


void main(){
    

}



