/*
To find the length of character array
*/

#include<iostream>
#include<string.h>
using namespace std;

int main()
{   
    char ch[50];
    cin >> ch;

    // first approach
    int n = sizeof(ch)/sizeof(char);
    cout << n << endl;//-> output 50, wrong output


    // second approach
    int count = 0;
    for(auto i:ch){
        if(i=='\0') break;
        count++;
    }
    cout << count << endl;
    

    // third approach
    cout << strlen(ch) << endl;//-> length will be given by excluding null character


    return 0;
}


