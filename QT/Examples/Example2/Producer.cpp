#include "Producer.hpp"

Producer::Producer(int value, QObject* parent) : QObject(parent), m_value(value){}
Producer::~Producer(){
    qDebug() << "Producer destroyed";
}
void Producer::Run(){
    emit SendData(m_value);
}
