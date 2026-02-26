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


struct Point3d{
    int x,y,z;

    Point3d(int xx, int yy, int zz):x(xx),y(yy),z(zz){}
    void display(){
        stringstream ss;
        ss << "(" << x << "," << y << "," << z << ")";
        cout << ss.str() << endl;
    }
};

int main(){
    //create unique pointer
    unique_ptr<int> un_int1 =make_unique<int>(15); //good practice

    //print unique pointer
    cout<<*un_int1<<endl;

    //get raw pointer
    cout<<un_int1.get()<<endl;

    unique_ptr<int> un_int2;
    //move ownership
    un_int2 = move(un_int1);

    unique_ptr<Point3d> un_p3d(new Point3d(3,2,5)); //not good practice

    un_p3d->display();

    unique_ptr<Point3d> un_p3d2;

    un_p3d2 = move(un_p3d);

    un_p3d2->display();

    if(!un_p3d) cout<< "old point is now null"<<endl;

    return 0;


}