/*
Google all c++ operator which can be overloaded
    -- compile time polymorphism
*/

#include<iostream>
#include<vector>
using namespace std;

class Vector
{
    int x,y;

public:
    Vector(int x, int y):x(x), y(y) {};

    // operator overloading
    void operator+(const Vector& src)
    {
        this->x = this->x + src.x;
        this->y = this->y + src.y;
    }

    void operator-(const Vector& src)
    {
        this->x -= src.x;
        this->y -= src.y;
    }

    void operator++()
    {
        this->x++;
        this->y++;
    }

    void display()
    {
        cout << "x: " << x << " ";
        cout << "y: " << y << endl;
    }
};

int main()
{
    Vector v1(2,3);
    Vector v2(4,5);

    v1.display();

    // we want to add v1 and v2 using + operator i.e., v1+v2 and answer should be stored in v1;

    v1+v2;//-> v1.operator+(v2) i.e., v1 calls its function. So, this keyword will point to v1 object

    v1.display();

    ++v1;

    v1.display();

    return 0;
}