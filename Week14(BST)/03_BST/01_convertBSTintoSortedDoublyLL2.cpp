
// solved by me: DFS(LNR)

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

void printLinkedList(TreeNode* head)
{
    TreeNode* temp = head;

    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
}

void convertBSTtoDLL(TreeNode* root, TreeNode* &head, TreeNode* &temp, int &headMilGya)
{
    // the first most left node will be the head of the linked list
    if(headMilGya==0 && root->left == NULL)
    {
        head = root;
        headMilGya = 1;
    }

    // base case
    if(root == NULL) return;


    convertBSTtoDLL(root->left, head, temp, headMilGya);

    if(temp==NULL){
        temp=root;
    }
    else{
        temp->right = root;
        root->left = temp;
        temp = root;
    } 

    convertBSTtoDLL(root->right, head, temp, headMilGya);
}

int main()
{
    vector<int> vec = {100,50,200,5,60,150,300,1,16,110,3,10,18,2};
    TreeNode* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);
    levelOrderTraversal(root);

    TreeNode* head = NULL;
    TreeNode* temp = NULL;
    int headMilGya = 0;
    convertBSTtoDLL(root, head, temp, headMilGya);

    printLinkedList(head);

    return 0;
}