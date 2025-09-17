
#include<iostream>
using namespace std;

class complex
{
private:
    int real;
    int img;

public:
    complex(int r = 0, int i = 0){
        real = r;
        img = i;
    }

    complex& operator=(complex &other)
    {
        cout << "assignment operator overloaded" << endl;
        real = other.real;
        img = other.img;
        return *this;
    }
};




int main()
{
    complex c1(10,5);

    complex c2, c3, c4;
    c2 = c3 = c4;

    return 0;
}



