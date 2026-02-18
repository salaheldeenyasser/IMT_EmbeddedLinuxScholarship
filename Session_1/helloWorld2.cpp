#include <iostream>



int main() {
    char first[20];
    char last[20];
    std::cin.getline(first, 20);
    std::cin.getline(last, 20);
    
    std::cout << "Hello, " << first << " " << last << "!" << std::endl;

}