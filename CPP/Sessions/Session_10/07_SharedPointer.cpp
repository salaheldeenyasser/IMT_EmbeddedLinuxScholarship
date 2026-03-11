#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <any>
#include <fstream>
#include <sstream>
#include <variant>
#include <memory>
#include <utility>

using namespace std;


int main(){
    //creating pointer
    shared_ptr<int> sh_int = make_shared<int>(20);
    shared_ptr<int> sh_int2 = sh_int;

    //printing reference count
    cout<<"ref count for sh_ptr= "<< sh_int.use_count()<<endl;

    cout<<"ref count for sh_ptr2= "<< sh_int2.use_count()<<endl;

    shared_ptr<int> sh_int3(new int(50));
    cout<<"ref count for sh_ptr3= "<< sh_int3.use_count()<<endl;

    //deleting pointer
    sh_int2.reset();
    if(!sh_int2) cout<<"sh_int2 is now null and ref_count= "<< sh_int.use_count()<<endl;
}