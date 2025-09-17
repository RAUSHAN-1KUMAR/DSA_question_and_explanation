
#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Student1{
    char c;//-> 8byte
    double b;//-> 8byte
    double a;//-> 8byte
};

class Student2{
    double b;//-> 8byte
    char c;//-> 8byte
    double a;//-> 8byte
};

class Student3{
    double b;//-> 8byte
    double a;//-> 8byte
    char c;//-> 8byte
};


int main()
{
    cout << sizeof(Student1) << endl;
    cout << sizeof(Student2) << endl;
    cout << sizeof(Student3) << endl;
    return 0;
}