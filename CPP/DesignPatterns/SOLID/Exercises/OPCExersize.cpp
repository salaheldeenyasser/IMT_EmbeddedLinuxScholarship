#include <iostream>

class NotificationMethod{
public:
    virtual void notify(const std::string& message) = 0;
};

class EmailNotification : public NotificationMethod{
public:
    void notify(const std::string& message) override {
        std::cout << "Email Notification: " << message << std::endl;
    }
};

class SMSNotification : public NotificationMethod{
public:
    void notify(const std::string& message) override {
        std::cout << "SMS Notification: " << message << std::endl;
    }
};

class PushNotification : public NotificationMethod{
public:
    void notify(const std::string& message) override {
        std::cout << "Push Notification: " << message << std::endl;
    }
};

class Notifier{
public:
    void sendNotification(NotificationMethod* notificationMethod, const std::string& message) {
        notificationMethod->notify(message);
    }
};