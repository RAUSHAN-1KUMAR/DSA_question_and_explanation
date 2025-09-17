/*
Previously (without virtual): for each of the child class, the data members and function of common base class were passed

Solving the ambiguity using virtual inheritance
    -- Virtual inheritance can solve the ambiguity problem by ensuring that only one instance of the common base class is shared among all the derived classes(at run time). This way, derived classes that inherit from the same base class do not create separate instances of that base class, which eliminates ambiguity

Virtual inheritance says, abhi inherit mat kro, compile time ke waqt dekh lengen.

In C++, inheritance is resolved during compilation and object construction, not dynamically at runtime (except for virtual functions).

*/

#include<iostream>
using namespace std;


class Engine 
{
public:
    void start() {
        cout << "Engine starting" << endl;
    }
};


class Vehicle : virtual public Engine 
{
public:
    void drive() {
        cout << "Driving the vehicle" << endl;
    }
}; 


class Airplane : virtual public Engine 
{
public:
    void fly() {
        cout << "Flying the airplane" << endl;
    }
};


class FlyingCar : public Vehicle, public Airplane 
{

};


int main() 
{
    FlyingCar fc;

    fc.drive();
    
    return 0;
}

