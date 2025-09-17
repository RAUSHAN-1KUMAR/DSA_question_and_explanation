/*
LevelWise Printing
    -- we will use a marker(NULL) for each level

*/

/*
Appraoch:- marking using NULL + queue
    -- iss question m hame level wise print kerna h so level ko identify krne ke liye queue m kuch aesa value(NULL) push kerna hoga ki jab wo aate to hame pata chal jaye ki haa ye ek level h.
    
Catch:- last wale NULL m infinite loop ho jayega to usko handle kerna h
*/

#include<iostream>
#include<queue>
#include<vector>
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

void levelWisePrinting(Node* root)
{
    queue<Node*> q;

    //-> initializing queue with root node and NULL
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* first = q.front();
        q.pop();

        if(first == NULL)
        {
            cout << endl;
            if(!q.empty())//-> Catch to avoid infinite loop
            { 
                q.push(NULL); //-> pushing null for next 'endl'
            }
        }
        else
        {
            cout << first->data << " ";
            if(first->left != NULL) q.push(first->left);
            if(first->right != NULL) q.push(first->right);
        }
    
    }
}


int main()
{
    Node* root = createTree();

    levelWisePrinting(root);

    return 0;
}