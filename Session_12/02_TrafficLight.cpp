#include <iostream>
#include <string>
#include <array>
#include <memory>

using namespace std;

#if 0
class TrafficLight
{
    enum class State
    {
        Red,
        Yellow,
        Green
    };
    State currentState;

public:
    TrafficLight() : currentState(State::Red) {}
    void change()
    {
        switch (currentState)
        {
        case State::Red:
            currentState = State::Green;
            break;
        case State::Green:
            currentState = State::Yellow;
            break;
        case State::Yellow:
            currentState = State::Red;
            break;
        }
    }
    

    State getState() const
    {
        return currentState;
    }

    void display() const
    {
        switch (currentState)
        {
        case State::Red:
            std::cout << "Red Light" << std::endl;
            break;
        case State::Green:
            std::cout << "Green Light" << std::endl;
            break;
        case State::Yellow:
            std::cout << "Yellow Light" << std::endl;
            break;
        }
    }
};

int main()
{
    TrafficLight light;
    while (true)
    {
        for (int i = 0; i < 30; ++i)
        {
            light.display();
            cout << "remaining time: " << 30 - i << " seconds" << endl;
        }
        light.change();
        for (int i = 0; i < 60; ++i)
        {
            light.display();
            cout << "remaining time: " << 60 - i << " seconds" << endl;
        }
        light.change();
        for (int i = 0; i < 10; ++i)
        {
            light.display();
            cout << "remaining time: " << 10 - i << " seconds" << endl;
        }
    }

    return 0;
}

#endif

#if 1

// State Design Pattern
// Context
class TrafficLightContext
{
    unique_ptr<TrafficLightState> currentState;
public:
    TrafficLightContext():currentState(make_unique<stateRed>()){}
    void setState(unique_ptr<TrafficLightState> newState){
        currentState = move(newState);
    }
};

// State interface
class TrafficLightState
{
    public:
    virtual void onTimer(TrafficLightContext& context) = 0;
    virtual void display() const = 0;
    virtual void onButtonPress(TrafficLightContext& context) = 0;

};

// Concrete states
class stateRed : public TrafficLightState
{
    public:
    void onTimer(TrafficLightContext& context) override{
        // Transition to Green
    }
    void display() const override{
        cout<<"Red Light"<<endl;
    }
    void onButtonPress(TrafficLightContext& context) override{
        context.setState(make_unique<stateGreen>());
};

class stateGreen : public TrafficLightState
{
    public:
    void onTimer(TrafficLightContext& context) override{
        // Transition to Yellow
    }
    void display() const override{
        cout<<"Green Light"<<endl;
    }
    void onButtonPress(TrafficLightContext& context) override{
        context.setState(make_unique<stateYellow>());
};

class stateYellow : public TrafficLightState
{
    public:
    void onTimer(TrafficLightContext& context) override{
        // Transition to Red

    }
    void display() const override{
        cout<<"Yellow Light"<<endl;
    }
    void onButtonPress(TrafficLightContext& context) override{
        context.setState(make_unique<stateRed>());
};








#endif