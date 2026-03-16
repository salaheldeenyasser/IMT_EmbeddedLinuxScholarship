#ifndef SENSORCONTROLLER_HPP
#define SENSORCONTROLLER_HPP

#include <QObject>
#include <QDebug>
#include <QThread>
#include "sensorWorker.hpp"

class sensorController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double temperature READ temperature NOTIFY dataUpdated)
    Q_PROPERTY(double humidity READ humidity NOTIFY dataUpdated)
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)
    
public:
    sensorController(QObject* parent = nullptr);
    ~sensorController();
    double temperature() const { return m_temperature; }
    double humidity() const { return m_humidity; }
    bool running() const { return m_running; }
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

public slots:
    void onSensorDataReady(double temperature, double humidity);

signals:
    void dataUpdated();
    void runningChanged();

private:
    sensorWorker* m_worker;
    QThread* m_thread;    
    double m_temperature;
    double m_humidity;
    bool m_running;

};
#endif // SENSORCONTROLLER_HPP