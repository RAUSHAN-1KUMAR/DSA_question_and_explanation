/* -> 2058

A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].


Example 1:
    Input: head = [3,1]
    Output: [-1,-1]
    Explanation: There are no critical points in [3,1].

Example 2:
    Input: head = [5,3,1,2,5,1,2]
    Output: [1,3]
    Explanation: There are three critical points:
    - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
    - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
    - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
    The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
    The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

Example 3:
    Input: head = [1,3,2,2,3,2,2,2,7]
    Output: [3,3]
    Explanation: There are two critical points:
    - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
    - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
    Both the minimum and maximum distances are between the second and the fifth node.
    Thus, minDistance and maxDistance is 5 - 2 = 3.
    Note that the last node is not considered a local maxima because it does not have a next node.
*/

/*
Approach:- three pointer iteratively
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

// solution form here
vector<int> nodesBetweenCriticalPoints(ListNode* head)
{
    vector<int> ans = {-1,-1};

    // base conditions
    ListNode* prev = head;
    if(prev==NULL) return ans;

    ListNode* curr = prev->next;
    if(curr==NULL) return ans;

    ListNode* next = curr->next;
    if(next==NULL) return ans;

    
    //Now
    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i=1;
    while (next!=NULL)
    {
        bool isCP = ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) ? true : false;

        if(isCP && firstCP == -1){//-> ager pehla CP
            firstCP = i;
            lastCP = i;
        }
        else if(isCP){ //-> ager next CP 
            minDist = min(minDist, i-lastCP);
            lastCP = i;
        }

        i++;
        prev = prev->next;
        curr = curr->next;
        next = next->next;
    }

    // finding max distance
    if(firstCP==lastCP){// only 1 CP was found
        return ans;
    }
    else{
        ans[0] = minDist;
        ans[1] = lastCP - firstCP; 
    }
    
    return ans;
}


int main()
{
    ListNode* first = new ListNode(1);
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

    vector<int> ans = nodesBetweenCriticalPoints(root);

    for(auto num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    deleteAllNode(root);

    return 0;
}

