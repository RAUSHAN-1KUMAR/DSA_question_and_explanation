
// One more example

#include<iostream>
using namespace std;


class Rectangle{
    public:
        void area(){
            cout << "Area of Rectangle." << endl;
        }
};


class Cuboid:public Rectangle{
    public:
        void volume(){
            cout << "Volume of Cuboid" << endl;
        }
};


int main()
{
    Rectangle *p = new Cuboid();

    p->area();
    // p->volume(); // -> error

    // Cuboid *q = new Rectangle(); // -> error

    return 0;
}

