/* -> 460

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:
    1. LFUCache(int capacity) Initializes the object with the capacity of the data structure.

    2. int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.

    3. void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

    4. To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:
    Input: ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
    Output: [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
    Explanation
    // cnt(x) = the use counter for key x
    // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
    LFUCache lfu = new LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);      // return 4
                    // cache=[4,3], cnt(4)=2, cnt(3)=3

*/

/*
Approach: little bit complex from LRU, becuase we have to check for individual freq and then if freq is same the follow LRU
    -- the logic was little bit same as LRU, i.e., if map is full then remove the head, it means in this question also we are maintainig the LRU at head but what about freq
    -- used a another one more map(freq, node_pointer) to point the top of perticular freq node
    -- in case if we have to remove a perticular freq node, i.e., in case of key access or key-value opdation we remove it and then increase the freq of it and then reinsert it. So in doing so we also have to maintain the freq map i.e., in removal and insertion operation
    -- so if we are inserting newNode then find its freq node first if we got it then place just after that same freqNode, it not then place it in front of tail and then update the freq map also
    -- if we are removing node then we have to check either it is head of that perticular freq node or intermediate, if intermediate the remove that node
        - but if it is head then we have move the pointer to that freq back it same freq node exist otherwise no need to 
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, value, freq;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), freq(1), prev(NULL), next(NULL){}
};

class DLL
{
public:
    Node* head;
    Node* tail;

    DLL():head(NULL){}

    void addNode(Node* newNode, unordered_map<int, Node*> &freqMp)
    {
        // if pehla node h
        if(head==NULL)
        {
            head = tail = newNode;

            freqMp[head->freq] = newNode;
        }
        else
        {
            // if freq of new node is less than freq of head then place it before head
            if(newNode->freq < head->freq)
            {
                newNode->next = head;
                head->prev = newNode;

                head = newNode;

                // new entry to freqMp
                freqMp[newNode->freq] = head;
            }
            else // if freq of new node is equal or greater then
            {
                // i) find its freq node which is already in DLL
                auto it = freqMp.find(newNode->freq); // now this is our last node for that freq

                // if we don't get that freq node, it means it's freq is new and it go to top of tail
                Node *placeNode = (it==freqMp.end() ? tail : it->second); 

                // ii) insert the node ahead of placeNode
                newNode->prev = placeNode;
                newNode->next = placeNode->next;
                if(placeNode->next) placeNode->next->prev = newNode;
                placeNode->next = newNode;

                // iii) now the freqMp will point to this newNode
                freqMp[newNode->freq] = newNode;

                // don't forget this
                if(placeNode==tail) tail=newNode;

            }
        }
    }

    void removeNode(Node* node, unordered_map<int, Node*>& freqMp)
    {
        if (node == NULL) return;

        auto it = freqMp.find(node->freq);

        // Update freqMp only if node is the last node for its frequency
        if (it != freqMp.end() && it->second == node)
        {
            
            if (node->prev && node->prev->freq == node->freq)
            {
                // if it's not the last node the move the freq pointer back
                freqMp[node->freq] = node->prev;
            }
            else
            {
                // if it's the last node then remove it
                freqMp.erase(node->freq);
            }
        }

        // Remove node from the DLL
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;

        node->prev = node->next = NULL;
    }

};

class LFUCache
{
public:
    DLL doublyLL;
    unordered_map<int, Node*> freqMp; // (freq, whichNode)
    unordered_map<int, Node*> valMp; // (key, whichNode)
    int size;

    LFUCache(int capacity)
    {
        this->size = capacity;
    }

    int get(int key)
    {
        if(valMp.find(key)!=valMp.end())
        {
            // jo read ho gya h usko remove kero
            doublyLL.removeNode(valMp[key], freqMp);

            // and then freq increase kerke, reinsert kro
            valMp[key]->freq++;
            doublyLL.addNode(valMp[key], freqMp);

            cout << doublyLL.head->key << " " << doublyLL.tail->key << endl;
 
            return valMp[key]->value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        // if key already resent h to 
        if(valMp.find(key)!=valMp.end())
        {
            // val ko change krdo
            valMp[key]->value = value;

            // remove it
            doublyLL.removeNode(valMp[key], freqMp);

            // then increase the freq and push it again
            valMp[key]->freq++;
            doublyLL.addNode(valMp[key], freqMp);

            return;
        }

        // if key is not present and size is full
        if(valMp.size()>=size)
        {
            // first remove it from map
            valMp.erase(doublyLL.head->key);

            // then remove it form DoubleLL
            doublyLL.removeNode(doublyLL.head, freqMp);
        }

        // and at last we have to insert the new node
        Node* newNode = new Node(key, value);
        valMp[key] = newNode;
        doublyLL.addNode(newNode, freqMp);
    }
};

int main()
{

    return 0;
}