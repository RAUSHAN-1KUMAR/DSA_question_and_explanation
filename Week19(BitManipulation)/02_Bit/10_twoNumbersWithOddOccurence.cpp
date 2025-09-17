/* GFG

Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:
    Input: N = 8, Arr = {4, 2, 4, 5, 2, 3, 3, 1}
    Output: {5, 1} 
    Explanation: 5 and 1 have odd occurrences.

Example 2:
    Input: N = 8, Arr = {1 7 5 7 5 4 7 4}
    Output: {7, 1}
    Explanation: 7 and 1 have odd occurrences.
*/

/*
Approach:- two bucket logic
    -- if we go and take XOR of all elements of tha array then at last we will have a number with the XOR of req answer
        EX:- {4^2^4^5^2^3^3^1} = 4(5^1) = 0100
        So 0100 signify the hamming distance between our req answer x and y is only 1 because XOR will preserve those bit who where different

        So now What we will do, we will try to find the number whose 3rd bit is 1 -> put this number into a bucket and the number whose 3rd bit is 0 -> put that number into another bucket

        Why we took 3rd bit, becuase 3rd bit was the first one hamming distance

    How we are gonna find the Right most hamming bit of the obtained XOR of all elements: -> (num&(num-1))^num
        EX: num = 1010100
         -- num - 1 = 1010011(output1)
         -- output1 & num = 1010000(output2)
         -- output2 ^ num = 0000100(answer) 

*/

#include<bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    long long int XORR=0;
    for(int i=0 ; i<N ; i++) XORR = XORR^Arr[i];

    // taking the right most bit only
    long long int rightMost = (XORR&(XORR-1))^XORR;

    long long b1=0;
    long long b2=0;

    for(int i=0 ; i<N ; i++){
        if(rightMost&Arr[i]){
            b1 = b1^Arr[i];
        }
        else{
            b2 = b2^Arr[i];
        }
    }

    return {b1, b2};
}

int main()
{
    long long int Arr[] = {1,7,5,7,5,4,7,4};
    long long int N = 8;
    vector<long long int> ans = twoOddNum(Arr, N);

    for(auto num:ans)
        cout << num << " ";
    cout << endl;
    
    return 0;
}