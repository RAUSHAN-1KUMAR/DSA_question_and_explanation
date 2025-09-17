/*
Given three array sorted in increasing order. Find the elements that are common in all three arrays.

Note:- can you take care of the dublicates without using any additional Data Structure?

Example:-
    Input:  A = {1,5,10,20,40,80}
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
Approach:- intuition based problem
    -- Applying if else condition carefully and using 'set' STL. but given that we don't have to use another data structure.

So we need an another solution.
*/


#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> commonElement(vector<int> A, vector<int> B, vector<int> C)
{
    vector<int> answer; 
    set<int> st;

    int i,j,k;
    i = j = k = 0;
    while(i<A.size() && j<B.size() && k<C.size()){
        if(A[i]==B[j] && B[j]==C[k]){
            st.insert(A[i]);
            i++, j++, k++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<C[k]){
            j++;
        }
        else{
            k++;
        }
    }

    for(auto i:st){
        answer.push_back(i);
    }

    return answer;
}


int main()
{

    vector<int> A = {10,20,30,40,50};
    vector<int> B = {10,10,40,50};
    vector<int> C = {10,10,20,30,50};
    
    vector<int> ans = commonElement(A,B,C);

    for(int i = 0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }

    return 0;
}

