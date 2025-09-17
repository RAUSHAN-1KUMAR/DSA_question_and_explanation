
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
    
    friend void operator<<(ostream &out, complex &c);
};

void operator<<(ostream &out, complex &c){
    out << c.real << "+i" << c.img << endl;
}


int main()
{
    complex c1(10,5);

    cout << c1;
    //OR
    operator<<(cout,c1);

    // cout << c1 << endl; -> for this it will throw an error because we are not returning to its own type called cout.

    return 0;
}



