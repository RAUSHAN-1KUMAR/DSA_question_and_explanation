/*
a another way to write constructor
*/

/*
Uses:- if a const integer is reassigns in it, it will not throw error but if it reassigns it inside its body then it will throw error
*/

#include<iostream>
#include<vector>
using namespace std;

class abc{
    mutable int x;
    int *y;
    const int z=2; // can be reassigns in case of initialization list

public:
    // initialization list
    abc(int _x, int _y, int _z) : x(_x), y(new int(_y)), z(_z){
        cout << "Hellow, how are you?" << endl;
        *y = *y*10;
    }

    int getX() const
    { 
        return x;
    }

    int getY() const
    {
        return *y;
    }

    int getZ() const{
        return z;
    }
};


int main()
{
    abc a(1,2,3);
    cout << a.getX() << endl;
    cout << a.getY() << endl;
    cout << a.getZ() << endl;

    return 0;
}

