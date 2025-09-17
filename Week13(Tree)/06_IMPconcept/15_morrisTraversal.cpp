/*
Morrise traversal:- InOrder traversal with O(n) time and O(1) space complexity 
    - we also say it as a threaded binary tree
*/

/*
Logic:- For Inorder traversal
    1. let say ham koi perticular node p h: curr

    2. how can we check curr ka left subtree is visited so that we can print curr->val
        a) if curr->left == NULL: no need to check just print the curr and curr=curr->right

        b) if curr->left != NULL: as we know that, in morris traversal the right most node of left subtree will be connected to its parent(curr) if left subtree is visited 
            - to ham log yahi check krengen

    3. ager curr ke left subtree ka right most node:
        i) curr ko hi point ker rha hoga, it means left subtree is visited: print kerdo curr->val and then curr ko right m bhej do

        ii) null ko point ker rha hoga, it means left subtree is not visited: curr ko left m bhejne se pehle right most ko curr se connect kerdo taaki back to parent aa sakt without recursion
            - rightMost->right = curr;
            - curr = curr->left;
*/


#include<bits/stdc++.h>
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
    inOrderTraversalRecursive(root->left); // -> LEFT

    cout << root->val << " "; // -> NODE

    inOrderTraversalRecursive(root->right); // -> RIGHT
}


// iterative inorder traversal(morris traversal)
void inOrderTraversal(TreeNode* root)
{
    TreeNode* curr = root;

    while (curr) 
    {
        if(curr->left==NULL){ // left is NULL go right
            cout << curr->val << " ";
            curr = curr->right;
        }
        else{// left is not null, need to check traversed or need to be traverse

            TreeNode* prev = curr->left;
            while (prev->right!=curr && prev->right!=NULL){
                prev = prev->right; // going to rightmost of leftsubtree
            }

            if(prev->right==NULL){ //  if right most is NULL => not traversed
                prev->right = curr;
                curr = curr->left;
            }
            else{ // if right most is curr => traversed
                prev->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}


// iterative preorder traversal using morris travesal
void preorderTraversal(TreeNode* root)
{
    TreeNode* curr = root;

    while (curr) 
    {
        if(curr->left==NULL){
            cout << curr->val << " ";
            curr = curr->right;
        }
        else{

            TreeNode* prev = curr->left;
            while (prev->right!=curr && prev->right!=NULL){
                prev = prev->right;
            }

            if(prev->right==NULL){
                prev->right = curr;
                cout << curr->val << " "; // for preorder
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}


// iterative postorder traversal using morris traversal: we will reverse the postOrder call i.e, LRN to NRL then find the answer and the mainAnser will be reverse of answer obtained by NRL
void postorderTraversal(TreeNode* root)
{
    TreeNode* curr = root;
    vector<int> ans;

    while (curr) 
    {
        if(curr->right==NULL){
            ans.push_back(curr->val); // for NRL
            curr = curr->left;
        }
        else{

            TreeNode* prev = curr->right;
            while (prev->left!=curr && prev->left!=NULL){
                prev = prev->left;
            }

            if(prev->left==NULL){
                prev->left = curr;
                ans.push_back(curr->val); // for NRL
                curr = curr->right;
            }
            else{
                prev->left = NULL;
                curr = curr->left;
            }
        }
    }

    // reverse ans
    reverse(ans.begin(), ans.end());
    for(int num:ans)
        cout << num << " ";
    cout << endl;
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


