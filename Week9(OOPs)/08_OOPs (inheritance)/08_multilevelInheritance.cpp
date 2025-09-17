/*
Multilevel inheritance:-
    -- A derived class inherits from another drived class creating a chain of inheritance.
*/

#include<iostream>
using namespace  std;

// parent class
class LivingThing 
{
public:
    void breathe() {
        cout << "Breathing" << endl;
    }
};

// child class
class Animal : public LivingThing 
{

};

// grand child class
class Human : public Animal 
{
public:
    void speak() {
        cout << "Speaking" << endl;
    }
};

int main() 
{
    Human h;
    h.breathe();  // Inherited from LivingThing
    h.speak();

    return 0;
}
