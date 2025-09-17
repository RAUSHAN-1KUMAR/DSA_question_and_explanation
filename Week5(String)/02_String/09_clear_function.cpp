
/*
clear()-> used to clear string or to remove all characters to a string
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";

    cout << "Befor clear: " << endl;
    cout << s1.capacity() << endl;
    cout << s1.empty() << endl;//-> false
    cout << s1.size() << endl;

    s1.clear();//-> it will only clears the string not the memory blocks

    cout << "After clear: " << endl;
    cout << s1.capacity() << endl;
    cout << s1.empty() << endl;//-> true
    cout << s1.size() << endl;
    

    return 0;
}