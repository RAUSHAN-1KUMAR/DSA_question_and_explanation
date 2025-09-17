/*
Given an array of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:
    Input : N = 5, A[] = {-8, 2, 3, -6, 10}, K = 2
    Output : -8 0 -6 -6
    Explanation : First negative integer for each window of size k
    {-8, 2} = -8
    {2, 3} = 0 (does not contain a negative integer)
    {3, -6} = -6
    {-6, 10} = -6

    Input : N = 8, A[] = {12, -1, -7, 8, -15, 30, 16, 28}, K = 3
    Output : -1 -1 -7 -15 -15 0 
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> firstNegativeNumer(vector<int> &arr, int k)
{
    int startWindow = 0;
    int endWindow = 0;
    vector<int> ans;

    queue<int> qu;

    while (endWindow < arr.size())
    {
        // negative element ko qu m push krdo
        if(arr[endWindow]<0) qu.push(arr[endWindow]);

        // jaisehi window size k ke equal hua
        if(endWindow-startWindow+1==k)
        {
            if(qu.empty())
            {
                // qu empty h iska matlab uss window m koi bhi negative number nhi h
                ans.push_back(0);
            }
            else
            {
                // qu empty nhi h iska matlab uss window m negative numbers the. So, jo pehela negative number hoga wo queue ke front m hoga
                ans.push_back(qu.front());
            }

            // window ka size fix h to ab startWindow ko aage bhejo
            if(arr[startWindow]<0) qu.pop();// ager startWindwo wala element negative tha to qu ko pop kerdo kyunki wo ab window se bahar ho chuka h
            startWindow++;
        }
        
        // expansion of window
        endWindow++;
    }

    return ans;
}

int main()
{
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};
    int k = 3;

    vector<int> ans = firstNegativeNumer(arr, k);

    for(auto num:ans)
    {
        cout << num << " ";
    }

    return 0;
}