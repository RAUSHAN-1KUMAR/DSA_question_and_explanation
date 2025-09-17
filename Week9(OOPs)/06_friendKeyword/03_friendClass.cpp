/*
A friend class is a class that is granted access to the private and protected members of another class.
*/

#include<iostream>
using namespace std;

class Your;//-> important to declare it before its call.

class My
{
    private:
        int a;
    
    protected:
        int b;

    public:
        int c;

    My(){
        this->a = 10;
        this->b = 20;
        this->c = 30;
    }

    friend Your;
};


class Your
{
    public:
        void fun(My &m)
        {
            cout << m.a << endl;
            cout << m.b << endl;
            cout << m.c << endl;
        }
};



int main()
{
    Your y;
    My m;

    // cout << m.a << endl; // error, accessing private member

    y.fun(m);
    
    return 0;
}