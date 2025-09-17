
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

    void study(){
        cout << "studying" << endl;
    }

    void sleep(){
        cout << "sleeping" << endl;
    }

    void bunk(){
        cout << "bunking" << endl;
    }

    string getGfName(){
        return gf;
    }

    void setGfName(string s){
        gf = s;
    }

private:
    void gfChatting(){
        cout << "chatting" << endl;
    }
};


int main()
{
    Student s1;
    s1.name = "Rohit";
    s1.age = 22;
    s1.id = 1;
    s1.nos = 5;
    s1.present = false;

    // accessing private memeber by function call
    s1.setGfName("chutki");
    cout << s1.getGfName() << endl;
    
    return 0;
}




