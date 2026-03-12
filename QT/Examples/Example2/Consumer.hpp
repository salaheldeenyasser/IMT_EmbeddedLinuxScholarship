#include <QObject>
#include <QDebug>
#include "Producer.hpp"

class Consumer : public QObject{
    Q_OBJECT
public:
    Consumer( QObject* parent = nullptr);
    ~Consumer();
public slots:
    void ReceiveData(int value);
private:
    Producer* m_producer;
};