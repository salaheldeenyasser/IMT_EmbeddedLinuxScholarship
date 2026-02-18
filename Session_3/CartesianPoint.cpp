#include <iostream>

class CCartesianPoint
{
public:
    CCartesianPoint(double x, double y) : m_x(x), m_y(y) {}

    float operator*(const CCartesianPoint other) const
    {
        return this->m_x * other.m_x + this->m_y * other.m_y;
    }

private:
    float m_x;
    float m_y; 
};



int main()
{
    CCartesianPoint point1(2.0, 3.0);
    CCartesianPoint point2(4.0, 5.0);

    int result = point1 * point2;

    std::cout << result << std::endl;

    return 0;
}
