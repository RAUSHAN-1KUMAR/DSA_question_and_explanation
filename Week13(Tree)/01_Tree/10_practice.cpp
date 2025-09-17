
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node* left;
    node* right;

    node(int data){
        this->val = data;
        this->left = this->right = NULL;
    }
};

node* createTree(){
    cout << "Enter the value of the node: ";
    int data;
    cin >> data;

    if(data==-1)
        return NULL;
    
    node* newNode = new node(data);

    cout << "Left subtree for node: " << newNode->val << endl;
    newNode->left = createTree();

    cout << "Right subtree for node: "<< newNode->val << endl;
    newNode->right = createTree();

    return newNode;
}

//lever wise traversal
void leverlWise(node* root){
    if(root==NULL)
        return;

    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);

    while(!qu.empty()){
        node* first=qu.front();qu.pop();

        if(first!=NULL){
            cout << first->val << " ";
            if(first->left) qu.push(first->left);
            if(first->right) qu.push(first->right);

        }
        else{
            cout << endl;
            if(!qu.empty()){
                qu.push(NULL);
            }
            else
                break;
        }
    }
}

int main()
{
    node* root = createTree();
    leverlWise(root);
    return 0;
}