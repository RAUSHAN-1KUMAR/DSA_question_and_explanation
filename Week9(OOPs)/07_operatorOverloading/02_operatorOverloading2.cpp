/*
About operator overloading:
    -- Operator overloading allows us to redefine or change the meaning of an operator (like +, -, *, etc.) for a user-defined data type (class).


Rules of Operator Overloading
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

// using friend function -> as we know friend function is not a member function so we will pass both the objects as parameter

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

    // using member function without overloading
    // Complex add(Complex &c){
    //     Complex Temp;
    //     Temp.real = real + c.real;
    //     Temp.img = img + c.img;

    //     return Temp;
    // }


    // using member function with operator overloading
    // Complex operator+(Complex &c)
    // {
    //     Complex temp;
    //     temp.real = real + c.real;
    //     temp.img = img + c.img;
    //     return temp;
    // }

    // using friend function with operator overloading
    friend Complex operator+(Complex &c1, Complex &c2);

    void print(){
        cout << real << "+i" << img << endl;
    }
};


Complex operator+(Complex &c1, Complex &c2){
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}

int main()
{
    Complex c1(3, 7);
    Complex c2(5, 4);
    Complex c3; // no error, as we have a constructor with having all default arguments

    c3 = c1+c2;
    // c3 = operator+(c1, c2); // no any object is calling the function

    c1.print();
    c2.print();
    c3.print();

    return 0;
}

