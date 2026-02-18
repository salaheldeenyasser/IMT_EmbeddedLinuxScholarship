#include<iostream>


class CSwapObjects{
private:
    int m_x, m_y;

public:
    CSwapObjects(int x, int y) : m_x(x), m_y(y) {}


    CSwapObjects swap(CSwapObjects &other){
        int tempX = m_x;
        int tempY = m_y;

        m_x = other.m_x;
        m_y = other.m_y;

        other.m_x = tempX;
        other.m_y = tempY;

        return *this ;
    }


    CSwapObjects& print(){
        std::cout << "x: " << m_x << ", y: " << m_y << std::endl;
        return *this;
    }

    CSwapObjects remove(){
        m_x = 0;
        m_y = 0;
        return *this;   
    }
};




int main(){
    CSwapObjects obj1(10, 20);
    CSwapObjects obj2(30, 40);

    std::cout << "Before swap:" << std::endl;
    obj1.print().swap(obj2);
    std::cout << "After swap:" << std::endl;
    obj1.print();
    std::cout << "After remove:" << std::endl;
    obj1.remove().print();
    return 0;
}