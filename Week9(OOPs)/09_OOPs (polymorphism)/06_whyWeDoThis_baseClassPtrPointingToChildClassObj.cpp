/*
We do Base_Class_Pointer → Derived_Class_Object mainly for run-time polymorphism

1. The Main Purpose: Polymorphism
    -- We want one pointer (of base type) to refer to different derived objects and automatically call the correct function at runtime.

    -- But What about member variables?? -> If we access a variable through a base class pointer, we will always get the base class variable, even if the derived class has a variable with the same name because they are resolved at compile time. So if you want to call the member variable of derived class, you need to create a member function in derived class which returns the value of that member variable and then call that function using base class pointer.
*/



#include<bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual void draw(){
        cout << "Drawing Shape" << endl;
    }
};

class Circle:public Shape
{
public:
    void draw(){
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle:public Shape
{
public:
    void draw(){
        cout << "Drawing Rectangle" << endl;
    }
};


// generic code
void normalFunction(Shape *str){
    str->draw();// runtime decides which draw()
}

int main()
{
    Circle c;
    Rectangle r;

    normalFunction(&c);
    normalFunction(&r);

    return 0;
}

/*
So we can see that:
    - One function can handle multiple types.
    - Add new derived classes without changing existing logic.

So if we didn't use base pointers, we would need separate code for each derived class like:
    - drawCircle(c);
    - drawRectangle(r);
    - drawTriangle(t);
*/
