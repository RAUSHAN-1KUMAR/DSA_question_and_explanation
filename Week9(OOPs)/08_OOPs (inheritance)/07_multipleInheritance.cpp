/*
Multiple inheritance:-
    -- A derived class inherits from more than one base class. This can introduce complexity and ambiguity, especially if base classes have methods with the same name.
*/

#include<iostream>
using namespace std;

// one base class
class Camera
{
public:
    void click() 
    {
        cout << "Clicking a photo" << endl;
    }
};

// another base class
class Phone
{
public:
    void call() 
    {
        cout << "Making a call" << endl;
    }
};

// one child class 
class SmartPhone : public Camera, public Phone
{
    // empty but it has public members of its parent class
};


int main() 
{
    SmartPhone sp;
    sp.click(); 
    sp.call();  
    return 0;
}


