/* -> 103 
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/

/*
Appraoch:-
    -- zig zag print kerna h, means pehle Left to right then right to left then left to right then again right to left and so on, like this
    -- so ham kya krenge ki ek vector m root node push ker rhe h aur jab uss vector ko use kerna h tab ham uske top index se 0 tak ayengen aur uss waqt jo bhi traversal chal rha hoga let say right to left, tab ham uss vector jo element h uske pehle right and then left node push ker dengen and then phir last m uss vector ke pehle used data erase ker dengen
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    // answer vector
    vector<vector<int>> ans;

    if(root == NULL) return ans;


    // vector to store the node at level wise
    vector<TreeNode*> ofQ = {root}; 
    bool leftRight = true;

    while(ofQ.size())
    {
        vector<int> ansChild;

        if(leftRight)
        {
            int index = ofQ.size();

            for(int i = ofQ.size()-1 ; i>=0 ; i--)
            {
                ansChild.push_back(ofQ[i]->val);

                if(ofQ[i]->left != NULL) ofQ.push_back(ofQ[i]->left); 
                if(ofQ[i]->right != NULL) ofQ.push_back(ofQ[i]->right); 
            }

            leftRight = false;

            ofQ.erase(ofQ.begin(), ofQ.begin()+index);
        }
        else
        {
            int index = ofQ.size();

            for(int i=ofQ.size()-1 ; i>=0 ; i--)
            {
                ansChild.push_back(ofQ[i]->val);

                if(ofQ[i]->right != NULL) ofQ.push_back(ofQ[i]->right);
                if(ofQ[i]->left != NULL) ofQ.push_back(ofQ[i]->left);
            }

            leftRight = true;
            
            ofQ.erase(ofQ.begin(), ofQ.begin()+index);
        }

        if(ansChild.size()) ans.push_back(ansChild);
    }

    return ans;
}

int main()
{
    TreeNode* root = createTree();
    return 0;
}