
// Constructor Overloading means defining multiple constructors in the same class with different parameter lists. Based on the arguments passed when creating an object, the appropriate constructor gets invoked.

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
    Student s1;


    Student s2(1, 21, false, "chota bheem", 5,  "chutki");
    cout << s2.name << endl;


    Student s3(1, 21, true, "kaaliaa", 5);
    cout << s3.name << endl;

    return 0;
} 
