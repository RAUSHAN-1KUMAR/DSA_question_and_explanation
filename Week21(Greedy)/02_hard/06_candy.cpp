/* -> 135

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:
    - Each child must have at least one candy.

    - Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:
    Input: ratings = [1,0,2]
    Output: 5
    Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
    Input: ratings = [1,2,2]
    Output: 4
    Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    The third child gets 1 candy because it satisfies the above two conditions.
*/

/*
Approach:-
1. Normal Approach
    -- We can use two arrays left and right.
    -- left[i] will store the number of candies needed if we consider only left side, and we are gonna fill the left array by traversing from left to right and checking if the current rating is greater than the previous rating, if yes then we will assign left[i] = left[i-1].
    -- right[i] will store the number of candies needed if we consider only right side and we are gonna fill the right array by traversing from right to left and checking if the current rating is greater than the next rating, if yes then we will assign right[i] = right[i+1].
    -- at last we will take the maximum of both sides for each child and sum them up to get the answer.

    TC: O(3n)
    SC: O(2n) for left and right arrays

2. Optimal approach: slope approach
    -- We can observe that the ratings can be divided into slopes, i.e., increasing and decreasing sequences.
    -- We can keep track of the length of the current increasing slope and the length of the current decreasing slope.
    -- When we encounter a peak (i.e., ratings[i] > ratings[i-1] and ratings[i] > ratings[i+1]), we can calculate the number of candies needed for the increasing slope and the decreasing slope.
    -- We need to ensure that the peak gets the maximum candies among its neighbors.
    -- We can use a variable to keep track of the previous slope length to handle cases where the peak is part of both an increasing and decreasing slope.

    TC: O(n)
    SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// normal approach
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n, 1); // candies needed if we consider only left side
    vector<int> right(n, 1); // candies needed if we consider only right side

    // fill left array
    for(int i=1 ; i<n ; i++)
    {
        if(ratings[i]>ratings[i-1])
            left[i] = left[i-1] + 1;
    }

    // fill right array
    for(int i=n-2 ; i>=0 ; i--)
    {
        if(ratings[i]>ratings[i+1])
            right[i] = right[i+1] + 1;
    }

    int ans = 0;
    for(int i=0 ; i<n ; i++)
        ans += max(left[i], right[i]); // take the maximum of both sides

    return ans;
}


// optimal approach
int candyOptimal(vector<int> &ratings)
{
    int n = ratings.size();
    if(n==0) return 0;

    int sum=0, i=1;

    while(i<n)
    {
        if(ratings[i]==ratings[i-1]){
            sum += 1;
            i++;
            continue;
        }

        int increasing=1;
        while(i<n && ratings[i]>ratings[i-1])
        {
            increasing++;
            sum += increasing;
            i++;
        }

        int decreasing=1;
        while (i<n && ratings[i]<ratings[i-1])
        {
            decreasing++;
            sum += decreasing;
            i++;
        }

        if(decreasing>increasing)
            sum += decreasing - increasing;
    }

    return sum;
}

int main()
{
    vector<int> ratings = {1,0,2};
    cout << candy(ratings) << endl;
    return 0;
}