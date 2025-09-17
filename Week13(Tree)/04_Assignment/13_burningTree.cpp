/* -> similar to 2385 and GFG

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 
    Input:      
              1
            /   \
          2      3
        /  \      \
       4    5      6
           / \      \
          7   8      9
                       \
                       10
    Target Node = 8
    Output: 7
    Explanation: If leaf with the value 8 is set on fire. 
    After 1 sec: 5 is set on fire.
    After 2 sec: 2, 7 are set to fire.
    After 3 sec: 4, 1 are set to fire.
    After 4 sec: 3 is set to fire.
    After 5 sec: 6 is set to fire.
    After 6 sec: 9 is set to fire.
    After 7 sec: 10 is set to fire.
    It takes 7s to burn the complete tree.
*/

/*
Appraoch:- 
    -- Step1: find the target node
    -- target node ko find to ker lengen but her node ke parent ka parent ko kaise pta kregen, uske liye ham map ka use krengen. 
    -- Step2: make node to parent node mapping
    -- step3: to mark fired node
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
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

// levelWise traversal use krengen
Node* makeNodeToParentMappinngAndFindTargetNode(Node* root, unordered_map<Node*, Node*> &parentMap, int target)
{
    queue<Node* >q;
    Node* targetNode = NULL;// abhi targetNode null h

    q.push(root);// initializing queue

    parentMap[root]=NULL;// root ka parent null hoga

    while(!q.empty())
    {
        Node* front = q.front(); q.pop();

        // target mil gya to target node ko store kerlo but ham break nhi kr rhe taaki saare node to parent ka link map m store ho jaye
        if(front->data == target)
        {
            targetNode = front;
        }

        // pushing node into queue as well as marking its parent in map
        if(front->left) {
            q.push(front->left);
            parentMap[front->left] = front;
        }

        if(front->right){
            q.push(front->right);
            parentMap[front->right] = front;
        }
    }

    return targetNode;
}

int burnTheTree(Node* targetNode, unordered_map<Node*, Node*> &parentMap)
{
    // To mark burnt node
    unordered_map<Node*, bool> isBurnt;

    // to store that nodes, janha se ab fire spread ho rha
    queue<Node*> q;

    int timeTaken = 0;

    // initializd the burned queue and map
    q.push(targetNode);
    isBurnt[targetNode] = true;

    while(!q.empty())
    {
        int size = q.size();
        bool isFireSpreaded=false;

        // queue m jitne element pade h usko sath m empty ker rhe kyunki fire to jitne node tak gya a ab wo sab node se ek saat spread hoga
        for(int i=0 ; i<size; ++i)
        {
            Node* front = q.front(); q.pop();

            // jo node q m tha uska left node m fire spread hoga if not visited
            if(front->left!=NULL && isBurnt[front->left]==false)
            {
                q.push(front->left);
                isBurnt[front->left]=true;
                isFireSpreaded = true;
            }

            // jo node q m tha uska right node m fire spread hoga if not visited
            if(front->right!=NULL && isBurnt[front->right]==false)
            {
                q.push(front->right);
                isBurnt[front->right]=true;
                isFireSpreaded = true;
            }

            // jo node q m tha uska parent node m fire spread hoga if not visited and parent exist
            if(parentMap[front] && isBurnt[parentMap[front]]==false)
            {
                q.push(parentMap[front]);
                isBurnt[parentMap[front]]=true;
                isFireSpreaded = true;
            }

        }
        
        if(isFireSpreaded) timeTaken++;
    }

    return timeTaken;
}

int minTime(Node* root, int target)
{
    // map to make link between node to parent node
    unordered_map<Node*, Node*> parentMap;

    Node* targetNode = makeNodeToParentMappinngAndFindTargetNode(root, parentMap, target);

    return burnTheTree(targetNode, parentMap);
}

int main()
{
    Node* root = createTree();

    return 0;
}