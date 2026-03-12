#include "Consumer.hpp"

Consumer::Consumer(QObject* parent) : QObject(parent){
    Producer* producer = new Producer(this);
    connect(producer, &Producer::SendData, this, &Consumer::ReceiveData);
}


void Consumer::ReceiveData(int value){
    qDebug() << "Consumer received data: " << value;
}
