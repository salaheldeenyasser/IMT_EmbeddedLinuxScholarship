#include "Consumer.hpp"

Consumer::Consumer(QObject* parent) : QObject(parent){
    m_producer = new Producer(this);
    connect(m_producer, &Producer::SendData, this, &Consumer::ReceiveData);
}


void Consumer::ReceiveData(int value){
    qDebug() << "Consumer received data: " << value;
}
