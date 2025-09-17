
// this will compare two string in dictionary order.(according to distionary or ASCII value)
/* 
syntax:-> first_string.compare(second_string);
    - If the first string is smaller than the second string -> it will return -ve(nagative value)
    - If the first string is same as the second string -> it will return 0
    - It the first string is greater than the second string -> it will return +ve(posetive value)
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1 = "babbar";
    string str2 = "babbar";
    cout << str1.compare(str2) << endl;

    string str3 = "Babbar";
    cout << str1.compare(str3) << endl;
    cout << str3.compare(str1) << endl;


    return 0;
}