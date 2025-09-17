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
Approach:-
    1. check it is complete Binary tree or not: using queue
    2. check if parent is greater than it's child not or not

Lakshay bhiyaa approach -> next solution
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

// solution from here: first checking it is CBT or not and parallely checking the maxHeap relation between parent and child node
bool isHeap(Node* root)
{
    queue<Node*> qu;
    qu.push(root);

    bool nullFound=false;

    while(!qu.empty())
    {
        Node* front = qu.front();
        qu.pop();

        if(front==NULL)
        {
            nullFound = true;
        }
        else
        { 
            // condition to check CBT
            if(nullFound)
            {
                return false;
            }

            // condition to check relation between parent and child
            if(front->left!=NULL)
                if(front->left->data > front->data)         
                    return false;
            if(front->right!=NULL)
                if(front->right->data > front->data)
                    return false;

            qu.push(front->left);
            qu.push(front->right);
        }
    }

    return true;
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

