/*
In this section, we are going to see that whole calss is not friend but its member function is made to be friend of another class
*/


#include<bits/stdc++.h>
using namespace std;

class Calculator;

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
        cout << "Your numver is " << a << " + " << b << "i" << endl;
    }
};


class Calculator
{
public:
    int add(int a, int b){
        return (a+b);
    }

    int sumRealComplex(Complex &c1, Complex &c2){
        return (c1.a + c2.a); // still we are having error because above in class complex we told the compiler that the sumRealComplex which is member function of class Calculator is your friend but as it is a member function of class which is declared after the class Complex, so compiler has no idea what Calculator::sumRealComplex even is. So to resolve this issue, we need to rearrange the declaration order -> see next solution
    }
};



int main()
{


    return 0;
}

