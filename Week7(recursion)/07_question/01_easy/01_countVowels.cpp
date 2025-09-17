
/*
We have to count the numbers of vowels in given string
*/

#include<iostream>
using namespace std;

bool checkVowels(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }

    return false;
}

int countVowels(string &s, int i)
{
    // base case
    if(i>=s.size()) return 0;

    //solve one case
    if(checkVowels(s[i])){
        return 1 + countVowels(s,i+1);
    }
    
    return countVowels(s,i+1);
}

int main()
{
    string s = "rhoojkl";

    cout << countVowels(s,0) << endl;

    return 0;
}