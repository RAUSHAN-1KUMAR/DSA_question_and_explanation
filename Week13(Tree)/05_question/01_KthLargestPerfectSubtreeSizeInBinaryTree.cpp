
/* 3319
Implementing tree using recursion
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

// it returns root node of the created tree
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

// solution start form here
struct node
{
    int noOfNode = 0;
    int leafNodeLevel = 0;
    bool take = false;
};

node helper(TreeNode* root, vector<int> &result, int level)
{
    // base case
    if(root->left==NULL && root->right ==NULL)
    {
        result.push_back(1);

        node s1;
        s1.noOfNode = 1;
        s1.leafNodeLevel = level;
        s1.take = true;

        return s1;
    }

    // left call
    node tempLeft;
    if(root->left != NULL) 
        tempLeft = helper(root->left, result, level+1);

    // right call
    node tempRight;
    if(root->right != NULL) 
        tempRight = helper(root->right, result, level+1);

    // solve one case
    node ans;
    if(tempLeft.take && tempRight.take)
    {
        if(tempLeft.leafNodeLevel == tempRight.leafNodeLevel)
        {
            ans.take = true;
            ans.noOfNode = 1+tempLeft.noOfNode+tempRight.noOfNode;
            ans.leafNodeLevel = tempLeft.leafNodeLevel;

            result.push_back(ans.noOfNode);
        }
    }
    else{
        return ans;
    }

    return ans;
}

int kthLargestPerfectSubtree(TreeNode* root, int k) 
{
    vector<int> result;

    int level=1;
    helper(root, result, level);

    sort(result.begin(), result.end(), [](int a, int b){
        return a > b;
    });

    // side case
    if(result.size()<k) return -1;

    return result[k-1];
}

int main()
{
    vector<int> treeNode = {1,2,-1,4,-1,-1,3,-1,-1};
    int i=0;
    TreeNode* root = createTree(treeNode,i);

    cout << kthLargestPerfectSubtree(root, 3) << endl;

    return 0;
}

