#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

bool isValidFormat(const std::string& path) {
    if (path.empty()) return false;
    if (path.length() >= 3 && isalpha(path[0]) && path[1] == ':' && (path[2] == '\\' || path[2] == '/')) return true;
    if (path[0] == '/') return true;
    return false;
}

int main() {
    std::string userInput;
    std::stack<std::string> pathStack;
    std::vector<std::string> pathVector;

    std::cout << "Enter a path: ";
    std::getline(std::cin, userInput);

    if (isValidFormat(userInput)) {
        std::cout << "Format is valid.\n";

        pathStack.push(userInput);

        pathVector.push_back(pathStack.top());
        pathStack.pop();

        std::reverse(pathVector[0].begin(), pathVector[0].end());
        std::cout << "Reversed in vector: " << pathVector[0] << "\n";

        std::string processed = std::accumulate(pathVector.begin(), pathVector.end(), std::string(""));

        std::reverse(processed.begin(), processed.end());
        
        std::replace(processed.begin(), processed.end(), '/', '\\');
        
        pathStack.push(processed);

        std::cout << "Final path in stack (Corrected): " << pathStack.top() << "\n";
    } else {
        std::cout << "Invalid path format. Please start with a drive letter (C:\\) or a slash (/).\n";
    }

    return 0;
}