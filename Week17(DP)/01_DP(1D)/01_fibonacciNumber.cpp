/* -> 509
DP:-
    1. Top-Down appoach:-
    2. Bottom-up approach:-

1. Top-down appraoch:- In this method, result of inputs are being stored in dp array, and later on if that input comes which has been already calculated then we are fetching the output of that same input from the dp array.
    Step1: create a dp array
    Step2: store results in dp array.
    Step3: if ans already exists in dp array, then return

2. Bottom-up approach boleto tabulation method: iss method m hame ye dhayan m rakhna h ki dp array actually kya batata h and initial value kya fill kerna h dp array m.
    Step1: create a dp array
    Step2: initialize the dp array using base case of top-down approach
    Step3: now fill the remaining dp array using for loop and inside that for loop -> recursive logic of top-down approach.
            i) copy paste the recursive logic
            ii) replace recursive calls with dp array
            iii) make sure dp array is using for loop variable 'i'

Note:- Time complexity in both the case is same but the space complexity in bottom-up approach is reduced.

3. Space optimization:- In case of space optimzation we are gonna reduce our dp array with single or two variable and 2d dp array with single or two 1d dp array
    i) create variable for 1d dp array or 1d dp array for 2d dp array, as required 
    ii) fill the dp array or variable using base case
    iii) use the same for loop code with entire for loop body of bottom-up approach and then replace the 2d dp array with 1d dp array or 1d dp array with variable taken.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Normal recursive appraoch
int fib(int n)
{
    if(n==0 || n==1) return n;

    int ans = fib(n-1)+fib(n-2);

    return ans;
}


// top-down approach(DP -> recursion + momoization)
int solveUsingMem(int n, vector<int> &dp)
{
    if(n==0 || n==1) return n;

    // just base case ke baad
    // Step3(final): if answer already exist then return the answer
    if(dp[n] != -1){
        return dp[n];
    }

    int ans=solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);

    // Step2: Store the results in dp array
    dp[n] = ans;

    return dp[n];
}

int fibo(int n)
{
    // Step1: create dp array
    vector<int> dp(n+1,-1);

    int ans = solveUsingMem(n, dp);

    return ans;
}


// bottom-down appraoch(DP->  tabulation method):-
// iss method m ham pehle dp array m known value fill kerte h and baki remaining filled value ke help se nikalengen
int solveUsingTabu(int n)
{
    // Step1: create dp array
    vector<int> dp(n+1, -1);

    // Step2: initialiaze the dp array using the base case of top-down approach
    dp[0]=0;
    if(n==0) return dp[0];

    dp[1]=1;

    // Step3: fill the remaining using recusive logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int i=2 ; i<=n ; i++)
    {
        int ans = dp[i-1] + dp[i-2];
        dp[i]=ans;
    }

    return dp[n];
}


// after tabulation we have space optimization
int solveUsingTabuSpaceOpt(int n)
{
    int prev=0;
    if(n==0) return prev;

    int curr=1;
    if(n==1) return curr;

    int ans;
    for(int i=2 ; i<=n ; i++)
    {
        ans = prev + curr;

        // now shift both value
        prev = curr;
        curr = ans;
    }

    return ans;
}


int main()
{

    return 0;
}