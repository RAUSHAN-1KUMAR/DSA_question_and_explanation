
/*
capacity()-> capacity will be larger because class string will not create exact size array.(i.e. it will count the number of total blocks available in string )
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";

    cout << s1.capacity() << endl;
    cout << s2.capacity() << endl;

    return 0;
}