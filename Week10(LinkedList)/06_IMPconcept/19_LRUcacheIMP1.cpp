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
Approach:- Better approach using list
*/

#include<bits/stdc++.h>
using namespace std;

class LRUCache 
{
    int cap;
    list<int> dll; // front->
    unordered_map<int, pair<list<int>::iterator, int>> cache; // {key -> {node, value}}

    void mostTheKeyRecentlyUsed(int key)
    {
        dll.erase(cache[key].first); // delete the node

        dll.push_front(key); // push it into front

        cache[key].first = dll.begin(); // update the node address in map
    }

public:

    LRUCache(int capacity){
        this->cap = capacity;
    }
    
    int get(int key)
    {
        if(cache.find(key)==cache.end())
            return -1;
        
        mostTheKeyRecentlyUsed(key);

        return cache[key].second;
    }
    
    void put(int key, int value)
    {

        if(cache.find(key)!=cache.end())
        {
            cache[key].second = value; // update the value
            mostTheKeyRecentlyUsed(key);
        } else {
            dll.push_front(key); // insert the new key at front
            cache[key] = {dll.begin(), value}; // insert the new key in map
            cap--;
        }

        if(cap<0)
        {
            int lruKey = dll.back(); // get the lru key
            dll.pop_back(); // remove it from list
            cache.erase(lruKey); // remove it from map
            cap++;
        }
    }
};


int main()
{

    return 0;
}

