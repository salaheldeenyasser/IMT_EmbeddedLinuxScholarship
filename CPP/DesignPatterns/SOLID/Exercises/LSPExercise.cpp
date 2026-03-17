#include <iostream>


class Creature{
    public:
    virtual void move() = 0;    
    virtual ~Creature() = default;
};


class seaCreature : public Creature{
    public:
    void move() override{
        std::cout << "The sea creature swims." << std::endl;
    }
};


class landCreature : public Creature{
    public:
    void makeSound(){
        std::cout << "The land creature makes a sound." << std::endl;
    }
    void move() override{
        std::cout << "The land creature walks." << std::endl;
    }
};

class fish : public seaCreature{
    public:
    void move() override{
        std::cout << "The fish swims." << std::endl;
    }
};

class dog : public landCreature{
    public:
    void move() override{
        std::cout << "The dog walks." << std::endl;
    }
};

void moveCreature(Creature* creature){
    creature->move();
}

void makeSound(landCreature* creature){
    creature->makeSound();
}


int main(){
    Creature* myFish = new fish();
    Creature* myDog = new dog();

    moveCreature(myFish);
    moveCreature(myDog);

    makeSound(dynamic_cast<landCreature*>(myDog));

    return 0;
}