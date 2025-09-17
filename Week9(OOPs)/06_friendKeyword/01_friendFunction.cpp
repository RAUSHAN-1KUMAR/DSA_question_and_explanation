/*
The friend keyword allows a function or another class to access private/protected members of a class.

A friend function is a function that is not a member of a class but is granted access to the class's private and protected members. This means that a friend function can access and modify the private and protected data of a class, even though it is not a member of that class

Key characteristics:
    -- Friendship is not mutual. If A is a friend of B, B is not automatically a friend of A.
    -- Friendship is not inherited.
    -- friend functions are not members of the class.
    -- Declaring a function/class as friend breaks encapsulation but is useful when necessary (like OPERATOR OVERLOADING). HOW-> we will see it in operator overloading section

Types of Friendships:-
    1. Friend Functions: Non-member functions that are given access to the private and protected members of the class.

    2. Friend Classes: Entire classes that are given access to the private and protected members of another class.

    3. Friend Member Functions: Specific member functions of another class that are given access to the private and protected members of a class.
*/

#include<iostream>
using namespace std;

class Test
{
    private:
        int a;
    
    protected:
        int b;

    public:
        int c;

    Test(int a, int b, int c) : a(a), b(b), c(c) {}

    friend void fun(const Test &t); //-> friend function
};

// if we don't use pass by reference in function, then copy constructor will be called
void fun(const Test &t)
{
    cout << t.a << endl;
    cout << t.b << endl;
    // a = 50; -> error because directly we cannot access, we have to create an object for it
}

int main()
{
    Test t(10, 20, 30);

    cout << t.c << endl;
    // cout << t.a << endl; // error we can't access private or protected member outside the class 

    fun(t);

    // t.fun(t); // no we can't, as we said, its not member function

    return 0;
}

