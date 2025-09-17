
// converting a string into a number.
// strtol -> string to long integer

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char str1[] = "235";
    long int x = strtol(str1,NULL,10);//-> 10 is for mentioning decimal number system that is 235 is a decimal number if it is octal then 8.

    cout << x << endl;
    return 0;
}