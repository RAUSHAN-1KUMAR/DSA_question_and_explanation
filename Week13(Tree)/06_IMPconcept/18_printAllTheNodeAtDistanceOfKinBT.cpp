/* 863

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.


Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    Output: [7,4,1]
    Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.


Example 2:
    Input: root = [1], target = 1, k = 3
    Output: []
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val; 
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


TreeNode* createTree(vector<int> treeNode,int &i)
{
    if(treeNode[i]==-1) return NULL;

    TreeNode* temp = new TreeNode(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
}


// solution from here
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    // first storing parent using BFS
    unordered_map<TreeNode*, TreeNode*> pmap;
    queue<TreeNode*> qu; qu.push(root);

    while(!qu.empty())
    {
        int size = qu.size();

        for(int i=0 ; i<size ; i++)
        {
            TreeNode* parent = qu.front(); qu.pop();

            if(parent->left){
                pmap[parent->left] = parent;
                qu.push(parent->left);
            }

            if(parent->right){
                pmap[parent->right] = parent;
                qu.push(parent->right);
            }
        }
    }
    

    // now applying BFS to find our answer
    unordered_map<TreeNode*, bool> visited;
    visited[target]=true;
    qu.push(target);
    int dis=0; 
    while(!qu.empty() && dis<k)
    {
        int size = qu.size();
        for(int i=0 ; i<size ; i++)
        {
            TreeNode* child = qu.front(); qu.pop();

            // parent
            if(pmap.count(child) && visited[pmap[child]]==false){
                qu.push(pmap[child]);
                visited[pmap[child]]=true;
            }

            // left 
            if(child->left && visited[child->left]==false){
                qu.push(child->left);
                visited[child->left]=true;
            }

            // right 
            if(child->right && visited[child->right]==false){
                qu.push(child->right);
                visited[child->right]=true;
            }
        }

        dis++;
    }


    // build our answer
    vector<int> ans;
    while (!qu.empty())
    {
        ans.push_back(qu.front()->val);
        qu.pop();
    }
    
    return ans;
}

int main()
{
    vector<int> treeNode = {1,2,-1,4,-1,-1,3,-1,-1};
    int i=0;
    TreeNode* root = createTree(treeNode,i);
    return 0;
}