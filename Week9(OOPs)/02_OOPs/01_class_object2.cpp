
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class:-> blueprint
class Student
{
    int id;//-> 4 byte
    bool present;//-> why 4 byte:-> compiler padding of extra 3byte 
    // compiler prepare itself for highest byte, this ensures fast memory access and correct alignment

    void study(){//-> jab ye call hoga tab int a ke liye memory book hoga
        int a;
        cout << "studying" << endl;
    }

    void sleep(){
        cout << "sleeping" << endl;
    }

    void bunk(){
        cout << "bunking" << endl;
    }
};


int main()
{
    cout << sizeof(Student) << endl;
    return 0;
}