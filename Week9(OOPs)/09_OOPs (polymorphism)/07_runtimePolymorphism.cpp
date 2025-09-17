/*
function overriding: already discussed
*/

#include<iostream>
using namespace std;

class Animal
{
public:
    void sound()
    {
        cout << "Animal making sound" << endl;
    }
};

class Dog:public Animal
{
public:
    void sound()
    {
        cout << "Dog barking" << endl;
    }
};

class Cat:public Animal
{
public:
    void sound()
    {
        cout << "Cat Meowing" << endl;
    }
};



void sound(Animal *animal)
{
    animal->sound();
}


int main()
{
    // a base class pointer points to its derived class object
    Animal *animal = new Dog;//-> this code is running in run time
    sound(animal);

    animal = new Cat;
    sound(animal);

    return 0;
}


/*
Ouput:-
Animal making sound
Animal making sound

-- because at time of compilation the animal PTR points to Animal class as it has declared to it and then at the run time the 'new Dog' sets a pointer to Dog object but initially the animal pointer has declared statically in compiler time so it will not change.
    So, we need a way to tell the compiler that kon sa sound call hoga-> see next code
*/
