/*
About operator overloading:
    -- Operator overloading allows us to redefine or change the meaning of an operator (like +, -, *, etc.) for a user-defined data type (class).


Rules of Operator Overloading:
    1. You cannot create new operators (like **, @, etc.)
    2. Some operators cannot be overloaded:
        - Scope resolution operator –> ::
        - Member access operator –> .
        - Member pointer access operator –> .*
        - Ternary conditional operator –> ?:
        - sizeof operator
        - etc
    3. At least one operand must be a user-defined type (class or struct)
    4. You can overload:
        - Unary Operators: ++, --, -, !
        - Binary Operators: +, -, *, /, ==, etc.
        - Stream Operators: <<, >> i.e., cout , cin
*/

// with operator overloading:
// using friend function -> see next solution

// Operator overloading states that it is the ability of an operator to behave differently in different contexts or with different types of operands. We can see that the same operator symbol can have different behaviours depending on how it is overloaded, and we say it is compile-time polymorphism as the decision is made during compilation.

#include<bits/stdc++.h>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex(int r=0, int i=0)
    {
        this->real = r;
        this->img = i;
    }

    // using member function without operator overloading
    // Complex add(Complex &c){
    //     Complex Temp;
    //     Temp.real = real + c.real;
    //     Temp.img = img + c.img;

    //     return Temp;
    // }


    // using member function with operator overloading
    Complex operator+(Complex &c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    void print(){
        cout << real << "+i" << img << endl;
    }
};


int main()
{
    Complex c1(3, 7);
    Complex c2(5, 4);
    Complex c3; // no error, as we have a constructor with having all default arguments

    c3 = c1+c2;
    // c3 = c1.operator+(c2); // we can also call like this as well i.e., c1 is calling its operator function and taking c2 as parameter

    c1.print();
    c2.print();
    c3.print();

    return 0;
}