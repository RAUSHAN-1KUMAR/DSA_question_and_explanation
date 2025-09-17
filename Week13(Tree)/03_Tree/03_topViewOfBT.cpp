/*
We are given a binary tree and we are asked to print its top view
*/

/*
Appraoch:- using deque + two variable(count , maxCount)
    -- i have two function topViewLeftPart to build the left part of top view in deque and function topViewRightPart to build the right part of top view in deque.

Can we do it just one function;-> levelWise Traversal, see next solution
*/


#include<iostream>
#include<deque>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree()
{
    int data;
    cin >> data;

    // base case
    if(data == -1) return NULL;

    // step 1: create Node
    Node* root = new Node(data);

    // step 2: create left subTree
    cout << "Left of Node: " << root->data << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

void topViewLeftPart(Node* root, deque<int> &dq, int Count, int &maxCount)
{
    // base case
    if(root == NULL) return;

    // solve one case
    if(Count > maxCount)
    {
        maxCount = Count;
        dq.push_front(root->data);
    }

    // RE
    topViewLeftPart(root->left, dq, Count+1, maxCount);
    topViewLeftPart(root->right, dq, Count-1, maxCount);
}

void topViewRightPart(Node* root, deque<int> &dq, int Count, int &maxCount)
{
    // base case
    if(root == NULL) return;

    // solve one case
    if(Count > maxCount)
    {
        maxCount = Count;
        dq.push_back(root->data);
    }

    // RE
    topViewRightPart(root->right, dq, Count+1, maxCount);
    topViewRightPart(root->left, dq, Count-1, maxCount);
}

int main()
{
    cout << "Enter the value for root node: ";
    Node* root = createTree();

    deque<int> dq;

    // calling topViewLeftPart function to build the left part of the top view from root node
    int Count = -1;
    int maxCount = -1;  
    topViewLeftPart(root, dq, Count+1, maxCount);

    // pop ker rhe, root node ke data ko hatane ke liye kyunki next call m wo dubara se dq m push hoga
    dq.pop_back();


    // calling topViewRightPart function to build the right part of the top view from root node
    Count = -1;
    maxCount = -1;
    topViewRightPart(root, dq, Count+1, maxCount);

    // print the data
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    


    return 0;
}