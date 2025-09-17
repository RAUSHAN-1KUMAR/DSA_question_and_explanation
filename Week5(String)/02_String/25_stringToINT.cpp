/*
Hint:-
    -- to convert digit into string: to_string(digit)
    -- to convert string into digit: stoi(digitString)
*/

#include<iostream>
using namespace std;

int main()
{
    // digit to string
    int a=40;
    string b = to_string(a);

    cout << b << endl;


    //string to digit
    string str = "2568";
    int num =  stoi(str);

    cout << num << endl;

    return 0;
}