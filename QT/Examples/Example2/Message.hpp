#include <QObject>
#include <QDebug>
#include <QDateTime>

class Message : public QObject{
    Q_OBJECT
public:
    Message(QString message, QObject* parent=nullptr);
    void Show() const;
private:
    QString m_message;
    QString m_timestamp;
};