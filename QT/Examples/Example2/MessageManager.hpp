#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "Message.hpp"


class MessageManager: public QObject{
    Q_OBJECT
public:
    MessageManager(QObject *parent = nullptr);
    void Addessage(QString message);
    void ShowMessages() const;
    void ClearMessages();
private:
    QList<QSharedPointer<Message>> m_messages;
};
