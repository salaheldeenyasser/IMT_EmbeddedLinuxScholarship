#include <iostream>
using namespace std;

/* Key Concepts:
** Address operator (&): Gets the address of a variable
** Dereference operator (*): Accesses the value at a pointer's address
** Null pointer: A pointer that points to nothing
*/


#if 0
int main(){
    // Basic pointer declaration
    #if 0

    int x = 10;
    int *ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    *ptr = 20;

    cout << "New value of x: " << x << endl;

    #endif


    // Pointer arithmetic
    #if 0

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "First element: " << *ptr << endl;
    cout << "Second element: " << *(ptr + 1) << endl;
    cout << "Third element: " << *(ptr + 2) << endl;

    ptr++;
    cout << "After ptr incremeting: " << *ptr << endl;

    #endif

    //Pointer to Pointer
    #if 0

    int x = 100;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;

    cout << "Value of x: " << x << endl;
    cout << "*ptr1: " << *ptr1 << endl;
    cout << "**ptr2: " << **ptr2 << endl; 

    **ptr2 = 200;
    cout << "New value of x: " << x << endl;

    #endif

    return 0;
}
#endif

//Function with pointer
#if 1

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int x = 5, y = 10;
    
    cout << "Before swap: x= "<<x<<", y= "<<y<<endl;
    swap(&x,&y);
    cout << "After swap: x= "<<x<<", y= "<<y<<endl;

    return 0;
}


#endif


/* Common Pitfalls:
** Dangling pointers: Pointing to deallocated memory
** Uninitialized pointers: Using pointers without initialization
** Memory leaks: Allocating memory without freeing it
*/