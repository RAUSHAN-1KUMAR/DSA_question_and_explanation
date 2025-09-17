/* -> 632

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:
    Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    Output: [20,24]
    Explanation: 
    List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    List 2: [0, 9, 12, 20], 20 is in range [20,24].
    List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
    Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
    Output: [1,1]
*/

/*
Approach:- similar to the previous question
    -- we are gonna take front element from each of the list into my minHeap, and we are gonna take min from that heap and also find max from that heap that will be our one of the range.

    We can get min from minHeap but how to get max:
        -- at the time of creating heap we will take a variable to which we are gonna save the max element, and if the upcomming element is greater than max then we would replace it.

Note:- we can also solve it using maxHeap as well:

TC:- O((n*k)*logk)
SC:- O(k)

Lets solve it by implimenting minHeap also -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

class info{
public:
    int data;
    int rowIndex;
    int colIndex;

    info(int a, int b, int c){
        this->data=a;
        this->rowIndex=b;
        this->colIndex=c;
    }
};

class comparator
{
public:
    bool operator()(info* a, info* b)
    {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) 
{
    vector<int> ans(2);
    int diff = INT_MAX;
    int maxi = INT_MIN;

    // Step1: create min heap
    priority_queue<info*, vector<info*>, comparator> pq;

    // Step2: insert first k element from each of the list, along with it save the max element in maxi variable
    for(int row = 0 ; row<nums.size() ; row++)
    {
        int data = nums[row][0];
        info* temp = new info(data, row, 0);
        pq.push(temp);

        // update maxi if updatable
        if(data>maxi) maxi = data;
    }


    // Step3: now lets begin to solve our solution
    while(!pq.empty())
    {
        info* front = pq.top();
        pq.pop();

        int data = front->data;//-> current min element and max is maxi
        int rowIndex = front->rowIndex;
        int colIndex = front->colIndex;

        // update the ans vector if we got a less diff range
        if(maxi-data < diff)
        {
            ans[0] = data;
            ans[1] = maxi;

            // don't forget this, we also update the diff so that we can compare it again with others max and min pair
            diff = maxi-data;
        }

        // now updating the heap
        int arraySize = nums[rowIndex].size();
        if(colIndex+1 >= arraySize)
            break; //-> catch
        else{
            int nextData = nums[rowIndex][colIndex+1];
            if(nextData>maxi) maxi = nextData;//-> don't forget this also, while inserting the data if it is greater than maxi than update maxi
            info* newTemp = new info(nextData, rowIndex, colIndex+1);
            pq.push(newTemp);
        }

        // necessaray for deallocation
        delete front;
    }

    return ans;
}


int main()
{
    vector<vector<int>> nums = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    vector<int> ans = smallestRange(nums);

    for(int num:ans)
        cout << num << " ";
    cout << endl;

    return 0;
}

