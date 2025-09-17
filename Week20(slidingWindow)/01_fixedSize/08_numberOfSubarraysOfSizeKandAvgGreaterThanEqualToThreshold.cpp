/* -> 1343

Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.


Example 1:
    Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
    Output: 3
    Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

Example 2:
    Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
    Output: 6
    Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int startWindow = 0;
    int endWindow = 0;

    int size = arr.size();
    int ans = 0;
    int sum = 0;

    while(endWindow<size)
    {
        // sum ko store kerte jao
        sum += arr[endWindow];

        // jab window size match ho jaye
        if(endWindow-startWindow+1==k)
        {
            // ager avg greater than or equal to threshold h to ans ++
            double floatK = k;
            double avg = sum/floatK;
            if(avg >= threshold) ans++;

            // increament of start window
            sum-=arr[startWindow];
            startWindow++;
        }

        endWindow++;
    }

    return ans;
}

int main()
{
    vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k = 3;
    int threshold = 5;

    cout << numOfSubarrays(arr, k, threshold) << endl;

    return 0;
}