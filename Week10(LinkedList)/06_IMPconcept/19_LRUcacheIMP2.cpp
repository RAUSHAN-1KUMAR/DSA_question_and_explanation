/* -> 146, medium++

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
    1. LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

    2. int get(int key) Return the value of the key if the key exists, otherwise return -1.

    3. void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
 

Example 1:
    Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output: [null, null, null, 1, null, -1, null, -1, 3, 4]
    Explanation:
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
*/

/*
Approach:- optimal approach using DLL
    -- Implementd DoubleLL to insert and remove the data in O(1) TC, no need of universal counter to give the preference we can just remove the head in case of removal
    -- used a doubly Linked list so that in case of removal and insertion we can do it in O(1) time, 
    -- used a map(key, node_pointer) to point the node in case of direct access by using the key
    -- if map size is same as size of cache, then remove head and its key form the map, why head-> because it is the LRU
    -- In case of accessing key, the remove it form map and then reinsert to the top of DLL using tail
*/

#include<bits/stdc++.h>
using namespace std;

// implementing doubly linked list
class Node
{
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL){}
};

class DLL
{
public:
    Node* head; //-> represent the least recently used node: to be removed when cache is full
    Node* tail; //-> represent the most recently used node

    DLL():head(NULL), tail(NULL){}

    void addNode(Node *node)
    {
        // new push
        if(head==NULL)
        {
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void removeNode(Node* node)
    {
        if(node==NULL) return;

        if(node->prev) node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;

        if(node==head) head = node->next;// if we are deleting the head
        if(node==tail) tail = node->prev;// if we are deleting the tail

        node->prev = node->next = NULL;
    }
};


class LRUCache {
public:
    DLL doublyLL;
    unordered_map<int, Node*> mp;
    int size = 0;

    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            int value = mp[key]->value;
            
            // jo read ho gya usko ab last me bhej do
            doublyLL.removeNode(mp[key]);
            doublyLL.addNode(mp[key]);

            return value;
        }

        return -1;    
    }
    
    void put(int key, int value)
    {
        // ager key already present h to 
        if(mp.find(key)!=mp.end())
        {
            // value ko update kerdo 
            mp[key]->value = value;

            // and also last me bhej do
            doublyLL.removeNode(mp[key] );
            doublyLL.addNode(mp[key]);

            return;
        }


        if(mp.size()>=size)// ager present nhi h and cache full h to delete the least recently used node(head)
        {
            // first remove it from map
            mp.erase(doublyLL.head->key);

            // then remove it from DoubleLL
            doublyLL.removeNode(doublyLL.head);

        }

        // and at last we have to insert the new node
        Node *newNode = new Node(key, value);
        doublyLL.addNode(newNode);
        mp[key] = newNode;
    }
};

int main()
{

    return 0;
}

