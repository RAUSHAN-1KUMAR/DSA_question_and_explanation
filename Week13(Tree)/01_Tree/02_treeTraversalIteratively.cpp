
/*
All traversal without using recursion 

Total two different approach given donw below
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

// iterative preOrder Traversal(NLR)
void preOrderTraversal(Node* root)
{
    stack<Node*>st;

    while(root!=NULL)
    {
        // go to left till NULL
        while(root!=NULL){
            st.push(root);
            cout << root->data << " ";
            root = root->left;
        }

        // pop stack if there is no right
        while(!st.empty() && st.top()->right==NULL){
            st.pop();
        }

        // assign root
        if(!st.empty()){
            root = st.top()->right; st.pop();
        }
    }
}


// one more approach for iterative preOrder iterative print
void preOrderTraversal2(Node* root){
    if(root==NULL) return;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top(); st.pop();
        cout << root->data << " ";

        if(root->right)  st.push(root->right);// first push right
        if(root->left)  st.push(root->left);// then push left
    }
}


// iterative Inorder traversal
void inorderTraversal(Node *root)
{
    if(root==NULL)
        return;

    stack<Node*> st;
    st.push(root); root = root->left;
    while(!st.empty() || root){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }

        Node* top=st.top(); st.pop();
        cout << top->data << " ";
        root = top->right;
    }
}

// iterative postOrder traversal
void postorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    map<Node*, bool> mp; // to keep track of node that has been traversed left and right
    // we can reduce the TC, by using another stack instead of using map

    stack<Node*> st;
    st.push(root); root = root->left;
    while(!st.empty()){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }

        Node* top = st.top();
        if(mp[top]){
            cout << top->data << " ";
            mp.erase(top);
            st.pop();
        }
        else{
            root = top->right;
            mp[top]=true;
        }
    }
}


// another approch for iterative postOrder traversal: using two stack
void postorderTraversal2(Node *root)
{
    if(root == NULL)
        return;

    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty())
    {
        // exchange the top of stack st1 to st2
        root = st1.top(); st1.pop();
        st2.push(root);

        if(root->left) st1.push(root->left);// first insert left in st1
        if(root->right) st1.push(root->right);// then insert right
    }

    // the order is stored in st2
    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// another approach for iterative postOrder traversal: using one stack
void postorderTraversal3(Node *root)
{
    if(root==NULL)
        return;

    stack<Node*> st;
    while (root!=NULL || !st.empty())
    {
        if(root!=NULL){
            st.push(root);
            root = root->left;
        }   
        else{
            Node* temp = st.top()->right;

            if(temp==NULL){
                temp=st.top(); st.pop();

                cout << temp->data << " "; // post order

                while(!st.empty() && temp==st.top()->right){
                    temp=st.top(); st.pop();
                    cout << temp->data << " "; // post order
                }
            }
            else{
                root = temp;
            }
        }
    }
    
    cout << endl;
}



int main()
{
    vector<int> treeNode = {1,2,5,8,-1,10,-1,-1,-1,6,11,-1,-1,12,-1,-1,4,7,-1,-1,-1};
    int i=0;
    Node* root = createTree(treeNode,i);

    cout << "PreOrder Traversal: ";
    preOrderTraversal2(root);
    cout << endl;

    cout << "InOrder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

