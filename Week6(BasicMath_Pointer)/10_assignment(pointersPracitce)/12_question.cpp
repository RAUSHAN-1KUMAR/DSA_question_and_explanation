
/*
Guess the output
*/

#include<iostream>
using namespace std;

int main()
{
    // first question
    cout << "first question: " << endl;
    char st[] = "ABCD";
    for(int i=0 ; st[i]!='\0'; i++){
        cout << st[i] << *(st)+i << *(i+st) << i[st] << endl;
    }

    // second question
    cout << "second question: " << endl;
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1+3;
    cout << *ptr2 << " ";
    cout << ptr2-ptr1;
    
    return 0;
}