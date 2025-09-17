/* -> 652

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

*/

/*
Appraoch:-
Brute force
    -- ek function hoga jo two argument lega i.e, TreeNode* wo check krega ki given nodes ka tree identical h ya nhi
    -- to ham kya krengen ki her node p jaake baaki sab node se compare krengen ki kya khi kisi se identical h ya nhi -> O(n^2) time

Better
    -- using preorder traversal
    -- do tree ki preorder representation same h to ha identical h, to ham brute force m baar baar traverse ke rhe the her node ke liye but ham child wale preorder ka hi use kreke uske parent ka preorder banyengen ek hi iteration m -> O(n) time
*/


#include<iostream>
#include<vector>
#include<unordered_map>
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
    int data;
    cin >> data;

    if(data == -1) return NULL;

    TreeNode* root = new TreeNode(data);

    cout << "Enter left of " << data << endl;
    root->left = createTree();

    cout << "Enter right of " << data << endl;
    root->right = createTree();

    return root;
}

vector<TreeNode*> findDublicateSubtrees(TreeNode *root)
{

}

int main()
{

    return 0;
}
