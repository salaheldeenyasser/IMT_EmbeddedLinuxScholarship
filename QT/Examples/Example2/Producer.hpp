
#include <QObject>
#include <QDebug>

class Producer : public QObject{
    Q_OBJECT
public:
    Producer(int value, QObject* parent = nullptr);
    ~Producer();
    void Run();
signals:
    void SendData(int value);
    private:
    int m_value;
};