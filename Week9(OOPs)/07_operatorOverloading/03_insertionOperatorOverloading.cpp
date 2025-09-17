
/*
In this we are going to overlaod the insertion operator (<< -> cout i.e, ostream) for complex number
    Ex: cout << c1 << endl;

In friend keyword class we discussed that: Declaring a function/class as friend breaks encapsulation but is useful when necessary (like OPERATOR OVERLOADING). HOW-> we will see it in operator overloading section
    -- so now in case of insertion operator overloading, we are bound to do it by using friend function as for "cout << c1" the right operand of << is a class and left operand of << is a ostream(cout) i.e., both are different and using operator overloading by member function means the left one of the object will call this function by passing the other object in its parameter but the thing is that in "cout << c1" we have only one object which is on right side
*/

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

    friend ostream& operator<<(ostream &out, Complex &c1);

    void print(){
        cout << real << "+i" << img << endl;
    }
};

// we can also do it by having return type as void -> see next solution
ostream& operator<<(ostream &out, Complex &c1){
    out << c1.real << "+i" << c1.img;
    return out;
}

int main()
{
    Complex c1(10, 5);
    
    cout << c1 << endl;
    // OR
    operator<<(cout, c1) << endl;
    return 0;
}

