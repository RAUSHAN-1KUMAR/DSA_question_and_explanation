/* GFG
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.
*/

/*
Appraoch:- DFS(head recursion)
    -- at every node we have two possible way to find the sum
        1. uss node ko include krlo
        2. uss node ko include mat kro

    -- to her ek node p do data hoga; use include kiya hua sum aur usse exclude kiya hua sum, to jab parent ko do possible answer nikalna hoga:

        1. uss node ko include kro:-> to node ka value + dono left aur right child node ka exclude wala sum
        
        2. uss node ko exclude kro:-> max(left.first, left.second) + max(right.first, right.second)
            -- ya to left child ka include ko bhi le sakte h ya phir exclude ko bhi -> max(left.first, left.second)
            -- aur phir right child ka bhi  ya to include ko bhi le sakye h ya phir exclude ko bhi -> max(right.first, right.second)

    -- yahi do her ek node ke liye krengen using DFS aur sum last se kerte ayengen
*/


#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree()
{
    cout << "Enter the value for Node: ";
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

// {include, exclude}
pair<int,int> getMaxSum_helper(Node* root)
{
    if(root==NULL) return {0,0};

    //RE(head recursion)
    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);

    // including the current node
    int a = root->data + left.second + right.second;

    // excluding the current node
    int b = max(left.first, left.second) + max(right.first, right.second);

    return {a,b};
}

int getMaxSum(Node* root)
{
    auto ans = getMaxSum_helper(root);

    return max(ans.first, ans.second);
}

int main()
{
    Node* root = createTree();

    return 0;
}