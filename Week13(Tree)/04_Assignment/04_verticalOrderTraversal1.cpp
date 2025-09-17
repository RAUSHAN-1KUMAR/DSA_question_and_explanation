
/*
Appraoch:- recurtion + map of map<int, mulitset>>
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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

TreeNode* createTree(vector<int> &nums, int &index)
{
    int num = nums[index];

    // base case
    if(num == -1) return NULL;

    TreeNode* root = new TreeNode(num);

    index++;
    root->left = createTree(nums, index);

    index++;
    root->right = createTree(nums, index);

    return root;
}

void levelWisePrinting(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* front = q.front();
        q.pop();

        if(front==NULL)
        {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else
        {
            cout << front->val << " ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    }
}

// solutino from here
void helperMap(TreeNode* root, map<int, map<int, multiset<int>>> &mp, int col, int row)
{
    //  base case
    if(root==NULL) return;

    mp[col][row].insert(root->val);

    helperMap(root->left, mp, col-1, row+1);

    helperMap(root->right, mp, col+1, row+1);
}

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    map<int, map<int, multiset<int>>> mp;

    helperMap(root, mp, 0, 0);

    vector<vector<int>> ans;
    // store final answer into ans vector
    for(auto it: mp) //-> iterating on first map 
    {
        auto &colMap = it.second;//-> first map ke second map p gye
        vector<int> vLine;

        for(auto colMapIt:colMap) //-> iterating on second map
        {
            auto &mSet = colMapIt.second; //-> second map ke second p data stored h
            vLine.insert(vLine.end(), mSet.begin(), mSet.end());
        }
        ans.push_back(vLine);
    }
    
    return ans;
}

int main()
{
    vector<int> num = {1,2,4,-1,-1,6,-1,-1,3,5,-1,-1,7,-1,-1};

    int i=0;
    TreeNode* root = createTree(num, i);

    vector<vector<int>> ans = verticalTraversal(root);

    for(auto vec:ans){
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}