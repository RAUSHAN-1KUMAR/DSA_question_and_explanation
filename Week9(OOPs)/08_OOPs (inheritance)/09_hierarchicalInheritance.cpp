/*
Hierarchical inheritance:-
    -- Multiple derived classes inherit from a single base class.
*/

// more than one child class from same base class

#include<iostream>
using namespace std;

// one base class
class Vehicle 
{
public:
    void start() {
        cout << "Starting the vehicle" << endl;
    }
};



class Car : public Vehicle 
{
public:
    void drive() {
        cout << "Driving the car" << endl;
    }
};


class Motorcycle : public Vehicle 
{
public:
    void ride() {
        cout << "Riding the motorcycle" << endl;
    }
};


int main() 
{
    Car c;
    c.start();
    c.drive();

    Motorcycle m;
    m.start();
    m.ride();

    return 0;
}



