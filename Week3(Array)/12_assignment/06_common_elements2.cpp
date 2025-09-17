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
Approach:- without using another data structure, So how?
    -- first remove dublicate
    -- then use the same concept as before 
*/


#include<iostream>
#include<vector>
#include<set>
using namespace std;

void removingDublicates(vector<int> &remove)
{
    int dublicateCount = 0;
    for(int i = 0 ; i<remove.size()-1 ; i++)
    {
        if(remove[i]==remove[i+1]) dublicateCount++;
    }

    for(int j = 0 ; j<dublicateCount ; j++)
    {
        for(int i = 0 ; i<remove.size()-1 ; i++)
        {
            if(remove[i]==remove[i+1]) remove[i+1] = remove[i+1+1];
        }
    }

    for(int i = 0 ; i<dublicateCount ; i++){
        remove.pop_back();
    }
}

vector<int> commonElement(vector<int> A, vector<int> B, vector<int> C)
{
    removingDublicates(A);
    removingDublicates(B);
    removingDublicates(C);

    vector<int> answer;

    int i,j,k;
    i = j = k = 0;
    while(i<A.size() && j<B.size() && k<C.size()){
        if(A[i]==B[j] && B[j]==C[k]){
            answer.push_back(A[i]);
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
    return answer;
}


int main()
{

    vector<int> A = {3,3,4,4};
    vector<int> B = {3,3,4,4};
    vector<int> C = {3,3,4,4};
    
    vector<int> ans = commonElement(A,B,C);

    for(int i = 0 ; i<ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

