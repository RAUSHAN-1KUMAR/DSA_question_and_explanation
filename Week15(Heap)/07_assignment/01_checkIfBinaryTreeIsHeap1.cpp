/* -> GFG

Given a binary tree. The task is to check whether the given tree follows the max heap property or not.

Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:
    Input:
            5
           / \
          2   3
    Output: 1
    Explanation: The given tree follows max-heap property since 5, is root and it is greater than both its children.


    Input:
         10
        /  \
      20   30 
     /  \
    40  60
    Output: 0

*/

/*
Approach:- Lakshay bhiyaa approach
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

void levelWisePrinting(Node* root);
void preOrderTraversal(Node* root);
Node* createTree(vector<int> treeNode,int &i);

// solution from here:
int nodeCount(Node* root)
{
    if(root==NULL) return 0;

    int l=nodeCount(root->left);
    int r=nodeCount(root->right);

    return 1+l+r;
}

// observe carefully this CBT check, it is done using the index i
bool isCBT(Node* root, int i, int &n)
{
    if(root==NULL) return true;
    
    if(i > n) return false;

    return isCBT(root->left, 2*i, n) && isCBT(root->right, 2*i+1, n);
}

bool isMaxOrder(Node* root)
{
    if(root==NULL) return true;

    int l = isMaxOrder(root->left);
    int r = isMaxOrder(root->right);

    bool ans = false;

    if(root->left==NULL && root->right==NULL)
    {
        ans = true;
    }
    else if(root->left && root->right==NULL)
    {
        ans = root->data > root->left->data;
    }
    else 
    {
        ans = root->data > root->left->data && root->data > root->right->data;
    }

    return ans && l && r;
}

bool isHeap(Node* root)
{
    int n=nodeCount(root);
    int i=1; //-> indexing of tree form 1
    return isCBT(root, i, n) && isMaxOrder(root);
}


int main()
{
    vector<int> treeNode = {10,11,12,13,-1,-1,23,-1,-1,45,12,-1,-1,25,-1,-1,30,20,10,-1,-1,20,-1,-1,-1};
    int i=0;
    Node* root = createTree(treeNode,i);

    if(isHeap(root)) cout << "Valid MaxHeap" << endl;
    else cout << "Invalid MaxHeap" << endl;


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

