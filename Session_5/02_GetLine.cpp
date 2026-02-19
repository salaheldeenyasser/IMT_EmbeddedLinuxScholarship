#include<iostream>



int main(){
    std::string input;
    std::getline(std::cin, input, '+');
    int a = std::stoi(input);
    std::getline(std::cin, input);
    int b = std::stoi(input);
    std::cout << "Sum: " << a + b << std::endl;

    return 0;
}