#include "mod.hpp"
#include <iostream>
extern int x;

MyData::MyData(int x): x(x){

}

int MyData::getx(){
    return x;
}

void MyData::setx(){
    this->x =x;
}

