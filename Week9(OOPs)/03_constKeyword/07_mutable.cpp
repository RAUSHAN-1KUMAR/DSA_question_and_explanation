/*
Used for debugging purpose

Mutable keyword: it allows a data member of a class to be modified even inside a const member function
*/

#include<iostream>
#include<vector>
using namespace std;

class abc{
    mutable int x;// mutable x
    int *y;

public:
    abc(){
        x = 0;
        y = new int(0);
    }

    int getX() const
    { 
        x = 50;//-> no error because now x is mutable
        return x;
    }

    void setX(int _val)
    {
        x = _val;
    }

    int getY() const
    {
        return *y;
    }

    void setY(int _val)
    {
        *y = _val;
    }
};


int main()
{
    abc a;
    cout << a.getX() << endl;
    cout << a.getY() << endl;

    return 0;
}