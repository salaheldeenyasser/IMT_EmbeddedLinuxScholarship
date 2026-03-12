#include "Data.hpp"
#include <QDebug>

Data::Data(int value, QObject* parent): QObject(parent), m_value(value){
    Data::Display();
}
Data::~Data(){
    qDebug() << "GoodBye, Data was: " << m_value;
}
void Data::Display() const{
    qDebug() << "Data is: " << m_value;
}