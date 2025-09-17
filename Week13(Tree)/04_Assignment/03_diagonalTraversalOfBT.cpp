/* GFG

Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree.

*/

/*
Appraoch:- DFS + map
    -- ek variable 'd' ka use ker rhe h diagonal ko batne ke liye aur uss d ke respective jitne element h usko map m store ker rhe h

    - when we call left, means we are changing diagonal. So, d+1
    - when we call right, means we are at same diagoanl. So, d
*/


#include<iostream>
#include<vector>
#include<map>
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


// soltion from here
void diagonalTraversalHelper(Node* root, map<int, vector<int>> &mp, int d)
{
    // base case
    if(root == NULL) return;

    // RE
    diagonalTraversalHelper(root->left, mp, d+1);

    mp[d].push_back(root->data);

    diagonalTraversalHelper(root->right, mp, d);
}

vector<int> diagonal(Node* root)
{
    // initial base case
    if(root->left == NULL && root->right == NULL) return vector<int> {root->data};

    // map to store the data diagonal wise
    map<int, vector<int>> mp;
    int d = 0;

    // function for our work
    diagonalTraversalHelper(root, mp, d);

    // forming our main answer by iterating on map
    vector<int> ans;
    for(auto it = mp.begin() ; it!=mp.end() ; it++)
    {
        ans.insert(ans.end(), it->second.begin(), it->second.end());
    }

    return ans;
}
 
int main()
{
    cout << "Enter the value of root node ";
    Node* p = createTree();
    return 0;
}