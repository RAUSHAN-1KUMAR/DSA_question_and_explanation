/*
Convert BST into Sorted Doubly Linked List

INPUT:-
        100
       /   \
      50   200
     /  \    \
    5   60   300

OUTPUT:-
    BST -> Sorted Doubly LL
    tree: left, right
    tree into LL: left->prev, right->next

    5 <-> 50 <-> 60 <-> 100 <-> 200 <-> 300
*/

/*
Appraoch:- DFS -> LNR(Left->Node->Right)
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

// converting BST into a sorted doubly linked list
void convertBSTtoDLL(TreeNode* root,TreeNode* &head, TreeNode* &temp, int &headMilGya)
{
    // base case
    if(root==NULL)
    {
        if(headMilGya==0)
        {
            headMilGya = 1;
        }
        return;
    }

    // LNR
    // Left
    convertBSTtoDLL(root->left, head, temp, headMilGya);

    // the only case of head
    if(headMilGya==1)
    {
        head = root;
        headMilGya = 10;
    }

    // Node(solve one case)
    root->left = temp;
    if(temp != NULL)
        temp->right = root;
    temp = root;

    // Right
    convertBSTtoDLL(root->right, head, temp, headMilGya);
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

int main()
{
    vector<int> vec = {50,20,60,70,55,65,10,80,25};
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