#include<iostream>

#define get_bit(num, pos) ((num >> pos) & 1)

void print_bin(int num, int padding){
    for(int i = 0; i< padding;i++){
        std::cout << get_bit(num, padding - 1 - i);
    }

}

int main() {
    
    print_bin(15, 4);
    return 0;
}