/*
Hybrid Inheritance:-    
    -- A combination of two or more types of inheritance. It often involves a mix of single, multiple, and heirarchical inheritance.
*/

// the diamond problem

#include<iostream>
using namespace std;

// one master class
class Engine 
{
public:
    void start() {
        cout << "Engine starting" << endl;
    }
};

// two child class from master class(heirarchical inheritance)
class Vehicle : public Engine 
{
public:
    void drive() {
        cout << "Driving the vehicle" << endl;
    }
};

class Airplane : public Engine 
{
public:
    void fly() {
        cout << "Flying the airplane" << endl;
    }
};

// one child class from both parent class(multilevel inheritance)
class FlyingCar : public Vehicle, public Airplane 
{

};

int main() {
    FlyingCar fc;
    fc.start();  // Ambiguity: which start() method to call?(compile time.) -> to resolve this we need virtual inheritance or using scope resolution-> see next solution
    return 0;
}