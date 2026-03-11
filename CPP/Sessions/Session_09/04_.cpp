#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <iterator>

using namespace std;


string  join(string acc, string next ){
    return (acc+','+next);
}

bool isEven(int num){
    return (num%2 == 0);
}

class NumChecker{
    
    bool isEven(int n){return (n%2==0);}

    public:
    // NumChecker(){}
    // NumChecker(int Num):m_num(num){}

    bool operator()(int num){
        return isEven(num);
    }
};


int main(int argc=0,char*argv[] = nullptr){
    
    vector<string> csv_line = {"Name", "Age", "Length"};
    
    string joined = accumulate(csv_line.begin()+1, csv_line.end(),
                                csv_line[0], join);
    // joined = joined.erase(0,1);
    cout<<joined<<endl;


    vector<string> copied;
    // copied.resize(csv_line.size());

    copy(csv_line.begin(), csv_line.end(), back_inserter(copied));

    joined = accumulate(copied.begin()+1, copied.end(),
                        copied[0], join);


    cout<<joined<<endl;
    
    vector<int> nums = {1,2,3,4,5,6,7,8,9};                                
    
    vector<int> evens;

    copy_if(nums.begin(), nums.end(), back_inserter(evens), isEven);

    for_each(evens.begin(), evens.end(), [](int a){ cout<<a<<' ';});

    return 0;

    




}