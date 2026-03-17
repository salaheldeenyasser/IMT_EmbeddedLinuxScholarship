#include <iostream>

class IPrinter
{
public:
    virtual void print() = 0;
    virtual ~IPrinter() = default;
};

class IScanner
{
public:
    virtual void scan() = 0;
    virtual ~IScanner() = default;
};

class IFax
{
public:
    virtual void fax() = 0;
    virtual ~IFax() = default;
};

class IStapler
{
public:
    virtual void staple() = 0;
    virtual ~IStapler() = default;
};

class BasicPrinter : public IPrinter
{
public:
    void print() override
    {
        std::cout << "Printing..." << std::endl;
    }
};

class Scanner : public IScanner
{
public:
    void scan() override
    {
        std::cout << "Scanning..." << std::endl;
    }
};

class ALLInOnePrinter : public IPrinter, public IScanner, public IFax, public IStapler
{
public:
    void print() override
    {
        std::cout << "Printing..." << std::endl;
    }
    void scan() override
    {
        std::cout << "Scanning..." << std::endl;
    }
    void fax() override
    {
        std::cout << "Faxing..." << std::endl;
    }
    void staple() override
    {
        std::cout << "Stapling..." << std::endl;
    }
};