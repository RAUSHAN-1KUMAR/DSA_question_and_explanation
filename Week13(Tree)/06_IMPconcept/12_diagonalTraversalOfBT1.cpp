/* GFG

Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree.

*/

/*
Appraoch:- DFS + queue
    -- logic is to take take front node from queue and call dfs for that node
    -- in dfs, if push that node into ans vector, 
        1. if left exist: push it into queue
        2. if right exist: continue dfs
*/


#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }

};

Node* createTree()
{
    int data;
    cin >> data;

    if(data == -1) return NULL;

    Node* root = new Node(data);

    cout << "Enter left of " << data << endl;
    root->left = createTree();

    cout << "Enter right of " << data << endl;
    root->right = createTree();

    return root;
}


vector<int> diagonal(Node* root)
{
    vector<int> ans;

    if(root==NULL) return ans;

    // initializing queue with root node
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        // queue ke front node  ko liye
        Node* temp = q.front();
        q.pop();

        // dfs for that temp
        while (temp)
        {
            ans.push_back(temp->data);

            // ager uss node ka left exist kerta h to ab isko queue m push kerdo taaki next time ab iska right(diagonal) push ho sake
            if(temp->left){
                q.push(temp->left);
            }

            // right m jao
            temp = temp->right;
        }

    }
    
    return ans;
}
 
int main()
{
    cout << "Enter the value of root node ";
    Node* p = createTree();


    return 0;
}