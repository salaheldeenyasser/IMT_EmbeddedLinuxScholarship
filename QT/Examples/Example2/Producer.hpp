
#include <QObject>
#include <QDebug>
#include <QTimer>

class Producer : public QObject{
    Q_OBJECT
public:
    Producer( QObject* parent = nullptr);
    ~Producer();
    void Run();
signals:
    void SendData(int value);
private:
    QTimer* m_timer;
    int m_value;
};