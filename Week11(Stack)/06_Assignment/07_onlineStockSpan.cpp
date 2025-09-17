/* -> 901

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
    - For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
    - Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

Implement the StockSpanner class:
    - StockSpanner() Initializes the object of the class.
    - int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:
Input: ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output: [null, 1, 1, 1, 2, 1, 4, 6]
Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6

*/

/*
Approach:- O(n^2) brute force
    -- her ek element ko vector m push kerte jao aur her ek push ke baad two pointer appraoch piche se lagate hue count++ kerte jao

Note: O(n)-> see next solution
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class StockSpanner
{
public:
    vector<int> st;

    StockSpanner(){}

    int next(int price)
    {
        st.push_back(price);

        int i=st.size()-1;
        int j=i;
        int count=0;
        while (i>=0)
        {
            if(st[i]<=st[j]){
                count++;
            }
            else{
                break;
            }
            i--;
        }
        return count;
    }
};



int main()
{
    StockSpanner *obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl;
    cout << obj->next(85) << endl;
    return 0;
}