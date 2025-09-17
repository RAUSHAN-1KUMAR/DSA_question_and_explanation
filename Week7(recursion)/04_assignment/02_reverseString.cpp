
#include<iostream>
using namespace std;

void reverseString(string &s, int start, int end)
{
    //base case
    if(start>=end){
        return;
    }

    // ek case solve kro
    swap(s[start],s[end]);

 
    // recursive call
    reverseString(s, start+1, end-1);
} 


int main()
{
    string s ="absjgt";
    reverseString(s,0,s.size()-1);
    cout << s << endl;
    return 0;
}