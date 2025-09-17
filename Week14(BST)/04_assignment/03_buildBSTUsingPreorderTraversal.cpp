/* 1008
Create BST using given preorder traversal of BST
*/

/*
Appraoch:- Formation of BST using given vector as we did in formation of BST in our first class

Note:- we can build BST using recursion or without recurstion, in this section we are gonna build BST without recursion

Time Complexity -> O(n^2)

Using recursion -> see next solution
*/

#include<iostream>
#include<queue>
#include<climits>
using  namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TreeNode* root)
{
    if(root == NULL) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrderTraversal(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* front = q.front(); q.pop();

        if(front == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << " ";
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
    }
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    TreeNode* root = NULL;
    bool firsDigit = true;

    for(auto eachData:preorder)
    {
        TreeNode* prev = NULL;
        TreeNode* next = root; 

        while(next!=NULL)
        {
            if(eachData > next->val)
            {
                prev = next;
                next = next->right;
            }
            else
            {
                prev = next;
                next = next->left;
            }
        }

        next = new TreeNode(eachData);
        if(firsDigit)
        {
            root = next;
            firsDigit = false;
        }
        else{
            if(eachData > prev->val) prev->right = next;
            else prev->left = next;
        }
    }

    return root;
}



int main()
{
    vector<int> preorder = {8,5,1,7,10,12};

    TreeNode* root = bstFromPreorder(preorder);

    preOrder(root);
    cout << endl;
    levelOrderTraversal(root);



    return 0;
}