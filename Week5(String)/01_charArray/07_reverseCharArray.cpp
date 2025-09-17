/*
To reverse character array
*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{   
    char ch[20];
    cin >> ch;

    //first appraoch(two pointer + swapping)
    int length = strlen(ch);
    int i=0;
    int j=length-1;

    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }

    cout << ch << endl;


    // second approach
    reverse(begin(ch), end(ch)-(20-length));//-> as our array size is 20 so if the input word is less than 20, so we have to justify the end properly.(end() section must at end element not just after end, like vector i.e., we want end() to point the element after end element)
    cout << ch << endl;

    reverse(begin(ch), begin(ch)+length);

    cout << ch << endl;


    // third approach
    strrev(ch);
    cout << ch << endl;


    return 0;
}