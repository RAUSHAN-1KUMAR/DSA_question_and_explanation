/*
find the last occurence of a character in a given string
*/

/*
Appraoch:- iterative appraoah
    1. search from left to right
    2. search from right to left
*/

#include<iostream>
using namespace std;

// left to right 
void lastOccLTR(string &s, char ch, int index, int &ans)
{
    // base case
    if(index >= s.size()){
        return;
    }

    // ek case solve kerte h
    if(s[index]==ch){
        ans=index;
    }

    // recursive call
    lastOccLTR(s,ch,index+1,ans);
}


// right to left 
void lastOccRTL(string &s, char ch, int index, int &ans)
{
    // base case
    if(index < 0){
        return;
    }

    // ek case solve kerte h
    if(s[index]==ch){
        ans=index;
        return;
    }

    // recursive call
    lastOccRTL(s,ch,index-1,ans);
}


int main()
{
    string s = "absdsedft";
    char ch = 'd';

    int ans=-1;

    lastOccLTR(s,ch,0,ans);
    cout << ans << endl;

    lastOccRTL(s,ch,s.size()-1,ans);
    cout << ans << endl;

    return 0;
}