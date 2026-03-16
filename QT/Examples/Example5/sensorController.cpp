#include "sensorController.hpp"

sensorController::sensorController(QObject* parent)
    : QObject(parent),
      m_worker(new sensorWorker()),
      m_thread(new QThread()),
      m_temperature(0.0),
      m_humidity(0.0),
      m_running(false)
{
    m_worker->moveToThread(m_thread); // Move worker to the thread it will run in 
    connect(m_thread, &QThread::started, m_worker, &sensorWorker::startPolling);
    connect(m_worker, &sensorWorker::pollingStopped, m_worker, [this](){
        m_thread->quit();
        m_thread->wait();
        m_running = false;
        emit runningChanged();
    });
    connect(m_worker, &sensorWorker::sensorDataReady, this, &sensorController::onSensorDataReady);
}

sensorController::~sensorController(){
    if(m_thread->isRunning()){
        QMetaObject::invokeMethod(m_worker, "stopPolling", Qt::QueuedConnection);
        m_thread->quit();
        m_thread->wait();
    }
    m_worker->deleteLater();
};

void sensorController::start(){
    if(!m_running){
        m_thread->start();
        m_running = true;
        emit runningChanged();
    }
}
void sensorController::stop(){
    if(m_running){
        QMetaObject::invokeMethod(m_worker, "stopPolling", Qt::QueuedConnection);
        m_running = false;
        emit runningChanged();
    }
}

void sensorController::onSensorDataReady(double temperature, double humidity){
    m_temperature = temperature;
    m_humidity = humidity;
    emit dataUpdated();
}