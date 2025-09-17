/*
Const method or func -> can't ever change any of the member variable
*/

#include<iostream>
#include<vector>
using namespace std;

class abc{
    int x;
    int *y;
    int z;

public:
    abc(){
        x = 0;
        y = new int(0);
        z = 0;
    }

    abc(int _x, int _y, int _z){
        x = _x;
        y = new int(_y);
        z = _z;
    }

    int getX() const
    { 
        return x;
    }

    int getY() const
    {
        return *y;
    }

    int getZ()
    {
        return z;
    }
};

// argument is const object so 'a' will demand for const member functions only
void printABC(const abc &a) // const -> makes 'a' read only
{
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl; //-> error, because getter function of z is not const
}


int main()
{
    abc a(1,2,3);

    printABC(a);

    return 0;
}


