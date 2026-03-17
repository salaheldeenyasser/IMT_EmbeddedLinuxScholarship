#include <iostream>
// Liskov Substitution Principle (LSP)
/*
** Definition: Subtypes must be substitutable for their base types without altering the correctness of the program.
** Problem: A base class "Creature" with a method "move()", and two derived classes "seaCreature" and "landCreature". If we create a function that takes a "Creature" pointer and calls "move()", it should work correctly for both "seaCreature" and "landCreature". However, if "landCreature" has an additional method "makeSound()", and we try to call it on a "Creature" pointer, it will fail for "seaCreature", violating LSP.
** Solution: Ensure that derived classes can be used interchangeably with their base class without causing any issues. In this case, we can keep the "makeSound()" method in "landCreature" and not try to call it on a "Creature" pointer, or we can design the classes in a way that "makeSound()" is not part of the base class if it's not applicable to all derived classes.
*/

class Creature
{
public:
    virtual void move() = 0;
    virtual ~Creature() = default;
};

class seaCreature : public Creature
{
public:
    void move() override
    {
        std::cout << "The sea creature swims." << std::endl;
    }
};

class landCreature : public Creature
{
public:
    void makeSound()
    {
        std::cout << "The land creature makes a sound." << std::endl;
    }
    void move() override
    {
        std::cout << "The land creature walks." << std::endl;
    }
};

class fish : public seaCreature
{
public:
    void move() override
    {
        std::cout << "The fish swims." << std::endl;
    }
};

class dog : public landCreature
{
public:
    void move() override
    {
        std::cout << "The dog walks." << std::endl;
    }
};

void moveCreature(Creature *creature)
{
    creature->move();
}

void makeSound(landCreature *creature)
{
    creature->makeSound();
}

int main()
{
    Creature *myFish = new fish();
    Creature *myDog = new dog();

    moveCreature(myFish);
    moveCreature(myDog);

    makeSound(dynamic_cast<landCreature *>(myDog));

    return 0;
}