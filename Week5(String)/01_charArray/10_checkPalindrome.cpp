/*
palindrome:- two pointer approach
    Ex:- NOON, RACECAR, BABBAB, TAPAT

    i.e., left to right = right to left
*/

#include<iostream>
#include<string.h>

using namespace std;

bool checkPalindrome(char ch[], int size)
{
    int s=0;
    int e=size-1;

    while(s<=e)
    {
        if(ch[s]==ch[e]){
            s++;
            e--;
        }
        else{
            return false;
        }
    }

    return true;
}

int main()
{
    char ch[30];
    cin >> ch;

    int length = strlen(ch);

    if(checkPalindrome(ch,length)) cout << "Plindrome" << endl;
    else cout << "Not palindrome" << endl;

    return 0;
}