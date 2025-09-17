
#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Student{
    int id;
    string name;//-> string bhi ek class h to string ke bhi apne properties and method h, So it takes 24 byte
};

int main()
{
    cout << sizeof(Student) << endl; // 28 byte
    return 0;
}