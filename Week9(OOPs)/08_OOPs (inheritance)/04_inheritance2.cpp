
// more examples of inheritance using scope resolution operator

#include<iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    
    public:
        Rectangle();
        Rectangle(int l, int b);
        Rectangle(Rectangle &r);
        int getLenght();
        int getBreadth();
        void setLength(int l);
        void setBreadth(int b);
        int area();
        int parimeter();
        bool isSquare();
        ~Rectangle();
};

class Cuboid:public Rectangle{
    private:
        int height;

    public:
        Cuboid(){
            height = 0;
        }

        Cuboid(int h){
            setHeight(h);
        }

        void setHeight(int h){
            if(h>=0) height = h;
            else height = 0;
        }

        int getHeight(){
            return height;
        }

        int volume(){
            return getLenght()*getBreadth()*height;
        }
};


int main(){

    Cuboid c(5);

    cout << c.volume() << endl; //-> output will be zero because since we have not given length and breadth so it will call the default constructor Rectangle() and assign the value of length and breadth as mentioned.

    c.setLength(10);
    c.setBreadth(7);

    cout << c.volume() << endl;

    // Cuboid c1(5,6); -> error  
    // Cuboid c2(5,6,7); -> error
    
    return 0;
}




Rectangle::Rectangle(){
    length = 0;
    breadth = 0;
}

Rectangle::Rectangle(int l, int b){
    setLength(l);
    setBreadth(b);
}

Rectangle::Rectangle(Rectangle &r){
    setLength(r.length);
    setBreadth(r.breadth);
}

void Rectangle::setLength(int l){
    if(l>=0) length = l;
    else length = 0;
}

void Rectangle::setBreadth(int b){
    if(b>=0) breadth = b;
    else breadth = 0;
}

int Rectangle::getLenght(){
    return length;
}

int Rectangle::getBreadth(){
    return breadth;
}

int Rectangle::area(){
    return length*breadth;
}

int Rectangle::parimeter(){
    return 2*length*breadth;
}

bool Rectangle::isSquare(){
    return length==breadth;
}

Rectangle::~Rectangle(){
    cout << "Created Object distroyed." << endl;
}