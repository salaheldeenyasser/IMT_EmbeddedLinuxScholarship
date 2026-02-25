#include<iostream>
#include<vector>
#include<format>
#include<map>
using namespace std;

struct Person{
    string name;
    int age;
};


struct Address{
    string street;
    string country;
    int building_no;

    bool operator<(Address &other){
        return(
            this->street < other.street && this->country < other.country && this->building_no < other.building_no
        );
    }
};

map<Address,Person> google_maps;