#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include<tuple>
using namespace std;

enum{
    NAME,AGE,LENGTH
};

struct Phase{
    

};

struct phaseVector{
    Phase phase1;
    Phase phase2;
    Phase phase3;

    Phase operator[](int i){
        switch (i){
            case 0: return phase1;
            case 1: return phase2;
            case 2: return phase3;
            default: throw std::out_of_range() ; 
        }
    }
};

phaseVector pv;

pv.phase

int main(int argc,char * argv[]){
    tuple<string,int,float> t = {"mazen", 30,151.25};
    //tuple<string, int,float> t1 = make_tuple<string,int,float>("mazen", 30,151.25);
    tuple<string,int, int,float> t2 = make_tuple<string,int,int ,float>("mazen", 30,50,151.25); //error

    // auto name = std::get<0>(t);
    // auto age = get<int>(t);
    // auto length = get<float>(t);


    //unpacking(structure binding)
    auto &[name,age,age2,length] = t2;
    cout<<name<<age<< length<<endl;

    get<0>(t) = "ahmed";

    name = std::get<0>(t);
    cout<<name<<age<< length<<endl;



    auto name = std::get<0>(t);
    auto age = get<int>(t);
    auto length = get<float>(t);



}
