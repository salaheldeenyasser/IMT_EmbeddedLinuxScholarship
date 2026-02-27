#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    map<string,int> m={
        {"mazen",30},
        {"nabil",27}
    };

    if(m.count("mazen")){
        cout<<"mazen exists in map"<<endl;
    }

    for(auto it = m.begin();it!=m.end();it++){
        cout<<"key: "<<it->first<<", value: "<<it->second<<endl;
    }
}