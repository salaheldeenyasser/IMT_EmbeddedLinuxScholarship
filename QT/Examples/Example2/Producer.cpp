#include "Producer.hpp"

Producer::Producer(QObject* parent) : QObject(parent){
    // m_timer = new QTimer(this);
    // m_timer->setInterval(2000);
    m_value = 20;
    Run();
}
Producer::~Producer(){
    qDebug() << "Producer destroyed";
}
void Producer::Run(){
    emit SendData(m_value);
}
