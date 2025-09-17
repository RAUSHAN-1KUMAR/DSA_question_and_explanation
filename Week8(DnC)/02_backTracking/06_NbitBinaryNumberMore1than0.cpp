/* GFG

Given a positive integer n, print all n-bit binary numbers having more 1’s than 0’s for any prefix of the number.

Examples: 
Input : n = 2
Output : 11 10

Input : n = 4
Output : 1111 1110 1101 1100 1011 1010
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printRec(string ans, int onesCount, int zeroCount, int n)
{
    if(ans.size()==n)
    {
        cout << ans << " ";
        return;
    }

    ans.push_back('1');
    printRec(ans, onesCount+1, zeroCount, n);
    ans.pop_back();

    // zero tabhi push kero jab, onesCount greater than zeroCount ho
    if(onesCount>zeroCount)
    {
        ans.push_back('0');
        printRec(ans, onesCount, zeroCount+1, n);
    }
}

void printNums(int n)
{
    string ans = "";
    int onesCount = 0;
    int zeroCount = 0;

    printRec(ans, onesCount, zeroCount, n);

}

int main()
{
    int n=4;

    printNums(n);

    return 0;
}

