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
using namespace std;

int main()
{
    string str;

    getline(cin, str);

    stringstream ss(str);
    string word;

    vector<string> v;

    while (ss >> word)
    {
        v.push_back(word);
    }
    reverse(v.begin(), v.end());
    string reversed = "";

    for_each(v.begin(), v.end(), [&reversed](string s){
        reversed+=s;
        if(!reversed.empty()){reversed+=' ';}});
    cout << reversed << endl;
    return 0;
}