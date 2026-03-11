#include <iostream>


void swapWithPointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int x = 10;
    int y = 20;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapWithPointer(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    return 0;
}