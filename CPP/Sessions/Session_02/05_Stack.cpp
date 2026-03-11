#include<iostream>

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int num){

        arr[++top] = num;
    }
    void pop(){
        arr[top--]= 0;
        
    }
    int isEmpty(){
        if(top == -1){
            std::cout << "Stack is empty ";
            return 1;
        }
        else{
            std::cout << "Stack is not empty ";
            return 0;
        }
    }
    int isFull(){
        if(top == capacity){
            std::cout<<"Stack is full";
            return 1;
        }
        else{
            std::cout<<"Stack is not full";
            return 0;
        }
    }
    int getSize(){
        return capacity;
    }

    //int*  
};

