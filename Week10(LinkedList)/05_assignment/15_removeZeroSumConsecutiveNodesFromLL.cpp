/* -> 1171

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.


(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
*/

/*
Appraoch:- iterative + observation type

Lets first focus on array wali approach:
    -- Logic:
       if a + (h+x+f+e+..) = a 
        => (h+x+f+e+..) = 0
            - isse ham kya intuition bna pa rhe h, ki hame ek hashing kerni hogi each prefix_sum aur index ka our wo sum dubara milta h matlab zero sum mil gya, wanha tak ke elements ko remove kro and then phir aage check kro but agge badhne se pehle map m jo ab old entry padi h usko to clear kerna padega na, to usko clear kerdengen

       if a + (j+d+e+..) = 0
            - simple, sari nodes ko hata do last janha p zero mila h wanha tak
        
Now In Linked list:
    - same as array wali, the only difference will be mapping i.e., between prefix_sum and last value jo sum hua h uska NodeAddress

Note:- sum milne ke baad map ko renew kerna hi iss question ko complex bna rha h.
    To sum map to renew kaise krengen:
        -- uske liye ek seperate function create ker dengen jisme ham pass krengen 
            1. jo sum map m mil gya h uska->next ko
            2. map ko aur
            3. current sum ko
        -- function ke ander , diye gaye node se value sum kerte jayengen current sum m, aur phir map m find kerke delete ker dengen, kabtak, jabtak dubara current sum na mil jaye.

-- aur jab: a+(s+e+f+..) = 0.
    - iss case m direct jis postion p 0 mil h uske node p chale jayengen, aur map ko sidha clear ker dengen
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
void sanitizeMap(ListNode* curr, unordered_map<int, ListNode*> &mp, int csum)
{
    int temp = csum;

    while (true)
    {
        temp += curr->val;

        if(temp == csum) break;

        mp.erase(temp);

        curr = curr->next;
    }
}

ListNode* removeZeroSumSublists(ListNode* head) 
{
    if(head==NULL || (head->next==NULL && head->val == 0)) return 0;

    unordered_map<int, ListNode*> mp;

    auto it = head;
    int csum = 0;

    while (it!=NULL)
    {
        csum += it->val;
        
        if(csum == 0)// ager zero sum mila
        {
            head = it->next;// head direct it ke aage
            mp.clear();// clear map
        }
        else if(mp.find(csum) != mp.end())// ager sum map m pehle se maujud h
        {
            sanitizeMap(mp[csum]->next, mp, csum);// map ko renew kerdo
            mp[csum]->next = it->next; // oldsumNode point to next of janha p same sum mila
        }
        else // ager sum map m maujud nhi h
        {
            mp[csum] = it;
        }

        it = it->next;
    }
    
    return head;
}


int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(-3);
    ListNode* forth = new ListNode(3);
    ListNode* fifth = new ListNode(1);

    ListNode* root = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    ListNode* ans = removeZeroSumSublists(root);

    printLL(ans);


    deleteAllNode(root);

    return 0;
}


