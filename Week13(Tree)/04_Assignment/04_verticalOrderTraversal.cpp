/* -> 987
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/

/*
Appraoch:- using queue(levelwise traversal) + map of map<int, multiset>>
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
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

TreeNode* createTree()
{
    int val;
    cin >> val;

    if(val == -1) return NULL;

    TreeNode* root = new TreeNode(val);

    cout << "Enter left of " << val << endl;
    root->left = createTree();

    cout << "Enter right of " << val << endl;
    root->right = createTree();

    return root;
}


vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    vector<vector<int>> ans;
    queue<pair<TreeNode*, pair<int,int>>> q;//-> Node, {row,col}
    q.push({root, {0, 0}});

    // using multiset to store the answer in ordered way with repeating elements w.r.t their row
    map<int, map<int, multiset<int>>> mp; //-> col -> (row -> [x,y,z,..])

    while(!q.empty())
    {
        auto front = q.front();
        q.pop();

        // Extracting values
        TreeNode* &node = front.first;
        auto coordinate = front.second;
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

int main()
{
    TreeNode* root = createTree();
    return 0;
}