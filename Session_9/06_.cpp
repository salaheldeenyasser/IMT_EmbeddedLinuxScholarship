#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main(){

    vector<int> v{2,8,5,3,9,2,0};
    for_each(v.begin(),v.end(), [](int & a){
        cout<< a<<',';} );
    
        int counter = count_if(v.begin(), v.end(), [](int & a){ 
        return (a%2 ==0);});

    cout<<endl<<counter<<endl;
    
    sort(v.begin(),v.end(),[](int &a,int &b){
        return a<b;
    });

    for_each(v.begin(),v.end(), [](int & a){
        cout<< a<<',';} );

    auto num = std::find_if(v.begin(), v.end(), [](int& s) {
        return (s%2==0);
    });

    cout<<endl<<num[0]<<endl;

    vector<int> v2;
    transform(v.begin(), v.end(), std::back_inserter(v2), [](int x){
        return x * 2; });

    for_each(v2.begin(),v2.end(), [](int & a){
        cout<< a<<',';} );
    
    cout<<endl;
    v.erase(remove_if(v.begin(), v.end(), [](int n) {
        return n % 2 != 0;
    }));

    for_each(v.begin(),v.end(), [](int & a){
        cout<< a<<',';} );
    cout<<endl;
}