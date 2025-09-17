/*
To resolve the previous issue, we need to rearrange declaration order wisely
*/


#include<bits/stdc++.h>
using namespace std;

class Complex;


class Calculator
{
public:
    int add(int a, int b){
        return (a+b);
    }

    int sumRealComplex(Complex &c1, Complex &c2);
    // {
    //     return (c1.a + c2.a); // it will give error, because at this point the compiler does not know that sumRealComplex is friend of class Complex, and it has to allow access to its private member
    // }
};



class Complex
{
private:
    int a, b;
    friend int Calculator::sumRealComplex(Complex &a, Complex &b); // a specific member of another class is friend not the whole class

public:
    void setNumber(int n1, int n2){
        a = n1;
        b = n2;
    }

    void printNumber(){
        cout << "Your nuber is " << a << " + " << b << "i" << endl;
    }
};


// now declare the sumRealComplex here 
int Calculator::sumRealComplex(Complex &c1, Complex &c2){
    return (c1.a + c2.a);
}

int main()
{
    Complex c1, c2;
    c1.setNumber(1, 2);
    c2.setNumber(3, 4);

    Calculator calc;
    int result = calc.sumRealComplex(c1, c2);
    cout << "Sum of real parts: " << result << endl;
    return 0;
}

