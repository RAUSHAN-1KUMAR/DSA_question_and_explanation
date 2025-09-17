
/*
Question no. 54 in leatCode:- Spriral Print a Matrix.(like jalebi)

Example:-
    Input:- 1 2 3
            4 5 6
            7 8 9
    Output:- 1 2 3 6 9 8 7 4 5

    Input:- 1 2 3
            4 5 6
            7 8 9
            10 11 12
    Output:- 1 2 3 6 9 12 11 10 7 4 5 8
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralPrintMatrix(vector<vector<int>> &matrix)
{
    vector<int> answer;
    int m = matrix.size();
    int n = matrix[0].size();
    int total_elements = m*n;

    int statingRow = 0;
    int endingCol = n-1;
    int endingRow = m-1;
    int startingCol = 0;

    int count = 0;
    while(count < total_elements)
    {
        //Printing starting row
        for(int i=startingCol; i<=endingCol && count<total_elements ; i++){
            answer.push_back(matrix[statingRow][i]);
            count++;
        }
        statingRow++;

        //printing ending column
        for(int i=statingRow ; i<=endingRow && count<total_elements ; i++){
            answer.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        //printing ending row
        for(int i=endingCol ; i>=startingCol && count<total_elements ; i--){
            answer.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        //printing starting column
        for(int i=endingRow ; i>=statingRow && count<total_elements ; i--){
            answer.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return answer;
}

int main()
{
    vector<vector<int>> v {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    vector<int> ans = spiralPrintMatrix(v);

    for(int i = 0 ; i<ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}