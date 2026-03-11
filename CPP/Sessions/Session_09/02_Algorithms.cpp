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


string  join(string acc, string next ){
    return (acc+','+next);
}

int main(int argc=0,char*argv[] = nullptr){
    
    vector<string> csv_line = {"Name", "Age", "Length"};
    
    string joined = accumulate(csv_line.begin()+1, csv_line.end(),
                                csv_line[0], join);
    // joined = joined.erase(0,1);
    cout<<joined<<endl;
    return 0;
}