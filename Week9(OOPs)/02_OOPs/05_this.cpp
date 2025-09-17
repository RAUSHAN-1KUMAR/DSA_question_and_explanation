
/*
this is used to specify current object
    -- this pointer added by compiler to a class privately
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

    Student(int id, int age, bool present, string name, int nos, string gf)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name  = name;
        this->nos = nos;
        this->gf = gf;
        cout << "parametrized constructor:" << endl;
    }

    void study(){
        cout << "studying" << endl;
    }

    void sleep(){
        cout << "sleeping" << endl;
    }

    void bunk(){
        cout << "bunking" << endl;
    }

private:
    void gfChatting(){
        cout << "chatting" << endl;
    }
};


int main()
{

    Student s2(1, 21, false, "chota bheem", 5,  "chutki");
    cout << s2.name << endl;

    return 0;
}



