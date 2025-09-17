/*
upper bound-> returns a iterator which is pointing to the first element in a sorted array that is greater than a given target value
    i.e., given number se just bada wala number

    -- upper_bound() function return iterator not the direct element.

use cases:- upper_bound is used to find the first position after all occurences of the given value.

Iterator is basically a pointer.
*/

#include<bits/stdc++.h> 
#include<algorithm>// for upper bound function

using namespace std;

int main()
{
    vector<int> nums = {2,4,4,6,8,10,12};

    auto ans = upper_bound(nums.begin(), nums.end(), 4);

    // this will print the element
    cout << *ans << endl;

    // this will print the index of the element
    cout << (ans-nums.begin()) << endl;

    return 0;
}