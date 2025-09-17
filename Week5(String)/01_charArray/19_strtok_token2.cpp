
// used to tokenize a string.
// strtol -> string to token

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s1[] = "x=10;y=20;z=35";

    //cout << strtok(s1,";") << endl; -> this will only print x=10

    char *token = strtok(s1, ";");

    while(token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, ";");//-> NULL is given so that it will work for same string s1
    }

    // If we use "=?" in place of ";" then it will only tokenize "=" because "?" is not present in string s1
    // If we use "?" in place of ";" then it will not tokenize anything, it will print whole string s1 as it is

    return 0;
}