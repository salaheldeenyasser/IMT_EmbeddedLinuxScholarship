#include<iostream>

class CInteger{
private:
    int m_number;

public:

    CInteger(int number) : m_number(number) {}

    int operator+(CInteger& other) {
        return m_number + other.m_number;
    }

    int operator-(CInteger& other) {
        return m_number - other.m_number;
    }

    int operator*(CInteger& other) {
        return m_number * other.m_number;
    }

    int operator/(CInteger& other) {
        if (other.m_number != 0) {
            return m_number / other.m_number;
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0; 
        }
    }

    int operator%(CInteger& other) {
        if (other.m_number != 0) {
            return m_number % other.m_number;
        } else {
            std::cerr << "Error: Modulo by zero!" << std::endl;
            return 0; 
        }
    }

    int operator++() {
        m_number++;
        return m_number;
    }

    int operator++(int) {
        int temp = m_number;
        m_number++;
        return temp;
    }

    int operator--() {
        m_number--;
        return m_number;
    }

    int operator--(int) {
        int temp = m_number;
        m_number--;
        return temp;
    }

    void operator+=(CInteger& other) {
        m_number += other.m_number;
    }

    void operator-=(CInteger& other) {
        m_number -= other.m_number;
    }

    /*--------------------------------------*/

    bool operator==(CInteger& other) {
        return m_number == other.m_number;
    }

    bool operator!=(CInteger& other) {
        return m_number != other.m_number;
    }

    bool operator<(CInteger& other) {
        return m_number < other.m_number;
    }

    bool operator>(CInteger& other) {
        return m_number > other.m_number;
    }

    bool operator<=(CInteger& other) {
        return m_number <= other.m_number;
    }

    bool operator>=(CInteger& other) {
        return m_number >= other.m_number;
    }

    /*--------------------------------------*/
    int operator!() {
        return !m_number;
    }

    int operator&&(CInteger& other) {
        return m_number && other.m_number;
    }

    int operator||(CInteger& other) {
        return m_number || other.m_number;
    }

    /*--------------------------------------*/



    void print(){
        std::cout << "Number: " << m_number << std::endl;
    }


};



int main(){
    CInteger num1(10);
    CInteger num2(5);

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    int quotient = num1 / num2;
    int modulo = num1 % num2;
    int preIncrement = ++num1;
    int postIncrement = num1++;
    int preDecrement = --num2;
    int postDecrement = num2--;
    int notValue = !num1;
    int andValue = num1 && num2;
    int orValue = num1 || num2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;
    std::cout << "Modulo: " << modulo << std::endl;
    std::cout << "Pre-Increment: " << preIncrement << std::endl;
    std::cout << "Post-Increment: " << postIncrement << std::endl;
    std::cout << "Pre-Decrement: " << preDecrement << std::endl;
    std::cout << "Post-Decrement: " << postDecrement << std::endl;
    std::cout << "Not Value: " << notValue << std::endl;
    std::cout << "And Value: " << andValue << std::endl;
    std::cout << "Or Value: " << orValue << std::endl;

    return 0;
}