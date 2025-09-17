/*
virtual function-> just we used in hybrid inheritance
    -- When a function is declared as virtual in a base class, it indicates that the function can be overridden in any derived class, and the appropriate version of the function is called based on the type of the object that is referred to or pointed to, rather than the type of the reference or pointer itself..
*/

#include<iostream>
using namespace std;

class Animal
{
public:
    // virtual function, isko sach mat maano
    virtual void sound()
    {
        cout << "Animal making sound" << endl;
    }
};

class Dog:public Animal
{
public:
    // override keyword may be used or may not be becuase it's just to increase the readability of the code
    void sound() override
    {
        cout << "Dog barking" << endl;
    }
};

class Cat:public Animal
{
public:
    void sound() override
    {
        cout << "Cat Meowing" << endl;
    }
};

class Parrot:public Animal
{
public:
    void sound() override
    {
        cout << "mithu mithu" << endl;
    }
};



void sound(Animal *animal)
{
    animal->sound();// polymorphic
    // animal->sound() is bahaving as per required object allocated at runtime.
}


int main()
{

    Animal *animal = new Dog;
    sound(animal);

    animal = new Cat;
    sound(animal);

    animal = new Parrot();
    sound(animal);

    return 0;
}


