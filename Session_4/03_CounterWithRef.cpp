#include<iostream>


class CounterWithRef{
private:
    int m_count, m_step;

public:
    int count(){;
        return m_count;
    }

    CounterWithRef& count(int c){
        m_count = c;
        return *this;
    }


    int step(){
        return m_step;
    }

    CounterWithRef& step(int s){
        m_step = s;
        return *this;
    }

};




int main(){
    CounterWithRef C1;

    C1.count(6).step(5);
}