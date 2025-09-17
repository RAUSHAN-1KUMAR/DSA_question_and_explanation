/*
Single inheritnace:-
    - A derived class inherits from only one base class i.e., one base class and one derived class
*/

#include<iostream>
using namespace std;

// one base class
class Animal 
{
public:
    void eat() {
        cout << "Eating" << endl;
    }
};

// one derived class
class Dog : public Animal 
{
public:
    void bark() {
        cout << "Barking" << endl;
    }
};

int main() 
{
    Dog d;
    d.eat();  // Inherited from Animal
    d.bark();

    return 0;
}
