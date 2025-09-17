#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

Node* createTree(vector<int> &val, int &index)
{
    int data = val[index];

    // base case
    if(data == -1) return NULL;

    Node* root = new Node(data);

    index++;
    root->left = createTree(val, index);

    index++;
    root->right = createTree(val, index);

    return root;
}

void levelWisePrinting(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front==NULL)
        {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    }
}

int main()
{
    vector<int> val = {5,6,1,-1,10,-1,-1,8,4,-1,-1,3,-1,-1,7,11,-1,-1,12,13,-1,-1,14,-1,-1};

    int i=0;
    Node* root = createTree(val, i);

    cout << "Printing formed tree: " << endl;
    levelWisePrinting(root);

    return 0;
}