/*
Deallocation handling means making sure that the memory or resources you previously allocated (reserved) are properly released when you no longer need them.


Virtual Destructors for polymorphism:
    - If you delete a derived object through a base pointer, the destructor must be virtual to ensure proper deallocation of derived members. If we don't use virtual then only base destructor runs.
*/

#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal making sound" << endl;
    }

    // dtor
    virtual ~Animal(){
        cout << "Animal dtor" << endl;
    }
};

class Dog:public Animal
{
public:
    void sound() override
    {
        cout << "Dog barking" << endl;
    }

    ~Dog(){
        cout << "Dog dtor" << endl;
    }
};

class Cat:public Animal
{
public:
    void sound() override
    {
        cout << "Cat Meowing" << endl;
    }

    ~Cat(){
        cout << "Cat dtor" << endl;
    }
};

class Parrot:public Animal
{
public:
    void sound() override
    {
        cout << "mithu mithu" << endl;
    }

    ~Parrot(){
        cout << "Parrot dtor" << endl;
    }
};



void sound(Animal *animal)
{
    animal->sound();
}


int main()
{
    Animal *animal = new Dog;
    sound(animal);

    delete animal;

    return 0;
}


