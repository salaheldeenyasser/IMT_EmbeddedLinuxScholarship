QT += core
QT -= gui

CONFIG += release c++17 console

TEMPLATE = app
TARGET = Example2

SOURCES += \
    main.cpp \
    Data.cpp \
    Message.cpp \
    MessageManager.cpp \
    Consumer.cpp
    producer.cpp



HEADERS += \
    Data.hpp \
    Message.hpp \
    MessageManager.hpp
    Consumer.hpp
    Producer.hpp