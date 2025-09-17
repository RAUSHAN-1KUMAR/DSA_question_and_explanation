/* -> 295

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
    - For example, for arr = [2,3,4], the median is 3.
    - For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:
    1. MedianFinder() initializes the MedianFinder object.
    2. void addNum(int num) adds the integer num from the data stream to the data structure.
    3. double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


Example 1:
    Input: ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"] => [[], [1], [2], [], [3], []]
    Output: [null, null, null, 1.5, null, 2.0]
    Explanation: 
    MedianFinder medianFinder = new MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0
*/

/*
Appoach:- Brute force -> using multiSet STL,
    -- insert the given data one by one into set, and then fetch the median

TC:- O(n(logn + n)) -> O(n^2) -> TLE
SC:- O(n)->set

Better solution: using heap-> next solution
*/

#include<bits/stdc++.h>
using namespace  std;

class MedianFinder {
public:
    multiset<int> mySet;

    MedianFinder(){}
    
    void addNum(int num) 
    {
        mySet.insert(num); //-> O(logn)
    }
    
    double findMedian() 
    {
        int size = mySet.size();
        if(size&1)// if size is odd
        {
            auto it = mySet.begin();
            advance(it, size/2); //-> O(size/2) -> O(n)
            return double(*it);
        }
        else // if size is even
        {
            auto it1=mySet.begin();
            auto it2=mySet.begin();

            advance(it1, (size-1)/2);
            advance(it2, size/2);

            double data = double(*it1+*it2)/2;

            return data;
        }
    }
};

int main() 
{

    return 0;
}