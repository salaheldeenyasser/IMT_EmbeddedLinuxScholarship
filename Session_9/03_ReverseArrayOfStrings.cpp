#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include<tuple>
#include <numeric>
using namespace std;

int main(){
    string str;

    getline(cin, str);

    // reverse(str.begin(), str.end());
    // cout<< "reversed string: "<< str <<endl;

    std::stringstream ss(str);
    std::string word;
    std::string result = "";

    while (ss >> word) {
        // Reverse the individual word
        std::reverse(word.begin(), word.end());

        // Append the reversed word to the result, with a space
        result += word + " ";
    }

    cout<<result<<endl;
}