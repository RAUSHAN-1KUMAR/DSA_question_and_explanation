/*
We are given a binary tree and we are asked to print its bottom view
*/

/*
Appraoch:- 
    -- appraoch and code is very similar to previous topViewOfBT question. In that question, we were checking that 'col' is present on map or not to store that col's first node, but now if we just remove that condition on our code we will get the bottomViewOfBT

for recursive solution we need depth variable as well so that we can actually check the new depth for that perticular col
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

// iterative solution
void printBottomView(Node* root)
{
    map<int,int> hdToNodeMap;

    queue<pair<Node*, int>> q;//{node, column}

    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();q.pop();

        Node* frontNode = temp.first;
        int col = temp.second;

        // removed this condion to store that col's last node
        // if(hdToNodeMap.find(col) == hdToNodeMap.end()){
        //     hdToNodeMap[col] = frontNode->data;
        // }

        // and overwrite the col's node
        hdToNodeMap[col] = frontNode->data;

        if(frontNode->left != NULL) q.push(make_pair(frontNode->left, col-1));
        if(frontNode->right != NULL) q.push(make_pair(frontNode->right, col+1));
    }


    cout << "printing bottom view: " << endl;
    for(auto i:hdToNodeMap)
    {
        cout << i.second << " ";
    }
}


// recursive solution
void helper(Node* root, map<int, pair<int, int>> &bmap, int col, int depth) {
    if (root == NULL)
        return;
    
    // Only update if:
    // 1. column not present in map
    // 2. current depth is greater than or equal to stored depth
    if (bmap.find(col) == bmap.end() || depth >= bmap[col].second){
        bmap[col] = {root->data, depth};
    }

    helper(root->left, bmap, col - 1, depth + 1);
    helper(root->right, bmap, col + 1, depth + 1);
}


void bottomView(Node *root) {
    if (root == NULL)
        return;

    map<int, pair<int, int>> bmap;  // col -> {value, depth}
    helper(root, bmap, 0, 0);


    for (auto &p : bmap) {
        cout << p.second.first << " ";
    }
    cout << endl;
}

int main()
{

    return 0;
}