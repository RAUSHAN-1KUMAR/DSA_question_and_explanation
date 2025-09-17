/* 1922 

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
    - For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.

Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
 

Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:
Input: n = 4
Output: 400

Example 3:
Input: n = 50
Output: 564908303
*/

/*
I have solved this question by taking 10 possibilites from 0-9 in each possible way but -> TLE
So, i have solve it using full recursion method. What if we can apply formula of PnC:-

Code -> next solution.
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPrime(int num)
{
    // 0 and 1 are not prime numbers
    if (num <= 1) return false; 

    // checking factor till root(n)
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0){
            return false;
        }
    }

    return true;
}


void solve(long long n, string &ans, long long &count)
{
    // base case
    if(ans.size() == n)
    {
        count++;
        return;
    }
    if(ans.size()>n){
        return;
    }


    for(int i=0 ; i<=9 ; i++)
    {
        int placingIndex = ans.size();
        // if the upcoming value at even position is even tabhi push kro
        if(placingIndex%2==0 && i%2==0){
            ans.push_back(i+'0');
            solve(n, ans, count);
            ans.pop_back();
        }
        else if(placingIndex%2!=0 && isPrime(i)){// if the upcoming value at odd position is prime tabhi push kro
            ans.push_back(i+'0');
            solve(n,ans,count);
            ans.pop_back();
        }
        else{
            continue;
        }
    }
}

int countGoodNumbers(long long n) 
{
    long long count = 0;
    string ans = "";

    solve(n, ans, count);

    return count;
}

int main()
{
    long long int n = 1;

    cout << countGoodNumbers(n) << endl;

    return 0;
}