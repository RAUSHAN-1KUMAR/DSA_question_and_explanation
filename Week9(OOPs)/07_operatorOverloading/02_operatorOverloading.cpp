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
        - Stream Operators: <<, >> i.e., cout, cin
    5. we cannot overload operators for built-in types like int, float, etc.
    6. we can overload only for user-defined types like class, struct, enums.
*/

// lets first start with '+' Binary operator, without operator overloading i.e., normal procedural approach using member function
// with operator overloading -> see next solution

#include<bits/stdc++.h>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    // If all your constructor parameters can have default values, one constructor with default arguments can replace both default and parameterized constructors.
    Complex(int r=0, int i=0)
    {
        this->real = r;
        this->img = i;
    }

    // using member function without operator overloading
    Complex add(Complex &c){
        Complex Temp;
        Temp.real = real + c.real;
        Temp.img = img + c.img;

        return Temp;
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

    c3 = c1.add(c2); // we wanted to do c3 = c1+c2 by operator overloading -> see next solution
    c1.print();
    c2.print();
    c3.print();

    return 0;
}

