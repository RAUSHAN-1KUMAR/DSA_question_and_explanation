/*
only data get copied, No, member functions are not copied — neither in shallow copy nor in deep copy.  
    - Member functions are shared across all instances.
    - They're part of the class's code section, not stored in each object.
    - When you create an object, only the data members (variables) occupy memory.
    - The function code is compiled once and reused by all objects.


// copy constructor add kerne ki need nhi h, default shallow copy kaam kerta h ache se. But copy constructor add kerne ki adat achi honi chahiye kyunki deep copy kerne ke liye
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
        cout << "default/non-parametrized constructor:" << endl;
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

    // copy constructor but why byReference-> because if we use pass by copy it means our copy constructor will be called for srcObj, but our copy constructor is incomplete,(C++ will try to use the copy constructor again... which requires copying... which again calls the copy constructor... and so on...) that's why we use pass by reference.
    // why const?-> we can do without const but it's a good practice to use const because to make the srcObj constant i.e., read only, we can't modify it.
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
    Student s1(1, 21, false, "chota bheem", 5,  "chutki");

    // calling copy constructor
    Student s2(s1); // copy constructor
    Student s3 = s1; // copy constructor

    cout << s1.name << endl;
    cout << s2.name << endl;

    // what if
    Student s4;
    cout << "printing s4 name " << s4.name << endl;
    s4 = s3;//-> will the copy constructor be called ?-> No because any constructor is called at the time of object creation. So, in this case non-parameterized constructor will be called at line number 98 and only assignment operator work at line number 100
    cout << "printing s4 name " << s4.name << endl;

    return 0;
} 