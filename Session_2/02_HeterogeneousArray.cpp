#include <iostream>
#include <cstring>

typedef enum {STRING, FLOAT, CHAR, INTEGER} Type;

struct element{
    union{
        char name[15];
        float f;
        char c;
        int i;
    }data;
    Type tag;
};


void NonHumoArray_main(){
    element list[4];
    
    strcpy(list[0].data.name, "Ahmed");
    list[0].tag = STRING;

    list[1].data.f, 15.44f;
    list[1].tag = FLOAT;

    list[2].data.c, 'c';
    list[2].tag = CHAR;

    list[3].data.i, 15;
    list[3].tag = INTEGER;

    for(int i =0;i <  4; i++){
        switch(list[i].tag){
            case STRING:
                std::cout << list[i].data.name << std::endl;
                break;
            case FLOAT:
                std::cout << list[i].data.f << std::endl;
                break;
            case CHAR:
                std::cout << list[i].data.c << std::endl;
                break;
            case INTEGER:
                std::cout << list[i].data.i << std::endl;
                break;
        }
    }
};


int main(){
    NonHumoArray_main();
}