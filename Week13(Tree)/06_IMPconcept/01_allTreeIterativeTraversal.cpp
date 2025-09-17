// IMPORTANT

/*
All Iterative treeTraversal can be done by using the postorder iterative traversal

SC:- (N), we have a morris traversal which can do in O(1) space
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


//  going to use the approach that we did in postorder traversal using single stack
void allTraversal(Node *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    if(root==NULL)
        return;

    stack<Node*> st;
    while (root!=NULL || !st.empty())
    {
        if(root!=NULL){
            st.push(root);
            preorder.push_back(root->data); // preorder
            root = root->left;
        }
        else{
            Node* temp = st.top()->right;
            inorder.push_back(st.top()->data); // inorder
            if(temp==NULL){
                temp=st.top(); st.pop();
                postorder.push_back(temp->data); // postorder
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top(); st.pop();
                    postorder.push_back(temp->data); // postorder
                }
            }
            else{
                root = temp;
            }
        }
    }
}


// one more approach, by maintaining state of each node
void allTraversal2(Node* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder)
{
    if (root == NULL)
        return;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        // needs to be taken as references, so that we can updated the state
        auto &nPair = st.top();
        int &num = nPair.second;
        Node* &node = nPair.first;
        
        if (num == 1) {
            preorder.push_back(node->data);  // Preorder
            num++;
            if (node->left != NULL)
                st.push({node->left, 1});
        }
        else if (num == 2) {
            inorder.push_back(node->data);  // Inorder
            num++;
            if (node->right != NULL)
                st.push({node->right, 1});
        }
        else {
            postorder.push_back(node->data);  // Postorder
            st.pop(); // pop only after postorder
        }
    }
}


int main()
{
    vector<int> treeNode = {1,2,5,8,-1,10,-1,-1,-1,6,11,-1,-1,12,-1,-1,4,7,-1,-1,-1};
    int i=0;

    vector<int> preorder, inorder, postorder;
    Node* root = createTree(treeNode,i);

    allTraversal2(root, preorder, inorder, postorder);

    cout << "PreOrder Traversal: ";
    for(auto num:preorder){
        cout << num << " ";
    }
    cout << endl;

    cout << "Inorder Traversal: ";
    for(auto num:inorder){
        cout << num << " ";
    }
    cout << endl;

    cout << "Postorder Traversal: ";
    for(auto num:postorder){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

