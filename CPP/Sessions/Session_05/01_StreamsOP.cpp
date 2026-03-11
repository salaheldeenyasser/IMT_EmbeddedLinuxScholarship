#include<iostream>
#include<string>

#if 0



#endif

#if 1
int main(int argc, char* argv[]){
    std::string input;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);

    char op;
    int num1, num2;

    if (sscanf(input.c_str(), "%d %c %d", &num1, &op, &num2) == 3) {
        int result;
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 1; 
                }
                break;
            default:
                std::cerr << "Error: Unsupported operator!" << std::endl;
                return 1; 
        }
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cerr << "Error: Invalid input format!" << std::endl;
        return 1; 
    }

    return 0;
}

#endif