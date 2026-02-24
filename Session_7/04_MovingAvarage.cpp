#include<iostream>
#include<queue>
#include<sstream>
#include<cctype>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    queue<int> q;
    double sum = 0,avg = 0;

    for(int i= 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        
        for(int j= 0; j<3;j++){
            if(q.size() != 3){
                q.push(arr[i+j]);
                sum+=q.back();
            }
            else{
                avg = sum/3;
                sum-=q.front();
                q.pop();
                cout<<avg<<",";
            }
        }
    }
    


}