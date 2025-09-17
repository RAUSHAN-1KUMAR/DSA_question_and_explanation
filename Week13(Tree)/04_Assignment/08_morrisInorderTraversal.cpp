/*
Morrise traversal:- InOrder traversal with O(n) time and O(1) space complexity 
    - we also say it as a threaded binary tree
*/


#include<iostream>
#include<vector>
using namespace std;

class TreeNode
{
public:
    int val; 
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


TreeNode* createTree(vector<int> treeNode,int &i)
{
    if(treeNode[i]==-1) return NULL;

    TreeNode* temp = new TreeNode(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
}

// recursive inorder traversal
void inOrderTraversalRecursive(TreeNode* root){
    // base case
    if(root == NULL) return;

    // solve one case
    inOrderTraversal(root->left); // -> LEFT

    cout << root->val << " "; // -> NODE

    inOrderTraversal(root->right); // -> RIGHT
}

// iterative inorder traversal(morris traversal)
vector<int> inOrderTraversal(TreeNode* root)
{
    vector<int> ans;
    TreeNode* curr = root;

    while (curr) 
    {
        // left node is NULL, then visit it or print it and curr ko right m bhej do
        if(curr->left == NULL){
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else // left node is not null
        {   
            // then sabse pehle check ker rhe ki kya left part traversed h ya nhi,
            TreeNode* pred = curr->left;
            while(pred->right != curr && pred->right) // ager left part traverse hoga to pred->right == curr hoga
            {
                pred = pred->right;
            }

            // if pred right is null, it means link nhi h it means left part has not traversed so establishing link from predecessor to curr and then curr ko left m bhej do
            if(pred->right == NULL) // if pred->right != curr then it will confirm NULL
            {
                pred->right = curr;
                curr = curr->left;
            }
            else // if pred->right != NULL then it will confirm curr and if it pred->right == curr then...
            {
                // if pred is not null it means link is present it means left part has traversed so visit it or print it and curr ko right m bhej do usse pehle link ko break kerdo
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }


        }
    }
    
    return ans;
}

int main()
{
    vector<int> treeNode = {1,2,5,8,-1,10,-1,-1,-1,6,11,-1,-1,12,-1,-1,4,7,-1,-1,-1};
    int i=0;
    TreeNode* root = createTree(treeNode,i);

    cout << "InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}


