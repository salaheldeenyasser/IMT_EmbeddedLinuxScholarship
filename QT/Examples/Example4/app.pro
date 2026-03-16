QT += core gui qml quick quickcontrols2

CONFIG += release c++17 console

TEMPLATE = app
TARGET = Example4

SOURCES += \
    main.cpp 
    downloaderThread.cpp

HEADERS += \
    downloaderThread.hpp

RESOURCES += \
    qml.qrc