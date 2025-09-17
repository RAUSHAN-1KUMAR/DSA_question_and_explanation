/* GFG
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:
    Input:
        BST1:                   
               5
             /   \
            3     7
           / \   / \
          2   4 6   8

        BST2:
              10
            /    \
           6      15
          / \    /  \
         3   8  11   18
        x = 16
    Output: 3
    Explanation: The pairs are: (5, 11), (6, 10) and (8, 8)
*/

/*
Appraoch:-
    1. Brute force: BST1 se ek element liye -> 'a' and then BST2 m find (x-a)
        Time:- O(n^2)
    
    2. Better: BST1 se ek element liye -> 'a' and then BST2 m find (x-a) using binary search approach
        Time:- O(nlogn)
    
    3. Better: BST1 ka inorder(sorted hota h) kerke ek vector m store ker diye and BST2 ka reverse inorder(sorted in descending) kerke ek dusre vector m store ker diye, and then i=0 for BST1_vector and j=0 for BST2_vector leke solve ker lenge Time:- O(n) me
        but we have space of O(2n)

    4. Best: Same approach as appraoch3 but without using space, How-> using stack
        -- traverse kerte jaoun aur sath sath wo algorithm bhi lagate jaun
        How we can do inorder traversal using stack??-> talked in first class
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front(); q.pop();

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
            cout << front->data << " ";
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
    }
}

// Node->Left->Right
void preOrder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        Node* first = new Node(data);
        return first;
    }

    if(data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node* &root, vector<int> &vec)
{
    for(int eachData:vec)
    {
        root = insertIntoBST(root, eachData);
    }
}

// Best approach
int countPairs(Node* root1, Node* root2, int x)
{
    int ans = 0;
    stack<Node*> s1, s2;
    Node* a = root1;
    Node* b = root2;

    while(1)
    {
        // inorder
        while(a)
        {
            s1.push(a);
            a = a->left;
        }

        // reverse inorder
        while(b)
        {
            s2.push(b);
            b = b->right;
        }

        // base case
        if(s1.empty() || s2.empty()) break;

        Node* atop = s1.top();
        Node* btop = s2.top();
        int sum = atop->data + btop->data;

        if(sum==x)
        {
            ++ans;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if(sum<x)
        {
            s1.pop();
            a = atop->right;
        }
        else
        {
            s2.pop();
            b = btop->left;
        }
    }

    return ans;
}

int main()
{
    vector<int> vec = {5,3,7,2,4,6,8};
    Node* root1 = NULL;

    cout << "BST formation one: " << endl;
    createBST(root1, vec);

    vector<int> vec2 = {5,3,7,2,4,6,8};
    Node* root2 = NULL;

    cout << "BST formation two: " << endl;
    createBST(root2, vec2);

    return 0;
}