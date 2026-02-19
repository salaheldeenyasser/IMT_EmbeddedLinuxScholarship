#include<iostream>


/*Parse words*/
#if 0
int main(){

    std::string line;
    int i = 0;
    while(std::cin >> line)
    {
        std::cout << i << ": " << line << std::endl;
        i++;
    }
}

#endif

/*Parse lines*/
#if 1
int main(){

    std::string line;
    int i = 0;
    while(std::getline(std::cin, line))
    {
        std::cout << i << ": " << line << std::endl;
        i++;
    }
}

#endif