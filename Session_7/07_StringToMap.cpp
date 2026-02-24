#include<iostream>
#include<string>
#include<map>
using namespace std;


int main(){
    string str = "apple lemon mango strawberry mango mango";
    map<string,int> m;


    for(int i = 0; i < str.length(); i++){
        string word = "";
        while(i < str.length() && str[i] != ' '){
            word += str[i];
            i++;
        }
        m[word]++;
    }

    for(auto it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }
    


}