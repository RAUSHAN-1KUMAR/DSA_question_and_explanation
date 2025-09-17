/*
Given a tree, verify that it is completed binary tree or not
*/

/*
Approach: level wise traversal
    -- Love Babbar -> he also used the level wise traversal like it did but he also pushed the NULL node so that we can check for CBT, if after NULL node any real node comes then it't not a CBT.

*/


#include<iostream>
#include<vector>
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

void levelWisePrinting(Node* root);
void preOrderTraversal(Node* root);
Node* createTree(vector<int> treeNode,int &i);

// solution from here
bool levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);

    bool nullFound = false;

    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front==NULL)
        {
            nullFound=true;
        }
        else
        {
            if(nullFound){
                return false; 
            }

            q.push(front->left);//-> will push the null also
            q.push(front->right);//-> will push the null also
        }

    }
    
    return true;
}

bool checkValidCBT(Node* root)
{
    return levelOrderTraversal(root);
}


int main()
{
    vector<int> treeNode = {10,11,12,13,-1,-1,23,-1,-1,45,12,-1,-1,25,-1,-1,30,20,10,-1,-1,20,-1,-1,-1};
    int i=0;
    Node* root = createTree(treeNode,i);

    if(checkValidCBT(root)) cout << "Valid CBT" << endl;
    else cout << "Invalid CBT" << endl;


    return 0;
}



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

