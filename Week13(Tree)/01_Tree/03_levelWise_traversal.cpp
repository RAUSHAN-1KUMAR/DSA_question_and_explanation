/*
LevelWise Traversal or BFS(breath first search)
*/

/*
Appraoch:- using queue
    -- sabse pehle queue ko initialize kregen tree ke root node se
    -- ab ek loop chalayegen jab tak queue empty na ho jaye, iss loop m queue ke front se element lengen usko print krengen and then uss node ke left aur right node ko queue m push kregen and queue ko pop kregen taki jo node use ho gaya h usko reuse na kre.
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

// using queue
void levelWiseTraversal(Node* root)
{
    queue<Node*> q;// queue of NODE*

    q.push(root);//-> initializing queue with root node

    while(!q.empty())
    {
        // taking the node form front of the queue
        Node* first = q.front();

        cout << first->data << " "; //-> printing node ka data

        // ab jo node liye the front of the queue se, uss node ke left aur right node ko push kerdo
        if(first->left != NULL) q.push(first->left);
        if(first->right != NULL) q.push(first->right);

        // pop the used node
        q.pop();
    }

}

int main()
{
    Node* root = createTree();

    levelWiseTraversal(root);

    return 0;
}