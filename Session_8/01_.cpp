#include<iostream>
#include<vector>
#include<format>
using namespace std;




int main(){
    struct point{
        point(int x,int y, int z):_x(x),_y(y),_z(z){
            cout<<"created point with()"<<x<<y<<z<<endl;
        } 

        int _x,_y,_z;
    };
    vector<point> points;
    points.push_back( point(1,2,3));
    points.emplace_back(4,5,6);
}
