
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student1{
    // 8byte for both n and c i.e., 3byte padding for char c, padding done by combining both n and c because they are declared just after
    int n;
    char c;
    double b;//-> 8byte
    double a;//-> 8byte
};

class Student2{
    // n and c are not declared just after to combine within 8byte
    int n;//->4byte + 4byte padding
    double b;//-> 8byte
    char c;//-> 1byte + 7byte padding
    double a;//-> 8byte
};

class Student3{
    double b;//-> 8byte
    char c;//-> 4byte
    int n;//-> 1byte + 3byte padding
    double a;//-> 8byte
};

class Student4{
    double b;//-> 8byte
    char c;//-> 8byte
    double a;//-> 8byte
    int n;//-> 8byte
};

//Why variable answer by just changing the declaration:- due to compiler smart padding i.e., sabse bade datatype ke nearest multiple pe memory ko le aao


int main()
{
    cout << sizeof(Student1) << endl;
    cout << sizeof(Student2) << endl;
    cout << sizeof(Student3) << endl;
    cout << sizeof(Student4) << endl;
    return 0;
}