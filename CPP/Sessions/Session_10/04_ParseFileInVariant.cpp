#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <any>
#include <fstream>
#include <sstream>
#include <variant>
using namespace std;


int main(){
    
    
    vector<variant<int, float, string>> var_vec;
    string v;
    int i;float f; string s;

    while(cin >> v){
        stringstream ss(v);
        ss >> i >> f >> s;

    }

    auto visitor = [](const auto& v){
        cout<< "I am a " << typeid(v).name() << endl;
    };

    for(const auto& v : var_vec){
        visit(visitor, v);
    }

}