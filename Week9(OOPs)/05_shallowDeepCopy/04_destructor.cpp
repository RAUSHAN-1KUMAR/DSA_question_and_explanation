/*
-- A distructor is another special function that runs automatically when an object is destroyed or goes out of scope. It's mainly used to free up resources like heap memory.

-- A distructor has the same name as the class but starts with a ~(tilde) and doesn't take any arguments.

-- if we don't write dtor, compiler will take the responsibility which is not safe in every case.
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

    Student(const Student &srcObj)
    {
        this->name = srcObj.name;
        this->age = srcObj.age;
        this->id = srcObj.id;
        this->gf = srcObj.gf;
        this->nos = srcObj.nos;
        this->present = srcObj.present;
        cout << "copy constructor:" << endl;
    }

    // destructor -> it will be called automatically when object's scope ends, why we need destructor?? -> if inside class we intialize data in heap-> see next code
    ~Student(){
        cout << "dtor called" << endl;
    }

private:
    void gfChatting(){
        cout << "chatting" << endl;
    }
};


int main()
{
    {
        Student s1(1, 21, false, "chota bheem", 5,  "chutki");
        cout << s1.name << endl;
    }

    Student s2;

    return 0;
} 