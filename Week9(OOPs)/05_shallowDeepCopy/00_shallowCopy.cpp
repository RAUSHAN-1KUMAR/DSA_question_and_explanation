/*
A shallow copy is a copy of an object where:
    - All member(private, public, etc) variables are copied as-it is
    - static members and pointers are shared not copied 
    - pointers (only the address is copied, not the data it points to)

When is this a problem?
If your class contains dynamically allocated memory (e.g. int* data = new int;), a shallow copy will cause:
    1. Both objects to point to the same memory.
    2. Double deletion when both destructors run → 💥 crash or undefined behavior.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std; 

class Student
{
private:
    string gf;

public:
    int id;
    int age;
    string name;
    bool present;
    int nos;

    Student(){
        cout << "non-parametrized constructor:" << endl;
    }

    Student(int _id, int _age, bool _present, string _name, int _nos, string _gfname)
    {
        id = _id;
        age = _age;
        present = _present;
        name  = _name;
        nos = _nos;
        gf = _gfname;
        cout << "parametrized constructor:" << endl;
    }

    Student(int _id, int _age, bool _present, string _name, int _nos)
    {
        id = _id;
        age = _age;
        present = _present;
        name  = _name;
        nos = _nos;
        cout << "parametrized constructor w/o GF:" << endl;
    }

    ~Student(){
        cout << "dtor is called for: " << this->name << endl;
    }

private:
    void gfChatting(){
        cout << "chatting" << endl;
    }
};


int main()
{
    Student s1(1, 21, false, "chota bheem", 5,  "chutki");

    // shallow copy i.e., compiler copy constructor bna rha h but good practice is to form your own copy constructor which helps in case of deep copy constructor -> see next file
    Student s2 = s1; // shallow copy
    Student s3(s2); // shallow copy

    cout << s1.name << endl;
    s1.name = "Rahul Kumar";
    cout << s1.name << endl;
    cout << s2.name << endl;
    cout << s3.name << endl;

    return 0;
} 