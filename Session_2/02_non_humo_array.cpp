#include <iostream>
#include <cstring>

typedef enum {STRING, FLOAT, CHAR, INTEGER} Type;

struct {
    union{
        char name[15];
        float f;
        char c;
        int i;
    }listelement;
    Type tag;
}liststruct;


void NonHumoArray_main(){

    
    strcpy(liststruct.listelement.name, "Ahmed");
    liststruct.listelement.f = 3.14;
    liststruct.listelement.c = 'a';
    liststruct.listelement.i = 42;
    liststruct.tag = Type::STRING;

    for(int i =0;i <  4; i++){
        switch(liststruct.tag){
            case Type::STRING:
                std::cout << liststruct.listelement.name << std::endl;
                break;
            case Type::FLOAT:
                std::cout << liststruct.listelement.f << std::endl;
                break;
            case Type::CHAR:
                std::cout << liststruct.listelement.c << std::endl;
                break;
            case Type::INTEGER:
                std::cout << liststruct.listelement.i << std::endl;
                break;
        }
    }
};


int main(){
    NonHumoArray_main();
}