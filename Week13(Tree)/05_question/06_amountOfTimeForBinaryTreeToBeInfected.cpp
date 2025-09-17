/* -> 2385 similar to burning tree

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:
    - The node is currently uninfected.
    - The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.


Example 1:
    Input: root = [1,5,3,null,4,10,6,9,2], start = 3
    Output: 4
    Explanation: The following nodes are infected during:
    - Minute 0: Node 3
    - Minute 1: Nodes 1, 10 and 6
    - Minute 2: Node 5
    - Minute 3: Node 4
    - Minute 4: Nodes 9 and 2
    It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:
    Input: root = [1], start = 1
    Output: 0
    Explanation: At minute 0, the only node in the tree is infected so we return 0.
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
int amountOfTime(TreeNode* root, int start)
{
    // lets build parent map and find our start node
    unordered_map<TreeNode*, TreeNode*> parentMap;
    TreeNode* target = NULL;
    queue<TreeNode*> qu; qu.push(root);
    while (!qu.empty())
    {
        int size = qu.size();
        for(int i=0 ; i<size ; i++)
        {
            TreeNode *t = qu.front() ; qu.pop();
            
            if(t->val == start && target==NULL){
                target = t;
            }

            if(t->left){
                parentMap[t->left] = t;
                qu.push(t->left);
            }

            if(t->right){
                parentMap[t->right] = t;
                qu.push(t->right);
            }
        }
    }

    
    // lets burn the tree
    unordered_map<TreeNode*, bool> vis; vis[target] = true;

    qu = queue<TreeNode*>();
    qu.push(target);
    int timeTaken = 0;

    while(!qu.empty())
    {
        int size = qu.size();
        bool isFireSpreaded=false;

        for(int i=0 ; i<size; ++i)
        {
            TreeNode* t = qu.front(); qu.pop();

            // parent
            if(parentMap.count(t) && vis[parentMap[t]]==false)
            {
                qu.push(parentMap[t]);
                vis[parentMap[t]]=true;
                isFireSpreaded = true;
            }

            // left
            if(t->left!=NULL && vis[t->left]==false)
            {
                qu.push(t->left);
                vis[t->left]=true;
                isFireSpreaded = true;
            }

            // right
            if(t->right!=NULL && vis[t->right]==false)
            {
                qu.push(t->right);
                vis[t->right]=true;
                isFireSpreaded = true;
            }


        }
        
        if(isFireSpreaded) timeTaken++;
    }

    return timeTaken;
    
}

int main()
{
    vector<int> treeNode = {1,2,-1,4,-1,-1,3,-1,-1};
    int i=0;
    TreeNode* root = createTree(treeNode,i);
    return 0;
}

