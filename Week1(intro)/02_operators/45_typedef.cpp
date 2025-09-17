
//used to give a new name to an existing datatype. so with the use of typedef we can increase the readeability of the program.

#include<iostream>
using namespace std;

typedef int marks;//-> in place of int we can use marks
typedef int rollno;//-> in place of int we can use rollno

int main(){
    marks m1 = 1, m2;//-> in place of int we our using our user defined datatype marks, which is a another name of integer datatype.
    m2 = 5;

    rollno m3;//-> it is just like int m3;
    cin >> m3;

    cout << m1 << " " << m2 << " " << m3 << endl;

    return 0;
}