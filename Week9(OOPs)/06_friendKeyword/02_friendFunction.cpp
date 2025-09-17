
// Sum Using Friend function

#include<bits/stdc++.h>
using namespace std;

class B; // need to declare forward, as class A using it

class A
{
private:
    int x;

public:
    A(int val) : x(val) {}

    friend int funSum(A &a, B &b);
};


class B
{
private:
    int y;

public:
    B(int val) : y(val) {}

    friend int funSum(A &a, B &b);
};


int funSum(A &a, B &b)
{
    return a.x + b.y;
}

int main()
{
    A A1(10);
    B B1(1);

    cout << funSum(A1, B1) << endl;

    return 0;
}