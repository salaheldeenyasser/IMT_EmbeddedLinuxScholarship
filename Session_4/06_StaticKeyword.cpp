#include <iostream>


class Counter
{
    int m_count, m_step;

    static int instances;

    public:
    Counter(int c =0, int s =1) : m_count(c), m_step(s) {
        instances++;
    }

    Counter& inc() {
        m_count += m_step;
        return (*this);
    }




    static int getReferenceCount() {
        return instances;
    }
};

/**Definaition of static members*/
int Counter::instances = 0;

int Counter::getReferenceCount() {
    return Counter::instances;
}

int main() {
    Counter c1;
    Counter c2(10, 2);
    Counter c3(5);

    std::cout << "Instances: " << Counter::getReferenceCount() << std::endl;

    return 0;
}