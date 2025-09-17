
/*
Generic tree implementation i.e., more than 2 child node
*/

#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data; 
    int children_count=0;
    Node** children;

    Node(int val)
    {
        this->data = val;
        this->children_count=0;
        this->children=NULL;
    }
};

Node* takeInput()
{
    int data, count;
    cout << "Enter data: ";
    cin >> data;

    cout << "Enter children count for " << data << " node: ";
    cin  >> count;

    if(data == -1) return NULL;

    Node* root = new Node(data);

    // change1
    root->children_count = count;
    root->children = new Node*[count];

    // change2
    for(int i=0 ; i<count; i++)
        root->children[i] = takeInput();


    return root;
}

void levelWisePrinting(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* first = q.front();
        q.pop();

        if(first == NULL)
        {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else
        {
            cout << first->data << " ";
            // change1
            for(int i=0 ; i<first->children_count ; i++)
            {
                if(first->children[i])
                {
                    q.push(first->children[i]);
                }
            }
        }
    }
}

int main()
{
    Node* root = takeInput();
    levelWisePrinting(root);

    return 0;
}

