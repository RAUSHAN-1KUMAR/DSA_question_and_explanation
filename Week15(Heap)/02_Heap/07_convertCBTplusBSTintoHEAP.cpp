/*
Given a tree which is a complete binary tree and binary search tree as well, convert it into maxHEAP
*/

/*
Approach: post-order traversal or level order traversal
    -- it's already in CBT, we just have to rearranege the node
    -- we are given binary tree, we will find its inOrder traversal and then fill it again by following postOrder traversal.

Post-order traversal -> LRN


for Minheap conversion:-
    1. Inorder traversal(LNR)
    2. fill it using preorder(NLR) 
*/

#include<iostream>
#include<vector>
#include<queue>
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

void levelWisePrinting(Node* root)
{
    if(root==NULL) return;

    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    while(!qu.empty())
    {
        Node* first = qu.front(); qu.pop();

        if(first==NULL)
        {
            if(!qu.empty()) qu.push(NULL);
            cout << endl;
        }
        else{
            cout << first->data << " ";

            if(first->left!=NULL) qu.push(first->left);
            if(first->right!=NULL) qu.push(first->right);
        }

    }
}

void preOrderTraversal(Node* root)
{
    if(root==NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

Node* createTree(vector<int> treeNode,int &i)
{
    if(treeNode[i]==-1) return NULL;

    Node* temp = new Node(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
}

// solution starts from here
void InorderTraversal(Node* root, vector<int> &inorder)
{
    if(root==NULL) return;

    // LNR
    InorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    InorderTraversal(root->right, inorder);
}

void UsingPostOrder(Node* root, vector<int> &in, int &i)
{
    if(root==NULL) return;

    //LRN
    UsingPostOrder(root->left, in, i);
    UsingPostOrder(root->right, in, i);
    root->data = in[i++];
}

Node* convertBSTintoMaxHEAP(Node* root)
{
    // Step1: find inorder
    vector<int> inorder;
    InorderTraversal(root, inorder);

    // Step2: replace the node values with the inorder value, using the postOrder traversal
    int i=0;
    UsingPostOrder(root, inorder, i);

    return root;
}


int main()
{
    vector<int> treeNode = {100,50,40,20,-1,-1,-1,60,-1,-1,150,110,-1,-1,200,-1,-1};
    int i=0;
    Node* root = createTree(treeNode,i);

    levelWisePrinting(root);

    cout << endl;
    root = convertBSTintoMaxHEAP(root);

    levelWisePrinting(root);

    return 0;
}




