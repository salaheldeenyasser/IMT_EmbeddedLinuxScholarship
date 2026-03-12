#include <QCoreApplication>
#include <QTimer>
#include <QScopedPointer>
#include "Data.hpp"
#include "MessageManager.hpp"
#include <QThread>
#include "Consumer.hpp"


int main(int argc, char* argv[]){

    QCoreApplication app(argc, argv);

    // QObject parent;
    // Data data_1(10,&parent);
    // Data* data_2 = new Data(20,&parent);
    // data_1.Display();
    // data_2->Display();
    // delete data_2;

    // QScopedPointer<Data> ptr1(new Data(10));
    // ptr1->Display();
    // Data* rawPtr = ptr1.data();
    // rawPtr->Display();
    
    // ptr1.reset(new Data(50));
    // ptr1->Display();
    // // QScopedPointer<Data> ptr2(ptr1.take());
    // if (ptr1.isNull()){
    //     qDebug() << "ptr1 is null";
    // } else{
    //     qDebug() << "ptr1 is not null";
    // }   
    
    // // ptr2->Display();

    // MessageManager manager;
    // manager.Addessage("Hello, World!");
    // manager.Addessage("Welcome to Qt programming.");
    // QThread::sleep(5);
    // manager.Addessage("This is a delayed message");
    // manager.ShowMessages();
    
    Consumer consumer;


    QTimer::singleShot(3000,[&](){
        app.quit();
    });

    app.exec();


}