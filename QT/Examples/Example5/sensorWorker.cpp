#include "sensorWorker.hpp"

sensorWorker::sensorWorker(QObject* parent): QObject(parent), m_timer(nullptr){}

void sensorWorker::startPolling(){
    m_timer = new QTimer(this);
    m_timer->setInterval(1000); // 1 second interval
    connect(m_timer, &QTimer::timeout, this, &sensorWorker::onTimerTick);
    m_timer->start();
}

void sensorWorker::stopPolling(){
    if(m_timer){
        m_timer->stop();
        m_timer->deleteLater();
        m_timer = nullptr;
    }
}

void sensorWorker::onTimerTick(){
    double temperature = QRandomGenerator::global()->bounded(1000); // Simulate temperature between 15 and 30
    double humidity = QRandomGenerator::global()->bounded(2000); // Simulate humidity between 30% and 70%
    emit sensorDataReady(temperature, humidity);
}