#include "MessageManager.hpp"

MessageManager::MessageManager(QObject *parent): QObject(parent){}
void MessageManager::Addessage(QString message){
    m_messages.append(QSharedPointer<Message>::create(message));

}
void MessageManager::ShowMessages() const{
    for (const auto& message : m_messages)
    {
        message->Show();
    }
}
void MessageManager::ClearMessages(){
    m_messages.clear();
}