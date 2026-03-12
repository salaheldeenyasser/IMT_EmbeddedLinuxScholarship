#include <iostream>
using namespace std;

/* Key Concepts
** Shared Memory: All members share the same memory location
** Size: Union size = size of largest member
** Mutual Exclusivity: Only one member can hold a value at a time
** Use Cases: Type punning, space-efficient data storage
*/

// Basic Union Declaration
#if 0
union Data{
    int intValue;
    float floatValue;
    char charValue;
};

int main(){
    Data data;
    cout << "Size of union: " << sizeof(data) << " Bytes" << endl;

    data.intValue = 10;
    cout << "data.intValue: " << data.intValue << endl;
    
    data.floatValue = 3.14f;
    cout << "data.floatValue: " << data.floatValue << endl;
    cout << "data.intValue: " << data.intValue << endl;

    return 0;
}

#endif

// Memory Comparison: Struct vs Union
#if 0
struct StructData{
    int a;
    float b;
    char c;
};

union UnionData{
    int a;
    float b;
    char c;
};

int main(){
    cout << "Size of struct: " << sizeof(StructData) << " bytes" << endl;
    cout << "Size of union: " << sizeof(UnionData) << " bytes" << endl;

    // Struct stores all values separately
    StructData s;
    s.a = 10;
    s.b = 3.14f;
    s.c = 'A';

    // Union overwrites when assigning
    UnionData u;
    u.a = 10;
    cout << "Union with int: " << u.a << endl;

    u.b = 3.14f;
    cout << "Union with float: " << u.b << endl;
    cout << "int value after float assignment: " << u.a << endl;  // Corrupted
    
    return 0;
}
#endif

// Union for Type Punning
//Type punning is a technique that circumvents a programming language's type system to treat a piece of memory as a different data type than originally declared.
#if 1

#endif