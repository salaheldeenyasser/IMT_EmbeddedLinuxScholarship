#ifndef SENSORWORKER_HPP
#define SENSORWORKER_HPP

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>
class sensorWorker : public QObject
{
    Q_OBJECT
public:
    sensorWorker(QObject* parent = nullptr);

public slots:
    void startPolling();
    void stopPolling();
signals:
    void sensorDataReady(double temperature, double humidity);
    void pollingStopped();

private slots:
    void onTimerTick();
private:
    QTimer* m_timer;
};


#endif // SENSORWORKER_HPP