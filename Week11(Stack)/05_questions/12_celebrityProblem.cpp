/* GFG

A celebrity is someone who is known to everyone but does not know anyone. So, if you are a celebrity at a party, you will be known to everyone, but you won’t know anyone there.

Given a sqaure N x N binary matrix. So, every cell can either have a value of 0 or 1. If matrix[i][j] = 1, this means that the ith person knows the jth person.

You have to tell whether a celebrity is present at the party or not. If it is present, we also have to tell which element (person) is the celebrity.

Note: The elements of the diagonal, i.e., when i = j, are always set to 0.


Example:
    input: N=3(person), {0,1,0}
                        {0,0,0}
                        {0,1,0}
    output: 1
    Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity
*/


/*
Approach:- 
    1. Brute force:- O(n*n)
        -- take two array -> knowMe(how many persons know me) and iknow(how many persons i know) and then 
        -- iterate through the whole matrix and each time i encounter 1(i,j) -> it means i know j(iKnow[i]++) and j is known by i(knowMe[j]++)
        -- at last iterate through the iknow array and then if i get zero at index(i) it means i don't know any one and then check for it in knowMe i.e., do i know everyOne(n-1) if yes then this is our required answer

    2. Better approach:- Using stack
        -- put all the persons/index into stack, and then pop out two at once from the stack and then compare, if someone know any one then don't push it again into stack

    3. Optimal apporach:- Using two pointer(O(1) space)
        -- one pointer will be at 0th row and other will be at last row, and then decrement that pointer who know other pointer
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// tow pointer
int celebrity(vector<vector<int>> &M, int n)
{
    int top=0;
    int down=n-1;

    while(top<down)//-> O(n)
    {
        if(M[top][down]==1)// if top know down
            top++;
        else if(M[down][top]==1) // if down know top
            down--;
        else //it they don't know anyone
        {
            top++;
            down--;
        }
    }

    if(top>down) return -1;

    // if celebrity is there then comfirm it
    for(int i=0 ; i<n; i++)//-> O(n)
    {
        if(i==top) continue;

        if(M[top][i]==0 && M[i][top]==1){}
        else return -1;
    }

    return top;
}

int main()
{
    vector<vector<int>> M = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int ans = celebrity(M, 3);

    cout << ans << endl;

    return 0;
}



