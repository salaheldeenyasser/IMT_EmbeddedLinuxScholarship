#include <QGuiApplication>
#include <QMLApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "downloaderThread.hpp"

int main(int argc, char *argv[])
{
    
    #if 1
    QGuiApplication a(argc, argv);

    DownloaderThread downloaderThread("example.com");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("downloaderThread", &downloaderThread);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootobjects().isEmpty())
        return -1;
    #endif

    return a.exec();
}