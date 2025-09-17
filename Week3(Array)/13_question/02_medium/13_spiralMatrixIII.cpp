/* -> 885
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
{
    vector<vector<int>> ans;

    int colJump = 1;
    int rowJump = 1;

    vector<int> ansChild = {rStart, cStart};
    ans.push_back(ansChild);

    while(true)
    {
        int rotate = 0;

        // right
        int right = cStart+1;
        cStart += colJump;
        if(rStart<rows && rStart>=0)
        {
            while(right <= cStart)
            {
                if(right< cols && right >= 0)
                {
                    vector<int> ansChild = {rStart, right};
                    ans.push_back(ansChild);
                }
                right++;
            }
        }
        else{
            rotate++;
        }
        colJump++;

        // down
        int down = rStart+1;
        rStart += rowJump;
        if(cStart<cols && cStart>=0)
        {
            while (down <= rStart)
            {
                if(down < rows && down >= 0)
                {
                    vector<int> ansChild = {down, cStart};
                    ans.push_back(ansChild);
                }
                down++;
            }
        }
        else{
            rotate++;
        }
        rowJump++;

        // left
        int left = cStart-1;
        cStart -= colJump;
        if(rStart < rows && rStart>=0)
        {
            while (left >= cStart)
            {
                if(left>=0 && left<cols)
                {
                    vector<int> ansChild = {rStart, left};
                    ans.push_back(ansChild);
                }
                left--;
            }
        }
        else{
            rotate++;
        }
        colJump++;

        // up
        int up = rStart-1;
        rStart -= rowJump;
        if(cStart < cols && cStart >= 0)
        {
            while (up >= rStart)
            {
                if(up>=0 && up<rows)
                {
                    vector<int> ansChild = {up, cStart};
                    ans.push_back(ansChild);
                }
                up--;
            }
        }
        else{
            rotate++;
        }
        rowJump++;


        if(rotate == 4) break;
    }

    return ans;
}

int main()
{
    int rows = 1;
    int cols = 4;
    int rStart = 0;
    int cStart = 0;

    vector<vector<int>> ans = spiralMatrixIII(rows, cols, rStart, cStart);

    for(auto vec:ans)
    {
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}