
// this will compare two string in dictionary order.(according to distionary or ASCII value)
/* If the first string is smaller than the second string -> it will return -ve(nagative value)
   If the first string is same as the second string -> it will return 0
   It the first string is greater than the second string -> it will return +ve(posetive value)
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[] = "Hello";

    char str2[] = "Hello";
    cout << strcmp(str1, str2) << endl;

    char str3[] = "hello";
    cout << strcmp(str3, str1) << endl; //-> lowercase alphabets has greater ASCII code as compare to uppercase alphabets
    cout << strcmp(str1, str3) << endl; 

    char str4[] = "minor";
    char str5[] = "elder";
    cout << strcmp(str4, str5) << endl;
    cout << strcmp(str5, str4) << endl;

    return 0;
}