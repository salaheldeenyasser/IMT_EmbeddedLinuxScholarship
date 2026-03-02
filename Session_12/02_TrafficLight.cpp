#include <iostream>
#include <string>

using namespace std;

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