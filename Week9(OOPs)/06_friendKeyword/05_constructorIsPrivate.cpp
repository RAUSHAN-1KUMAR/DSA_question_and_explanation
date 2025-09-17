/*
Friend class required in case you want to access the private member outside of the class
*/

#include<iostream>
using namespace std;

class Box
{
private:
    int width;
    Box(int w):width(w){}//-> constructor is under private section

public:
    Box(){
        width = 0;
    }

    int getWidth() const
    {
        return width;
    }

    void setWidth(int _val)
    {
        width = _val;
    }

    friend class Boxfactory; // friend class
};


class Boxfactory
{
private:
    int count;

public:
    Box getABox(int w)
    {
        count++;
        
        return Box(w); // constructor is called, but the question is that the Box() is a constructor and as we studied a constructor don't have any return type but here we have a return type Box, -> we are calling constructor but we are creating a object and then returning that object
    }
};


int main()
{
    Boxfactory bfact;

    // Box b(5); // Error, constructor is private
    Box b = bfact.getABox(5); // here we are assinging object b to a object return by getABox function, hence default copy constructor is in action

    cout << b.getWidth() << endl;
    
    return 0;
}


