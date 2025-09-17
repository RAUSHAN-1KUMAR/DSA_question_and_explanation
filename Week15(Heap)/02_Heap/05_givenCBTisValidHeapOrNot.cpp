/*
Given CBT, check it that it is valid max heap or not
*/

/*
Approach: recursion
    -- love babbar approach
*/

#include<bits/stdc++.h>
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

void levelWisePrinting(Node* root)
{
    if(root==NULL) return;

    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    while(!qu.empty())
    {
        Node* first = qu.front(); qu.pop();

        if(first==NULL)
        {
            if(!qu.empty()) qu.push(NULL);
            cout << endl;
        }
        else{
            cout << first->data << " ";

            if(first->left!=NULL) qu.push(first->left);
            if(first->right!=NULL) qu.push(first->right);
        }

    }
}

void preOrderTraversal(Node* root)
{
    if(root==NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

Node* createTree(vector<int> treeNode,int &i)
{
    if(treeNode[i]==-1) return NULL;

    Node* temp = new Node(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
}

// solution from here
class info
{
public:
    int maxVal;
    bool isheap;
};

info isHeapHelper(Node* root)
{
    // base cases
    if(root==NULL){
        info temp;
        temp.maxVal = INT_MIN;
        temp.isheap = true;
        return temp;
    }

    if(root->left == NULL && root->right == NULL)
    {
        info temp;
        temp.maxVal = root->data;
        temp.isheap = true;
        return temp;
    }


    //recursive call
    info leftAns = isHeapHelper(root->left);
    info rightAns = isHeapHelper(root->right);

    // solve one case
    info ans;

    if(root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isheap && rightAns.isheap)
    {
        ans.maxVal = root->data;
        ans.isheap = true;
        return ans;
    }

    ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
    ans.isheap = false;

    return ans;
}



int main()
{
    vector<int> treeNode = {10,20,40,-1,-1,60,-1,-1,30,-1,-1};
    int i=0;
    Node* root = createTree(treeNode,i);

    info ans = isHeapHelper(root);
    cout << ans.isheap << endl;

    return 0;
}