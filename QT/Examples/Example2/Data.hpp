#include <QObject>
#include <QDebug>

class Data : public QObject{
    Q_OBJECT
public:
    Data(int value, QObject* parent=nullptr);
    ~Data();
    void Display() const;
private:
    int m_value;
};