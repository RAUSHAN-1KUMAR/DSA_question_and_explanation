
// used to tokenize a string.
// strtol -> string to token

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s1[] = "x=10;y=20;z=35";

    // cout << strtok(s1,"=;") << endl; //-> this will only print x

    char *token = strtok(s1, "=;");//-> pointer is used to iterrate through each element

    while(token != NULL)
    {
        cout << token;
        token = strtok(NULL, "=;");//-> NULL is given so that it will work for same string s1
    }

    return 0;
}