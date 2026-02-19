#include<iostream>
#include<string>
#include<sstream>

#if 0
int main(){

    std::string line;
    int i = 0;
    while(std::getline(std::cin, line))
    {
        std::cout << i << ": " << line << std::endl;
        i++;
        int op_pos = line.find_first_of("+-*/");
        std::string num1_str = line.substr(0, op_pos);
        std::string num2_str = line.substr(op_pos + 1, line.size() - op_pos);
        char op = line[op_pos];

        auto adder = [](int a, char op, int b) {
            switch (op)
            {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b != 0) {
                    return a / b;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0; 
                }
            default:
                std::cerr << "Error: Unsupported operator!" << std::endl;
                return 0; 
            }
        };
        std::cout << "Result: " << adder(std::stoi(num1_str), op, std::stoi(num2_str)) << std::endl;
        
    }
}


#endif


/* parsing using stringstream*/

#if 1

int main(){

    std::string line;
    int i = 0;
    while(std::getline(std::cin, line))
    {
        
        i++;
        std::stringstream ss(line);
        int first_op = 0;
        int second_op = 0;
        char op;

        ss >> first_op >> op >> second_op;

        auto adder = [](int a, char op, int b) {
            switch (op)
            {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b != 0) {
                    return a / b;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0; 
                }
            default:
                std::cerr << "Error: Unsupported operator!" << std::endl;
                return 0; 
            }
        };
        std::cout << "Result: " << adder(first_op, op, second_op) << std::endl;
        
    }
}


#endif