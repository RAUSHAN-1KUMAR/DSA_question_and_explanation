/*
Solving the ambiguity using scope resolution operator

The scope resolution operator :: is used to access something that is outside the current scope — like a global variable, a class member, or a namespace element.
*/

#include<iostream>
using namespace std;


class Engine
{
public:
    void start() 
    {
        cout << "Engine starting" << endl;
    }
};


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


class FlyingCar : public Vehicle, public Airplane 
{

};


int main()
{
    FlyingCar fc;

    // previously ambiguity is to selection between whose start function, Vehicle or Airplane

    // but now fc, tu Vehicle ka start function use kerle
    fc.Vehicle::start();

    // now fc, tu Airplane ka start function use kerle
    fc.Airplane::start();

    // Error -> Which Engine do you mean? Vehicle::Engine or Airplane::Engine?
    fc.Engine::start();

    return 0;
}
