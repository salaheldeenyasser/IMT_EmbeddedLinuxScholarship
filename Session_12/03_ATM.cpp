#include <iostream>
#include <string>

using namespace std;

class ATMContext
{
private:
    ATMState *currentState;

public:
    ATMContext() : currentState(nullptr) {}
    void setState(ATMState *newState)
    {
        currentState = newState;
    }
};
class ATMState
{
public:
    virtual void insertCard(ATMContext &context) = 0;
    virtual void enterPin(ATMContext &context) = 0;
    virtual void selectOperation(ATMContext &context) = 0;
    virtual void ejectCard(ATMContext &context) = 0;
};

class ATMStateIdle : public ATMState
{
public:
    void insertCard(ATMContext &context) override
    {
        context.setState(new ATMStateCardInserted());
    }
    void enterPin(ATMContext &context) override
    {
        // Invalid action in Idle state
    }
    void selectOperation(ATMContext &context) override
    {
        // Invalid action in Idle state
    }
    void ejectCard(ATMContext &context) override
    {
        // Invalid action in Idle state
    }
};

class ATMStateCardInserted : public ATMState
{
public:
    void insertCard(ATMContext &context) override
    {
        // Invalid action in CardInserted state
    }
    void enterPin(ATMContext &context) override
    {
        context.setState(new ATMStatePinEntered());
    }
    void selectOperation(ATMContext &context) override
    {
        // Invalid action in CardInserted state
    }
    void ejectCard(ATMContext &context) override {}
};

class ATMStatePinEntered : public ATMState
{
public:
    void insertCard(ATMContext &context) override
    {
        // Invalid action in PinEntered state
    }
    void enterPin(ATMContext &context) override
    {
        // Invalid action in PinEntered state
    }
    void selectOperation(ATMContext &context) override
    {
        // Transition to OperationSelected state
        context.setState(new ATMStateSelectingOperation());
    }
    void ejectCard(ATMContext &context) override
    {
        // Transition to Idle state
    }
};

class ATMStateSelectingOperation : public ATMState
{
public:
    void insertCard(ATMContext &context) override
    {
        // Invalid action in SelectingOperation state
    }
    void enterPin(ATMContext &context) override
    {
        // Invalid action in SelectingOperation state
    }
    void selectOperation(ATMContext &context) override
    {
        // Invalid action in SelectingOperation state
    }
    void ejectCard(ATMContext &context) override
    {
        // Transition to Idle state
        context.setState(new ATMStateIdle());
    }
};

int main()
{
    
}