#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <any>
using namespace std;

template <typename T>
T any_get(any x)
{
    T d;
    if (x.type() == typeid(T))
    {
        // cout <<"any double: " << any_cast<T>(x) << endl;
        d = any_cast<T>(x);
        return d;
    }
    return d;
}

int main()
{

    any x = string(" ");

    cout << "any int: " << any_cast<int>(10) << endl;

    x = 3.14;

    cout << "any now has a type of: " << string(x.type().name()) << endl;

    if (x.type() == typeid(double))
    {
        cout << "any double: " << any_cast<double>(x) << endl;
    }

    double dd = any_get<double>(x);

    any vec = vector<int>{1, 2, 3, 4, 5, 6};

    vector<int> vec2 = any_get<vector<int>>(vec);

    std::vector<std::any> any_vec;
    any_vec.push_back(10);                   // int
    any_vec.push_back(3.14);                 // double
    any_vec.push_back(std::string("Hello")); // string

    for_each(any_vec.begin(), any_vec.end(), [](any &a) {
        if (a.type() == typeid(int)) {
            cout << "int: " << any_cast<int>(a) << endl;
        } else if (a.type() == typeid(double)) {
            cout << "double: " << any_cast<double>(a) << endl;
        } else if (a.type() == typeid(std::string)) {
            cout << "string: " << any_cast<std::string>(a) << endl;
        }
    });

    return 0;
}