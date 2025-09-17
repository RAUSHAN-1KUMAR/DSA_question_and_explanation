/* -> 43

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
 

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string multiply(string num1, string num2)
{
    if(num1=="0" || num2=="0") return "0";

    // maximum length of the multiplication is lengthofNum1 + lengthofNum2.
    vector<int> num(num1.size()+num2.size());

    // do dry run the below code and observe it directness
    for(int i=num1.size()-1 ; i>=0 ; i--)
    {
        for(int j = num2.size()-1 ; j>=0 ; j--)
        {
            num[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            num[i+j] += num[i+j+1]/10;
            num[i+j+1] %= 10;
        }
    }

    //skipping leading 0's
    int i=0;
    while(i<num.size() && num[i]==0) i++;

    string ans = "";
    while(i<num.size()) ans.push_back(num[i++]+'0');

    return ans;
}


int main()
{
    string s1 = "123456789";
    string s2 = "987654321";

    string ans = multiply(s1,s2);

    cout << ans << endl;

    return 0;
}