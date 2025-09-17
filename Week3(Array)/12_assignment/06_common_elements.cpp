/*
Given three array sorted in increasing order. Find the elements that are common in all three arrays.

Note:- can you take care of the dublicates without using any additional Data Structure?

Example:-
    Inpute: A = {1,5,10,20,40,80}
            B = {6,7,20,80,100}
            C = {3,4,12,20,30,70,80,120}
    Output: 20 80 
    Explanation: 20 and 80 are the only common elements in A, B and C.

    Input: A = {3,3,3,3}
           B = {3,3,3,3}
           C = {3,3,3,3}
    Output: 3
*/


/*
Approach:- Brute force
    -- Doing Linear Search in each array for each element in array A.(But it will not be applicable for example 2)
*/


#include<iostream>
#include<vector>
#include<map>
#include<limits>
using namespace std;

void commonElement(vector<int> A, vector<int> B, vector<int> C)
{
    for(int i = 0 ; i<A.size() ; i++){
        for(int j = 0 ; j<B.size() ; j++){
            for(int k = 0 ; k<C.size() ; k++){
                    if(A[i]==B[j] && B[j]==C[k]) cout << A[i] << " ";
            }
        }
    }
}


int main()
{
    vector<int> A = {1,5,10,20,40,80};
    vector<int> B = {6,7,20,80,100};
    vector<int> C = {3,4,10,20,30,70,80,120};
    
    commonElement(A,B,C);

    return 0;
}
