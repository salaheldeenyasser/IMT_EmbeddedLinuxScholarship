#include <iostream>
#include <cstring>


int main(){
    std::string number;

    std::cin>>number;

    int insertPosition = number.length() - 3;
    while (insertPosition > 0) {
        number.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    std::cout<<number<<std::endl;
}