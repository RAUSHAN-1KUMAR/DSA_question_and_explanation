/* -> 2181

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Example 2:
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

*/

/*
Appraoch:- three pointer
    -- pehla pointer iterate krega list m aur sum ko store krega jabtak zero na mile list m, 
    -- zero milte ke sath dusra_pointer->val = sum ker dengen aur dusra pointer ko aage badha denge, isse ham koi extra space nhi lengen.
    -- teesra pointer dusra pointer ke just piche rahega taki last m ham apne answer wale list ko detach ker sake
*/

#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(){
        this->next = NULL;
    }

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }

    ~ListNode()
    {
        cout << "Dtor called for:" << this->val << endl;
    }
};

void printLL(ListNode* &head)
{
    ListNode *temp = head;

    while(temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthLL(ListNode* &head)
{
    ListNode *temp = head;

    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void deleteAllNode(ListNode* &head)
{
    ListNode* temp = head;

    while (head!=NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    
    delete temp;
}

ListNode* reverseLL(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr!=NULL)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

ListNode* mergeNodes(ListNode* head)
{
    // base case
    if(head==NULL) return NULL;

    ListNode* first = head;
    ListNode* second = head->next;
    ListNode* third = NULL;
    int sum = 0;

    while (second != NULL)
    {
        // second_pointer ki val 0 nhi h to sum kerte jao
        if(second->val != 0){
            sum += second->val;
        }
        else{ // second_pointer ki val 0 ho gyi
            first->val = sum;
            third = first;
            first = first->next;
            sum=0;
        }

        second= second->next;
    }
    
    // formed list ko detach kerdo
    third->next = NULL;

    // baki jo node bach gya usko delete kerdo
    ListNode* temp = first;
    while (temp != NULL)
    {
        ListNode* next = temp->next;
        delete temp;
        temp = next;
    }
    
    return head;
}

int main()
{
    ListNode* first = new ListNode(0);
    ListNode* second = new ListNode(5);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(0);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(0);

    ListNode* root = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;


    printLL(root);

    ListNode* ans = mergeNodes(root);

    printLL(ans);

    deleteAllNode(root);

    return 0;
}

