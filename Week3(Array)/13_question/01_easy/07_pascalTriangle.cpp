/* -> 118

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

        1
       1 1
      1 2  1
     1 3  3  1
    1 4  6  4 1
   1 5 10 10 5 1


Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

*/

/*
Type of question that can be asked:-
    (i) given row and col (1th index), tell the element at that place
    (ii) print any nth row of parcals triangle
    (iii) print the entire pascal triangle
*/


/*
formula to find at a particular place:- 
    ans = ans*(row-col)/col ; row = [1,N] and col = [1,row], ans -> first it is 1 then it will be modified 
*/

#include<iostream>
#include<vector>
using namespace std;


// type (i)
int element(int r, int c)
{
    // we will use combination formula to find the element at rth and cth position-> (r-1)C(c-1)
    // but how to handle factorial of a number-> we will derive formula for that
    // so we will just write the code to find (r-1)C(c-1).
    int res = 1;
    for(int i=0 ; i<(c-1) ; i++)
    {
        res = res*((r-1)-i);
        res = res/(i+1);
    }

    return res;
}


// type (ii)
void entireRow(int r)
{
    int ans = 1;
    for(int c=1 ; c<=r ; c++)
    {
        cout << ans << " ";
        ans = ans*(r-c)/c;
    }
    cout << endl;
}

// type(iii)
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for(int row=1 ; row<=numRows ; row++)
    {
        vector<int> eachVec;
        int c=1;
        for(int col=1 ; col<=row ; col++)
        {
            eachVec.push_back(c);
            c = c*(row-col)/col;
        }
        ans.push_back(eachVec);
    }

    return ans;
}


int main()
{
    int numRows = 6;

    // type(i)
    cout << element(5,2) << endl;

    // type(ii)
    entireRow(6);

    // type (iii)
    vector<vector<int>> ans = generate(numRows);

    for(vector<int> num:ans)
    {
        for(int eachNum:num)
        {
            cout << eachNum << " ";
        }
        cout << endl;
    }

    return 0;
}