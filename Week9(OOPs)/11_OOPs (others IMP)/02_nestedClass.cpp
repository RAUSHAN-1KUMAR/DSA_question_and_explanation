/*
Nested class:
    -- Class inside a class is called nested class,

Some rules:
    1. Inner class can access the member of outer class if they are static. (it behaves like a normal class, just declared inside another class)
    2. Outer class can create the object of inner class within its own body outside the inner class.
*/

#include<bits/stdc++.h>
using namespace std;

class Student
{
private:
    int rollno;
    string name;

    class Address
    {
    private:
        int houseno;
        string street;
        string city;
        string state;
        string pincode;

    public:
        void setAddress(int h, string s, string c, string st, string p)
        {
            houseno = h;
            street = s;
            city = c;
            state = st;
            pincode = p;
        }

        void showAddress()
        {
            cout << houseno << " ";
            cout << street << " ";
            cout << city << " ";
            cout << state << " ";
            cout << pincode << endl;
        }
    };

    Address add;
    // we can see that we have three data members of student class -> rollno, name and add

public:
    void setRollno(int r){
        rollno = r;
    }

    void setName(string n){
        name = n;
    }

    void setAddress(int h, string s, string c, string st, string p){
        add.setAddress(h, s, c, st, p);
    }

    void showStudent()
    {
        cout << "Student Data" << endl;
        cout <<  rollno << " ";
        cout << name << " ";
        // we can't access the address class private members outside the address class
        add.showAddress();
        cout << endl;
    }
};

int main()
{
    Student s1;
    s1.setRollno(101);
    s1.setName("Aman");
    s1.setAddress(10, "MG Road", "Pune", "Maharashtra", "411001");
    s1.showStudent();

    // we can't create the object of inner class outside the outer class because it's private
    // Student::Address a1; // this will only work if Address class is public

    return 0;
}

