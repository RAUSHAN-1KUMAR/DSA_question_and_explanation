/*
convert lowercase char to uppercase in a given string

Note:- islower and toupper function of cctype header file
*/

#include<iostream>
#include<cctype>
using namespace std;

void lowerToUpper(string &s, int i)
{
    // base case;
    if(i>=s.size()) return;

    // solve one case
    if(islower(s[i])){
        s[i] = toupper(s[i]);
    }

    lowerToUpper(s,i+1);
}

int main()
{
    string s = "ROhIt";

    cout << s << endl;

    lowerToUpper(s,0);

    cout << s << endl;

    return 0;
}