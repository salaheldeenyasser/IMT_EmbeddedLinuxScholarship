QT += core gui qml quick quickcontrols2

CONFIG += release c++17 console

TEMPLATE = app
TARGET = Example5

SOURCES += \
    main.cpp 
    sensorWorker.cpp
    sensorController.cpp

HEADERS += \
    sensorWorker.hpp
    sensorController.hpp

RESOURCES += \
    qml.qrc