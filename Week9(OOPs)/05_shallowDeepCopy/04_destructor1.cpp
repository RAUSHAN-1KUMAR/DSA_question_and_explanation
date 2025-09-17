

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
    int *v;

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
        this->v = new int(*srcObj.v);//-> heap allocation
        cout << "copy constructor:" << endl;
    }

    // uss particular object ke liye last m destructor call ho rha to ab ham destructor ke ander heap memory deallocation ker sakte h
    ~Student(){
        cout << "dtor called" << endl;
        delete v;
    }

private:
    void gfChatting(){
        cout << "chatting" << endl;
    }
};


int main()
{
    Student s1(1, 21, false, "chota bheem", 5,  "chutki");
    cout << s1.name << endl;

    return 0;
} 