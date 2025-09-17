/* -> 653

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

*/

/*
Appraoch:- pre-requisite -> BST Iterator question
*/

#include<iostream>
#include<queue>
#include<stack>
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

TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if(root == NULL)
    {
        TreeNode* first = new TreeNode(val);
        return first;
    }

    if(val > root->val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

void createBST(TreeNode* &root, vector<int> &vec)
{
    for(int eachData:vec)
    {
        root = insertIntoBST(root, eachData);
    }
}


// solution from here
class BSTIterator 
{
    stack<TreeNode*> st;
    bool reverse = true; // true -> before, false -> next

    void pushAll(TreeNode* root)
    {
        while(root){
            st.push(root);
            if(reverse==true){
                root = root->right;
            }else{
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() 
    {
        TreeNode* topNode = st.top();st.pop();

        if(reverse==true)
        {
            pushAll(topNode->left);
        }
        else
        {
            pushAll(topNode->right);
        }

        return topNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};


bool findTarget(TreeNode* root, int k)
{
    if(root==NULL) return false;

    BSTIterator l(root, false); // next
    BSTIterator r(root, true); // before

    int i=l.next();
    int j=r.next();
    while(i<j)
    {
        if(i+j == k) return true;
        else if(i+j < k) i = l.next();
        else j = r.next();
    }

    return false;
}

int main()
{
    // BST
    vector<int> vec = {100,50,30,70,200,120,300};
    TreeNode* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    levelOrderTraversal(root);

    return 0;
}