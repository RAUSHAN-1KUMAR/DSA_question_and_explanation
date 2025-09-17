// 450

/*
Approach:-
    -- to delete a node, we have four cases
        1. both the left and right of the node is null
        2. only left is null
        3. only right is null
        4. neither right is null nor left is null

    Case1: delete that node and return NULL
    Case2: delete that node and return node->right
    Case3: delete that node and return node->left
    Case4: the complex case because we have to maintain the BST's Nature
        - Method1: left subtree m jao aur maximum value utha lao and then uss max value ko deleted wale node p assign kerdo and then uss max value ko janha se laaye the uss node ko delete kerdo
        - Method2: right subtree m jao aur minimum value utha lao and then uss min value ko deleted wale node p assign kerdo and then uss min value ko janha se laaye the uss node ko delete kerdo
*/

#include<iostream>
#include<queue>
using  namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data)
{
    // if its the first node
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // if its not the first node
    if(data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node* &root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}

Node* maxValue(Node* root)
{
    // base case
    if(root->right == NULL){
        return root;
    }

    return maxValue(root->right);
}

// solution from here (recursive approach)
Node* deleteFromBST(Node* root, int target)
{
    // target ko dhundo
    // target ko delete karo

    if(root==NULL)
    {
        return NULL;
    }


    if(target == root->data)
    {
        // ab delete krengen

        // Case1-> both right and left are NULL
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL)// case2-> only right is NULL
        {
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        else if(root->left == NULL && root->right != NULL)// case3-> only left is NULL
        {
            Node* childSubtree = root->right;
            delete root; 
            return childSubtree;
        }
        else // case4-> left non null and right non null
        {
            // Method1. left subtree ki max value lao
            Node* maxi = maxValue(root->left);

            // replace
            root->data = maxi->data;

            // delete the actual maxi node(important)
            root->left = deleteFromBST(root->left, maxi->data);

            return root;
        }
    }
    else if(root->data > target)
    {
        // left m chalo
        root->left =  deleteFromBST(root->left, target);
    }
    else
    {
        // right m chalo
        root->right = deleteFromBST(root->right, target);
    }

    return root;
} 

int main()
{
    Node* root = NULL;
    createBST(root);



    int target;
    cout << "Enter the target: ";
    cin >> target;

    while(target != -1)
    {
        root = deleteFromBST(root, target);
        cout << endl << "Enter the target: ";
        cin >> target;
    }


    return 0; 
}