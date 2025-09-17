
/*
Guess the output
*/

#include<iostream>
using namespace std;

int main()
{
    // first question
    cout << "first question: " << endl;
    char arr[20];
    int i;
    for(i = 0; i<10 ; i++){
        *(arr+i) = 65+i;
    }
    *(arr+i) = '\0';
    cout << arr << endl;

    // second question
    cout << "second question: " << endl;
    char *ptr;
    char Str[] = "abcdefg";
    ptr = Str;
    ptr += 5;
    cout << ptr << endl;
    
    return 0;
}