#include    <iostream>  



class CBankAccount{
private:
    int m_AccessCount = 0;
    double m_Balance = 1000.0;
    const int m_AccessTime;

public:
    CBankAccount(double balance) : m_Balance(balance), m_AccessCount(0), m_AccessTime(0) {}

    double getBalance()const{
        /* std ::cout << m_Balance << std::endl; */
        return m_Balance;
    }

    double getBalance(){
        return m_Balance;
    }


    double getAccessCount() const {
        return m_AccessCount;
    }


};


int main(){

    CBankAccount account(1000.0);

    std::cout << "Initial Balance: " << account.getBalance() << std::endl;
    std::cout << "Access Count: " << account.getAccessCount() << std::endl;

    account.getBalance();
    account.getBalance();

    std::cout << "Balance after access: " << account.getBalance() << std::endl;
    std::cout << "Access Count after access: " << account.getAccessCount() << std::endl;

    return 0;

}