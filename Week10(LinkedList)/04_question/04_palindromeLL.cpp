/*
Check Given LL is Palindrome or not
*/

/*
Approach:-
Logic1: 
    - ek nayi reverse list bnao aur then usko starting elements se compare kerte jao

Logic2: (better approach)
    1. break LL into two halves.
    2. reverse the other halve of LL.
    3. now check one by one

    In case of even length from middle node will be first element. but what if length of the LL is odd,-> observe the compareList function.

Logic3: Stack ka use kerke
    1. first store all the elements in stack
    2. then use recursion or while loop to compare the first element with the last element using stack
*/

#include<iostream>
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
};

void printLL(ListNode* &head);
int lengthLL(ListNode* &head);

// solution from here
ListNode* middleNode(ListNode* &head)
{ // tortoise algorithm
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL)
    {
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;

            slow = slow->next;
        }
    }

    return slow;
}

void reverseSLLiteratively(ListNode* &head)
{
    ListNode* prev = NULL;
    ListNode*curr = head;

    while(curr!=NULL)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head = prev;
}


bool compareList(ListNode* head1, ListNode* head2)
{
    // we have condition on head2 only because in case of odd length list, length of head2 will be less than length of head1.
    while (head2 != NULL)
    {
        if(head1->val != head2->val) return false;
        else{
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    
    return true;
}

// applying logic 2
bool isPalindrome(ListNode* &head)
{
    //Step1: find the middle of the LL
    ListNode* midNode = middleNode(head);

    //Step2: break the LL from middle
    ListNode* head2 = midNode->next;
    midNode->next = NULL;

    //Step3: reverse second half
    reverseSLLiteratively(head2);

    //Step4: comparing both half list
    bool ans = compareList(head, head2);

    return ans;
}

int main()
{
    // creating node
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* forth = new ListNode(30);
    ListNode* fifth = new ListNode(20);
    ListNode* sixth = new ListNode(10);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;

    if(isPalindrome(head)) cout << "true";
    else cout << "false";


    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    delete sixth;
    
    return 0;
}




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

