/* -> 1382
Median-> middle element 
    1,2,3,4,5 -> (n+1)/2 term i.e., 3
    1,2,3,4,5,6 -> [(n/2 term) + ((n/2 + 1) term)]/2 i.e., 3.5

Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:
    Input:
           6
         /   \
       3      8   
     /  \    /  \
    1    4  7    9
    Output: 6
    Explanation: Inorder of Given BST will be:
    1, 3, 4, 6, 7, 8, 9. So, here median will 6.

    Input:
           6
         /   \
       3      8   
     /   \    /   
    1    4   7   
    Output: 5
    Explanation:Inorder of Given BST will be:
    1, 3, 4, 6, 7, 8. So, here median wil (4 + 6)/2 = 10/2 = 5.
*/

/*
Approach:-
    1. common:- make vector of inorder traversal and then find the median from that vector

    but to make vector of inorder traversal we have three ways:-
        1. using recurstion:- time(O(n)) and space(O(n)).
        2. using stack:- same time and will take some space(stack).
        3. morris traversal:- time(O(n)) and space(O(1)).

    So we will use morris traversal to find inorder of the given BST
*/


#include<iostream>
#include<stack>
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

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front(); q.pop();

        if(front == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
    }
}

Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        Node* first = new Node(data);
        return first;
    }

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

void createBST(Node* &root, vector<int> &vec)
{
    for(int eachval:vec)
    {
        root = insertIntoBST(root, eachval);
    }
}

float findMedian()
{

}


int main()
{
    vector<int> vec = {50,20,60,70,55,65,10,80,25};
    Node* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);


    return 0;
}

