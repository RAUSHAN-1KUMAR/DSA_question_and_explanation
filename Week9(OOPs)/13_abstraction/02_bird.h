/* Abstract class
- class that contains at least one pure virtual function, and these classes cannot be instantiated i.e., its object cannot be formed.
- It has come from the idea of Abstraction.
*/


#if !defined(BIRD_H)
#define BIRD_H

#include<iostream>
using namespace std;

class Bird
{
public:
    // pure virtual function-> and classes that inherits abstract class has must to implement pure virtual function 
    virtual void eat() = 0;
    virtual void fly() = 0;
};

class sparrow:public Bird
{
public:
    void eat()
    {
        cout << "sparrow is eating" << endl;
    }

    void fly()
    {
        cout << "sparrow is flying" << endl;
    }
};

class eagle:public Bird
{
public:
    void eat()
    {
        cout << "eagle is eating" << endl;
    }

    void fly()
    {
        cout << "eagle is flying" << endl;
    }
};

#endif