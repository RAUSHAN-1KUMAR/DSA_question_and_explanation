
/*
Time complexity:-
    1. worst case: O(n) -> to find a single character
    2. worst case: O(n*m) -> to find a substring(m length) in a string(n length)
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello how are you";

    string s3 = "programming";


    cout << s1.find("are") << endl;//-> used to find the index of given string or character inside a string.

    cout << s1.find("hellp") << endl;
    
    if(s1.find("hellp")==string::npos){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found" << endl;
    }
    cout << endl;


    cout << s3.find('g') << endl;//-> find from left
    cout << s3.rfind('g') << endl << endl;//-> find from right

    cout << s1.find_first_of('o') << endl;//-> used to find a character from left hand side of the string.
    cout << s1.find_last_of('o') << endl;//-> used to find a character from right hand side of the string.
    cout << s1.find_first_of('o',5) << endl; //-> digit indicate that i want to search my digit form index 5.
    cout << s1.find_first_of("le") << endl; //-> it will look for both the digit instead of searching string, it will print that index which matches any of the character in the given string. 

    return 0;
}