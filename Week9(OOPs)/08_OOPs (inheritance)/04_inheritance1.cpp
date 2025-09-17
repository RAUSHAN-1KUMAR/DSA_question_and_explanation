
// The parent class default/non-param constructor is always called first, before the child class constructor — no matter what. -> The base class constructor is called first to ensure that all parts of the object that the derived class depends on are already initialized.

#include<iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout << "Non-param of base class." << endl;
        }

        Base(int x){
            cout << "Param of base class: " << x << endl;
        }
};

class Derived:public Base{
    public:
        Derived(){
            cout <<"Non-param of derived class" << endl;
        }

        Derived(int y){
            cout << "Param of derived class: " << y << endl;
        }

        // if it is called then parameterized constructor of base class will be called, not default constuctor.
        Derived(int x, int y) : Base(x){
            cout << "Two input param of derived class: " << y << endl;
        }
};


int main(){

    Derived p(10);
    cout << endl;
    Derived d(5,10);

    return 0;
}

