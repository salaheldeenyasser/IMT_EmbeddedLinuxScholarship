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
namespace MyApp
{
    int x = 1;

    void print()
    {
        cout << "My app" << endl;
    }

    class MyData
    {
    public:
        static void data()
        {
            cout << "class" << endl;
        }
    };
}


// can expand a namespace
namespace MyApp
{
    void stop() {}
}

// nested namespace before c++17
namespace Company
{
    namespace Project
    {
        namespace Module
        {
            void run()
            {
                cout << "nested" << endl;
            }
        }
    }
}

namespace Company::Project::Module
{
    void run2()
    {
        cout << "nested" << endl;
    }
}

//anonimous namespace
namespace{
    int z;
}

// Alias for namespace
namespace AliasForNamespace{
    void print(){

    }
}
namespace AliasN = AliasForNamespace; //can be used to access a nested namespace


//versioning
namespace MyLib{
    inline namespace V2{ //defines the default version
        void func(){
            cout<<"version 2"<<endl;
        }

    }
}


namespace st{
    struct name{
        int x= 10;
        int y= 20;
        int z= 30;
    };
}



int main()
{
    MyApp::x = 20;
    MyApp::print();
    MyApp::MyData c;
    c.data();
    MyApp::MyData::data();


    MyLib::func();

    st::name n;
    auto [a,b,o] = n;

    return 0;
}