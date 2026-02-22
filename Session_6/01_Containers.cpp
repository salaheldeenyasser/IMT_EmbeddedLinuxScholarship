#include<iostream>
#include<array>
#include<vector>

int main(){
    //array container
    #if 0
    std::array<int, 10> arr = {10,20,30};


    //Accessing array
    arr[0] = 30;
    arr.at(6) = 100; // performs bounds checking

    /* try{
        arr.at(12);
    }
    catch(ex){

    } */

    //Looping on array
    for(int val:arr){ //may be int& val 
        std::cout<<val<<std::endl;

    }

    for(auto it = arr.begin(); it!=arr.end(); ++it){  //.begin() returns a pointer to arr start
        std::cout <<*it<<std::endl;
    }

    //Access front and back
    int first = arr.front();
    int back = arr.back();

    //Fill array with values
    arr.fill(0);

    //Check if array is empty
    if(!arr.empty()){
        std::cout<<"array is not empty"<<std::endl;
    }

    //Get ponter to underlying data
    int* data = arr.data(); //not preferable
    std::cout<< "First element of arr via pointer"<< *data<<std::endl;


    #endif


    #if 1

    std::vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v[0] = 20;

    int last  =v.back();//returns last value
    v.pop_back(); //does not return

    int carray[] = {1,2,3,4,5,6};
    // std::vector<int> vfromcarry(std::)

    #endif


}