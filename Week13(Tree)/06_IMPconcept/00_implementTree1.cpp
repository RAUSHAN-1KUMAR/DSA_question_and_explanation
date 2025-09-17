
/*
Tree ka question aate k saath socho kya isse recursively solve ker sakte h ya iteratively or using queue (level wise)
*/

/*
Implementing tree using recursion
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

// it returns root node of the created tree
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


int main()
{
    vector<int> treeNode = {1,2,5,8,-1,10,-1,-1,-1,6,11,-1,-1,12,-1,-1,4,7,-1,-1,-1};
    int i=0;
    Node* root = createTree(treeNode,i);

    levelWisePrinting(root);
    cout << endl;
    preOrderTraversal(root);

    return 0;
}

