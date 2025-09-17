/* -> 1721

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
*/

/*
Appraoch:- two pointer
    1. simple approach: ek pointer ko starting se iterate kerte kerte k tak jao, aur dusre pointer ko starting se iterate kerte kerte n-k+1 tak jao, aur phir dono pointer ki value ko change kerdo

    2. complex approach(hard level): links ko change krengen
        -- bhut se cases honge 

We will proceed with complex approach
*/

#include<iostream>
#include<vector>
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


// solution from here
ListNode* swapNodes(ListNode* head, int k)
{
    // base cases
    if(head==NULL || head->next == NULL) return head;

    int len = lengthLL(head);
    int lpos = k;
    int rpos = len-k+1;

    // catch
    if(rpos<lpos) swap(lpos, rpos);

    // case1 (both point to same node)
    if(lpos == rpos) return head;

    // case2 (only 2 node in LL)
    if(len == 2){
        ListNode* nextNode = head->next;
        nextNode->next = head;
        head->next = NULL;
        head = nextNode;
        return head;
    }

    // case3 (both point are end to end)
    if(lpos == 1){
        ListNode* lp = NULL; // leftPointer(lp) lies behin leftNode(ln)
        ListNode* ln = head; // leftNode

        ListNode* rp = head;// rightPointer(rp) lies behind rightNode(rn)
        for(int i=0 ; i<rpos-2 ; i++)
        {
            rp = rp->next;
        }
        ListNode* rn = rp->next; // rightNode

        ListNode* rsave = NULL; // rightNode ke just baad wali node p

        // swapping
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;
        head = rn;

        return head;
    }

    // case4 (both point are adjacent)
    int noOfNodesBetweenSwapNodes = rpos-lpos-1;

    if(noOfNodesBetweenSwapNodes == 0){
        ListNode* lp = head;// lp ln ke piche jayega
        for(int i=0 ; i<lpos-2 ; i++)
        {
            lp = lp->next;
        } 
        ListNode* ln = lp->next;

        ListNode* rp = head;// rp rn ke piche jayega
        for(int i=0 ; i<rpos-2 ; i++)
        {
            rp = rp->next;
        }
        ListNode* rn = rp->next;

        ListNode* rsave = rn->next;// rs rn ke just aage wala

        //swapping
        lp->next = rp->next;
        rn->next = rp;
        rp->next = rsave;
        return head;
    }

    // case5 (both point are not adjacent)
    if(noOfNodesBetweenSwapNodes>=1){
        ListNode* lp = head;// lp ln ke piche jayega
        for(int i=0 ; i<lpos-2 ; i++)
        {
            lp = lp->next;
        } 
        ListNode* ln = lp->next;

        ListNode* rp = head;// rp rn ke piche jayega
        for(int i=0 ; i<rpos-2 ; i++)
        {
            rp = rp->next;
        }
        ListNode* rn = rp->next;

        ListNode* rsave = rn->next;// rs rn ke just aage wala

        // swapping
        lp->next = rn;
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;
        return head;
    }

    return NULL;
}

int main()
{
    ListNode* first = new ListNode(9);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    ListNode* root = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    printLL(root);

    ListNode* ans = swapNodes(root,2);

    printLL(ans);

    deleteAllNode(ans);

    return 0;
}


