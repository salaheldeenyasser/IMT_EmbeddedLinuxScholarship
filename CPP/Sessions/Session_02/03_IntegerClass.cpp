#include<iostream>
#include<cstring>


class Integer {
private:
    int x;
    int y;
public:
    void setXY(int xValue, int yValue) {
        x = xValue;
        y = yValue;
    }
    void getXY(int* xValue, int* yValue) {
        *xValue = x;
        *yValue = y;
    }
};




int main(){
    Integer myInt;
    myInt.setXY(5, 10);
    
    
    return 0;
}