/*
We are given a binary tree and we are asked to print its top view
*/

/*
Appraoch:- simple levelWise traversal with pair of queue
    -- but how we form our answer-> using map
    -- her ek node p pair hoga {node_ka_data, col}, which will pushed in our queue
    -- if that col is not visited(checked using map) then it means it's the top data for that col, mark it value in map
*/


#include<iostream>
#include<map>
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

void printTopView(Node* root)
{
    map<int,int> hdToNodeMap; // to track col

    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    //Now level order traversal
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();q.pop();

        Node* frontNode = temp.first;
        int col = temp.second;

        // if col is not mapped
        if(hdToNodeMap.find(col) == hdToNodeMap.end()){
            hdToNodeMap[col] = frontNode->data;
        }


        if(frontNode->left != NULL) 
            q.push(make_pair(frontNode->left, col-1));//-> col-1 kiye left ke liye taki map m left wala ordered way m first p aajaye

        if(frontNode->right != NULL) 
            q.push(make_pair(frontNode->right, col+1));//-> col+1 kiye right ke liye taki map m right wale ordered way m last p aate jaye
    }

    // our answer is in map
    cout << "printing top view: " << endl;
    for(auto i:hdToNodeMap)
    {
        cout << i.second << " ";
    }
}

int main()
{
    cout << "Enter the value for root node: ";
    Node* root = createTree();


    printTopView(root);

    return 0;
}