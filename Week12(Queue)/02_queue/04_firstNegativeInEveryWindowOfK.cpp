/*
We have a given array and a integer k, we have to return first negetive number in every window size k in given array, if there is not negative number then return 0
*/

/*
Appraoch:- deque/queue + sliding window
    -- we are gonna store index of negative element in deque
    -- pehla window process kro aur usme jo negative aya tha uska index deque m store kerdo, and then her window ke baad deque ke first element(index) p jo value h wo uss window ka first negative number h,
    -- jab window ko slide krenge to anne wala number ager negative h to uska index deque m push kerdo aur piche se jo number hat rha h ager wo negative h to deque ko pop kerdo, kyunki wo uska index deque ke first p hoga.
*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> firstNegative(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    int startW=0;

    // processing first window
    for(int i=0 ; i<k ; i++)
    {
        int element = nums[i];
        if(element<0) dq.push_back(i);
    }
    
    // ab baki ka window-> removal and addition of index as per the upcoming and ongoing element
    for(int i=k ; i<nums.size() ; i++)
    {
        if(!dq.empty()){
            ans.push_back(nums[dq.front()]);// front of deque will be the negative number of current window
        }
        else{
            ans.push_back(0);
        }

        //removal
        if(nums[startW]<0){
            dq.pop_front();
        }
        startW++;

        // addition
        if(nums[i]<0){
            dq.push_back(i);
        }
    }

    // last wala window ka answer
    if(!dq.empty()){
        ans.push_back(nums[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,5,4,-1,2,0,5};

    vector<int> ans = firstNegative(nums, 3);

    for(int num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}