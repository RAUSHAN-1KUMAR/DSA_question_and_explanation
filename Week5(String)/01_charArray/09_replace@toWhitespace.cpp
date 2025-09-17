/*
To replace @ character to whitespace
*/

#include<iostream>
#include<string.h>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{   
    // first approach
    cout << "first approach: " << endl;
    char ch[20];
    cin.getline(ch,20);

    cout << ch << endl;

    int i=0;
    while(ch[i] != '\0')
    {
        if(ch[i] == '@') ch[i] = ' ';
        i++;
    }

    cout << ch << endl;



    // second approach
    cout << "second approach: " << endl;

    char arr[20];
    cin.getline(arr,20);

    cout << arr << endl;

    char *found = find(arr, arr+strlen(arr), '@');//-> pointer is used to iterate through each element.
    if(found != '\0'){
        *found = ' ';
    }//-> but this will remove only one @ not all.

    cout << arr << endl;


    return 0;
}