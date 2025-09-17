
/*
Iterators are used for accessing all the character of the string, it works like pointer i.e. we can read as well as we can modify it.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";
    string s3 = "programming";
    string s4 = "coding";

    string :: iterator str; //-> str is a iterator, which will access the character from the beginning
    for(str = s1.begin() ; str != s1.end() ; str++)//-> begin() is for beginning index of the string and end() is for ending index of the string. 
    {
        cout << *str;
        *str = *str-32;
    }
    cout << endl << s1 << endl << endl;


    string::reverse_iterator ptr;//-> ptr is a iterator, which will access the character from the ending
    for(ptr = s3.rbegin() ; ptr != s3.rend() ; ptr++)//-> rbegin() is for beginning index from reverse and rend() is for ending index from reverse. 
    {
        cout << *ptr;
    }
    return 0;
}