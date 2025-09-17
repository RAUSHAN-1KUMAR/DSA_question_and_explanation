/*
To uppercase all character of array
*/

/*
ASCII code:
    Ex: if A = 65, a = 97,
    --> to convert a to A, we can do a-97+65. => (lowercase-97+65) or (lowercase-'a'-'A') for all lowercase to uppercase conversion

    --> to convert A to a, we can do A-65+97 => (uppercase-65+97) or (uppercase-'A'-'a') for all uppercase to lowercase conversion
*/

#include<iostream>
#include<string.h>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{   
    // first approch(lowercase-97+65)
    cout << "first approach: " << endl;

    char ch[20];
    cin.getline(ch,20);

    cout << ch << endl;

    int i=0;
    while(ch[i] != '\0')
    {
        if(ch[i]>='a' && ch[i]<='z') ch[i] = ch[i]-'a'+'A';
        // if(ch[i]>='a' && ch[i]<='z') ch[i] = ch[i]-97+65; //-> we can also do like this
        i++;
    }
    cout << ch << endl;


    //second approach(islower() and toupper(), isupper() and tolower())
    cout << "second approach: " << endl;

    char ch1[20];
    cin.getline(ch1,20);
    
    cout << ch1 << endl;

    int length = strlen(ch1);

    for(int i=0 ; i<length ; i++){
        if(islower(ch1[i])) ch1[i] = toupper(ch1[i]); // lower to upper
    }

    cout << ch1 << endl;

    for(int i=0 ; i<length ; i++){
        if(isupper(ch1[i])) ch1[i] = tolower(ch1[i]); // upper to lower
    }

    cout << ch1 << endl;
    

    return 0;
}