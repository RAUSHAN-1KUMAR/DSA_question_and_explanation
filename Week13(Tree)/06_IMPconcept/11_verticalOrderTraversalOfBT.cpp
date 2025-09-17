/* -> 987
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/

/*
Approach:- iterative and recursive
    -- logic, think of whole tree in n*m 2D matrix, and insert nodes into 2D map: map<int, map<int, multiset<int>>>
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};


// iterative solution
vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    vector<vector<int>> ans;
    queue<pair<TreeNode*, pair<int,int>>> q;//-> Node, {row,col}
    q.push({root, {0, 0}});

    // using multiset to store the answer in ordered way with repeating elements w.r.t their row
    map<int, map<int, multiset<int>>> mp; //-> col -> (row -> [x,y,z,..])

    while(!q.empty())
    {
        auto front = q.front(); q.pop();

        // Extracting values
        TreeNode* &node = front.first; auto coordinate = front.second;
        int &row = coordinate.first;
        int &col = coordinate.second;

        // entering values inside map
        mp[col][row].insert(node->val);

        if(node->left) q.push({node->left, {row+1, col-1}});
        if(node->right) q.push({node->right, {row+1, col+1}});
    }


    // store final answer into ans vector
    for(auto it: mp) //-> iterating on first map 
    {
        auto &colMap = it.second;//-> first map ke second map p gye
        vector<int> vLine;

        for(auto colMapIt:colMap) //-> iterating on second map
        {
            auto &mSet = colMapIt.second; //-> second map ke second p data stored h
            vLine.insert(vLine.end(), mSet.begin(), mSet.end());
        }
        ans.push_back(vLine);
    }

    return ans;
}


// recursive solution: just do what we did in iterative approach in recursive way
void helperMap1(TreeNode* root, map<int, map<int, multiset<int>>> &mp, int col, int row)
{
    //  base case
    if(root==NULL) return;

    mp[col][row].insert(root->val);

    helperMap1(root->left, mp, col-1, row+1);

    helperMap1(root->right, mp, col+1, row+1);
}

vector<vector<int>> verticalTraversal1(TreeNode* root)
{
    map<int, map<int, multiset<int>>> mp;

    helperMap1(root, mp, 0, 0);

    vector<vector<int>> ans;
    // store final answer into ans vector
    for(auto it: mp) //-> iterating on first map 
    {
        auto &colMap = it.second;//-> first map ke second map p gye
        vector<int> vLine;

        for(auto colMapIt:colMap) //-> iterating on second map
        {
            auto &mSet = colMapIt.second; //-> second map ke second p data stored h
            vLine.insert(vLine.end(), mSet.begin(), mSet.end());
        }
        ans.push_back(vLine);
    }
    
    return ans;
}

int main()
{


    return 0;
}


