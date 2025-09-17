/* -> 415

Question already solved by iterative appraoch in Week5->06_question

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
*/


#include<iostream>
#include<algorithm>
using namespace std;

void addRE(string &num1, int p1, string &num2, int p2, int carry, string &ans)
{
    // base case
    if(p1<0 && p2<0){
        if(carry){
            ans.push_back(carry+'0');
        }
        return;
    }

    // ek case solve kro
    int n1 = (p1>=0 ? num1[p1]-'0' : 0);
    int n2 = (p2>=0 ? num2[p2]-'0' : 0);
    int csum = n1+n2+carry;
    int digit = csum%10;
    carry = csum/10;

    ans.push_back(digit+'0');


    // recursive call
    addRE(num1, p1-1, num2, p2-1, carry, ans);
}

string addStrings(string s1, string s2)
{
    string ans = "";
    
    addRE(s1, s1.size()-1, s2, s2.size()-1, 0, ans);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s1 = "456";
    string s2 = "77";

    string ans = addStrings(s1,s2);

    cout << ans << endl;
    return 0;
}