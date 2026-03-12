#include "Message.hpp"

Message::Message(QString message, QObject* parent) : 
QObject(parent), 
m_message(message),
m_timestamp(QDateTime::currentDateTime().addSecs(-12*3600).toString("yyyy-MM-dd hh:mm:ss"))
{
    // QString date = "1998-12-31 23:59:59";
    // QDateTime dt = QDateTime::fromString(date, "yyyy-MM-dd hh:mm:ss");
    // QDateTime dt2 = QDateTime::currentDateTime();
    // dt.daysTo(dt2);

}


void Message::Show() const{
    qDebug() << m_message << " at " << m_timestamp;
}