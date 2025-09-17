
/*
erase()-> erase is like clear i.e. used to clear a string

Function of erase():-
    -- Syntax:-
        1. str.erase():- to erase entire string.
        2. str.erase(digit1,digit2):- to erase total digit2 no. of characters  form index digit1.
        3. str.erase(str.begin()+digit):- to erase a particular character at index digit.
        4. str.erase(str.begin()+digit1, ch.begin()+digit2):- erase characters from digit1 to digit2 position, excluding digit2 position.

Time complexity:-
    1. worst case: O(n)-> to erase a single character
    2. worst case: O(n)-> to erase multi character
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    // erase()
    string s1 = "hello";

    cout << "Befor erase: " << endl;
    cout << s1.capacity() << endl;
    cout << s1.empty() << endl;//-> false
    cout << s1.size() << endl;

    s1.erase();

    cout << "After erase: " << endl;
    cout << s1.capacity() << endl;
    cout << s1.empty() << endl;//-> true
    cout << s1.size() << endl;


    //erase(digit1,digit2)
    string s3 ="programming";
    cout << s3.erase(2,3) << endl;


    //erase(ch.begin())
    string s5 ="programming";
    s5.erase(s5.begin()+2);
    cout << s5 << endl;


    //erase(ch.begin(), ch.begin())
    string s4 ="programming";
    s4.erase(s4.begin(), s4.begin()+5);
    cout << s4 << endl;


    //erase(ch.begin(), ch.end())
    s4.erase(s4.begin(), s4.end()-3);
    cout << s4 << endl;

    return 0;
}



