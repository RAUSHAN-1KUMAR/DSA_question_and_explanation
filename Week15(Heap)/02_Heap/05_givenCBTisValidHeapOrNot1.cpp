/*
Given CBT, check it that it is valid max heap or not
*/

/*
Approach: recursion
    -- my approach: the difference is that, he also has pssed the max element, but actually we don't have to
*/

#include<bits/stdc++.h>
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

void levelWisePrinting(Node* root);
void preOrderTraversal(Node* root);
Node* createTree(vector<int> treeNode,int &i);

// solution from here
bool isHeap(struct Node* tree) 
{
    // base case
    if(tree==NULL) return true;
    
    bool caseA = isHeap(tree->left);
    bool caseB = isHeap(tree->right);
    
    bool ans = false;

    // if its left and right subtree is heap and then now check it for itself
    if(caseA && caseB)
    {
        int currData = tree->data;
        
        int leftData=0;
        if(tree->left!=NULL)
            leftData = tree->left->data;
            
        int rightData=0;
        if(tree->right!=NULL)
            rightData = tree->right->data;
            
        if(currData>=leftData && currData>=rightData)
            ans = true;
            
        return ans;
    }
    
    return ans;
}



int main()
{
    vector<int> treeNode = {10,20,40,-1,-1,60,-1,-1,30,-1,-1};
    int i=0;
    Node* root = createTree(treeNode,i);

    cout << isHeap(root) << endl;

    return 0;
}



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