
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class:-> blueprint
class Student
{
public://-> declaring publically
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
    s1.name = "Rohit";//-> public members accesseble outside class

    Student s2;
    return 0;
}

/*
Access modifier/specifier:- they define scope of acess of class members
    1. private: Private allows access only within the class
    2. protected: protected allows access within the class and its subclasses
    3. public: public allows access from anywhere

An access specifier controls who can access parts of a class in object-oriented programming. It helps in securing data and maintaining proper code structure.
*/


