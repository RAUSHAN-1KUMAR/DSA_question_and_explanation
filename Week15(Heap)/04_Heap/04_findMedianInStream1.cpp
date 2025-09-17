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
Appoach:- using minHeap and maxHeap both
    -- the will be comming, i.e., for the stream, we make one half as maxHeap and other half as minHeap, and then we will use the top of them
        Ex:- stream-> 2,4,5,3,0,1,6,18,12

         1. at any instance-> 0, 1, 2,  3, 4, 5
                              maxHeap   minHeap
            
            median will be -> (topOfMaxHeap(2) + topOfminHeap(3))/ 2

         2. at any instance-> 0, 2, 3,  4, 5
                              maxHeap   minHeap

            median will be -> topOfmaxHeap(3);

         2. at any instance-> 0, 1, 2,  3, 4, 5, 6
                              maxHeap   minHeap

            median will be -> topOfminHeap(3);

    we have to insert the upcomming data carefully -> look in code

    TC:- o(nlogn)
    SC:- O(n)
*/

#include<bits/stdc++.h>
using namespace  std;

class MedianFinder
{
public:
    priority_queue<int> maxHeap;//-> first half
    priority_queue<int, vector<int>, greater<int>> minHeap;//-> second half

    MedianFinder(){}
    
    void addNum(int num)
    {
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }

        int topOfMax = maxHeap.top();

        if(num<=topOfMax)
            maxHeap.push(num);
        else //(num>topOfMax)
            minHeap.push(num);

        // now move the top on the basis of size
        if(maxHeap.size()+2==minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(minHeap.size()+2==maxHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian()
    {
        int sizeMax = maxHeap.size();
        int sizeMin = minHeap.size();

        // taking out the top of both the half
        double data1 = maxHeap.top();
        double data2;
        if(!minHeap.empty())
            data2 = minHeap.top();

        double result;

        if(sizeMax==sizeMin)
            result = (data1+data2)/2;
        else if(sizeMax>sizeMin)
            result = data1;
        else
            result = data2;
        
        return result;
    }
};


int main() 
{

    return 0;
}

