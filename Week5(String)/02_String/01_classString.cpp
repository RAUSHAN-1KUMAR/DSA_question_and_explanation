
// class string is a built in class in cpp

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;// str is an object not a variable because it is declared using a class.
    str = "Hello";// it will not create a exact size array.
    cout << str << endl;

    // cin >> str; //-> for one word input
    getline(cin,str);//-> getline() function accept and read single and multiple line strings from the input stream. 
    cout << "Welcome Mr./Mrs. " << str << endl;
    return 0;
}

