
/*
copy()-> used to copy string inside an array, digit indicates how many digits to be copied, null character will be added automatically by the compiler(not in mac).
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello Rohit, How are you";
    string s2 = "world";

    char s4[20] = "hello";

    cout << s4 << endl;
    s2.copy(s4,3);//-> s2 ke 3 characters copy kro s4 m
    cout << s4 << endl;

    s2.copy(s4,5); //-> s2 ke 5 characters copy kro s4 m
    cout << s4;


    return 0;
}



