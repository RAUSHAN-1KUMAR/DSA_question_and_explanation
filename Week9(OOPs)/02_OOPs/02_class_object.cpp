
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class:-> blueprint
class Student{
    int id;
    int age;
    string name;
    int nos;

    void study(){
        cout << "studying" << endl;
    }

    void sleep(){
        cout << "sleeping" << endl;
    }

    void bunk(){
        cout << "bunking" << endl;
    }
};


int main()
{
    // objects:- instance of a class
    Student s1;
    s1.name = "Rohit";//-> error because by default the data inside class are held privately

    Student s2;
    return 0;
}