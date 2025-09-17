/*
PreOrder traversal with O(1) space.

Same as previous appraoch, only little bit change
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

// it returns root node of the created tree
TreeNode* createTree()
{
    cout << "Enter the value for TreeNode: ";
    int val;
    cin >> val;

    // base case
    if(val == -1) return NULL;

    // step 1: create TreeNode
    TreeNode* root = new TreeNode(val);

    // step 2: create left subTree
    cout << "Left of TreeNode: " << root->val << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of TreeNode: " << root->val << endl;
    root->right = createTree();

    return root;
}


// iterative preOrder traversal(Node -> left -> right)
vector<int> preOrder(TreeNode* root)
{
    vector<int> ans;
    TreeNode* curr = root;

    while (curr) 
    {
        if(curr->left == NULL){
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {

            TreeNode* pred = curr->left;
            while(pred->right != curr && pred->right){
                pred = pred->right;
            }

            if(pred->right == NULL){
                ans.push_back(curr->val);// change1
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                // ans.push_back(curr->val); change2
                curr = curr->right;
            }
        }
    }
    
    return ans;
}

int main()
{
    TreeNode* root = createTree();

    return 0;
}


