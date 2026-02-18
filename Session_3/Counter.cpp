#include<iostream>

class CCounter
{
public:
    CCounter() : m_count(0), m_step(1) {}
    CCounter(int count, int step) : m_count(count), m_step(step) {}
    CCounter(int count) : m_count(count), m_step(1) {}

    int operator++() {
        m_count += m_step;
        return m_count;
    }

    int operator++(int) {
        int oldCount = m_count;
        m_count += m_step;
        return oldCount;
    }

private:
    int m_count;
    int m_step;
};




int main()
{
    CCounter CCounter1;
    CCounter CCounter2(10, 2);
    CCounter CCounter3(5);

    ++CCounter1;
    ++CCounter2;
    ++CCounter3;

    std::cout << "Counter 1: " << CCounter1.operator++() << std::endl;
    std::cout << "Counter 2: " << CCounter2.operator++() << std::endl;
    std::cout << "Counter 3: " << CCounter3.operator++() << std::endl;

    CCounter1++;
    CCounter2++;
    CCounter3++;

    std::cout << "Counter 1: " << CCounter1.operator++(0) << std::endl;
    std::cout << "Counter 2: " << CCounter2.operator++(0) << std::endl;
    std::cout << "Counter 3: " << CCounter3.operator++(0) << std::endl;
    return 0;
}