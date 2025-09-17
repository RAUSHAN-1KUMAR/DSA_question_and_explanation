/*
Const method/func -> can't ever change any of the member variable
*/

#include<iostream>
#include<vector>
using namespace std;

class abc{
    int x; // member variable
    int *y; // member variable

public:
    abc(){
        x = 0;
        y = new int(0);
    }

    //-> it can never modify any attributes
    int getX() const
    { 
        // x = 50; -> error
        return x;
    }

    // getter
    int getY() const
    {
        // y = &x; -> error
        return *y;
    }

    // setter
    void setX(int _val)
    {
        x = _val;
    }

    // setter
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





