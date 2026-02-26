#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <any>
#include <variant>
using namespace std;

struct Point2d{
    int x,y;
};

struct Point3d{
    int x,y,z;
};

struct PointVisitor{
    void operator()(Point2d p2d) const{
        cout<<"("<<p2d.x<<","<<p2d.y<<")"<<endl;
    }
    void operator()(Point3d p3d) const{
        cout<<"("<<p3d.x<<","<<p3d.y<<","<<p3d.z<<")"<<endl;
    }
};

int main(){
    variant<int, float, string> var;

    var = 10;

    cout<< "has int? : "<<(holds_alternative<int>(var) ? "true":"false") <<endl;

    var = "hello";

    cout<< "has string? : "<<(holds_alternative<string>(var) ? "true":"false") <<endl;

    if(holds_alternative<string>(var)){
        cout<<"string in variant is: "<< get<string>(var)<<endl;
    }


    //visitor pattern
    variant<Point2d, Point3d> var_point;
    Point2d p1 = {10, 20};
    Point3d p2 = {40, 50, 60};
    
    var_point = p1;
    visit(PointVisitor(), var_point);

    var_point = p2;
    visit(PointVisitor(), var_point);

}