#include <QGuiApplication>
#include <QMLApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "downloaderThread.hpp"
#include "sensorWorker.hpp"
#include "sensorController.hpp"

int main(int argc, char *argv[])
{
    
    #if 1
    QGuiApplication a(argc, argv);

    sensorController controller;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("sensorWorker", &worker);
    engine.rootContext()->setContextProperty("sensorController", &controller);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootobjects().isEmpty())
        return -1;
    #endif

    return a.exec();
}