/*
lower bound-> returns a iterator which is pointing to the first element in a sorted array that is greater than or equal to a given target value
    i.e., given number se just bada wala number ya phir equal wala number

    -- lower_bound() function return iterator not the direct element.

use cases:- lower_bound is used when you need the first position where a value could be inserted to maintain the sorted order or to find the first occurence of an element that is equal to or greater than the given value

Iterator is basically a pointer.
*/

#include<bits/stdc++.h> 
#include<algorithm>// for lower bound function

using namespace std;

int main()
{
    vector<int> nums = {0,0,10,10};

    auto ans = lower_bound(nums.begin(), nums.end(), 0);

    // this will print the element
    cout << *ans << endl;

    // this will print the index of the element
    cout << (ans-nums.begin()) << endl;

    return 0;
}

