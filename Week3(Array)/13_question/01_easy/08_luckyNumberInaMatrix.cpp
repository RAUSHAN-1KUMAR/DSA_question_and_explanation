/* -> 1380
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
*/

#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    unordered_map<int,int> mp;

    int row = matrix.size();
    int col = matrix[0].size();

    int num = INT_MAX;

    // finding min element in each row of given matrix and marking its occurence in map
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            if(matrix[i][j]<num) num = matrix[i][j];
        }
        mp[num]++;
        num = INT_MAX;
    }

    // now checking which max element of column is already present in map
    num = INT_MIN;
    vector<int> ans;
    for(int i=0 ; i<col ; i++)
    {
        for(int j=0 ; j<row ; j++)
        {
            if(matrix[j][i]>num)
            {
                num = matrix[j][i];
            }
        }
        if(mp.find(num) != mp.end()) ans.push_back(num);
        num = INT_MIN;
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {7,8},
        {1,2}
    };

    vector<int> ans = luckyNumbers(matrix);

    for(int num:ans)
    {
        cout << num << endl;
    }

    return 0;
}