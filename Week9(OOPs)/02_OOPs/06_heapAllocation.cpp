
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

    // heap allocation in case of integer
    int *a = new int(5);

    // similarly for object
    Student *s1 = new Student(1, 21, false, "chota bheem", 5,  "chutki");
    
    // below are the two ways to access the members of the class
    cout << s1->name << endl; // use arrow operator only in case of pointer to object
    cout << (*s1).name << endl;

    delete a;
    delete s1;

    return 0;
} 