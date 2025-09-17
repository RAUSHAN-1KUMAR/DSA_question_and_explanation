/* -> 1423

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 
Example 1:
    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
    Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12

Example 2:
    Input: cardPoints = [2,2,2], k = 2
    Output: 4
    Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:
    Input: cardPoints = [9,7,7,9,7,7,9], k = 7
    Output: 55
    Explanation: You have to take all the cards. Your score is the sum of points of all cards.
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
using namespace std;

int maxScore(vector<int>& cardPoint, int k)
{
    int size = cardPoint.size();

    // if the k is equal to the size of given array, then we just need to return the sum of all the element.
    if(size==k)
    {
        return accumulate(cardPoint.begin(), cardPoint.end(), 0);
    }

    int maxSum = 0;
    int sum=0;

    // setting up the first front k size sum
    int startWindow=0;
    while(startWindow<k) sum+=cardPoint[startWindow++];
    startWindow--;

    maxSum = max(maxSum, sum);

    // now, startWindow ke sum ko hatayengen aur last se add krenge
    int endWindow = size-1;
    while(endWindow >= size-k)
    {   
        sum-=cardPoint[startWindow];
        startWindow--;

        sum+=cardPoint[endWindow];

        maxSum = max(sum, maxSum);

        endWindow--;
    }
    
    return maxSum;
}

int main()
{
    vector<int> nums = {9,7,7,9,7,7,9};
    int k=7;

    cout << maxScore(nums, k) << endl;

    return 0;
}