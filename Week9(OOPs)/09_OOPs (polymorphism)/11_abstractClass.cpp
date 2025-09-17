/*
Abstract Class:
    - A class that contains at least one pure virtual function becomes an abstract class (and cannot be instantiated i.e., we cannot create objects of an abstract class but we can create pointer to achieve polymorphism).
    - Derived classes must override all pure virtual functions, otherwise they too become abstract.
*/

#include<iostream>
using namespace std;

// Abstract class -> classes having pure virtual function
class Car{
    public:
        virtual void start() = 0; //-> pure virtual function, means must be overritten inside its child class
};

class Innova:public Car{
    public:
        void start(){
            cout << "Innova Started" << endl;
        }
};

class Swift:public Car{
    public:
        void start(){
            cout << "Swift Started" << endl;
        }
};


int main()
{
    // Car c; -> we can't declare object of abstract class

    Car *p = new Innova();
    p->start();

    p = new Swift();
    p->start();

    return 0;
}
