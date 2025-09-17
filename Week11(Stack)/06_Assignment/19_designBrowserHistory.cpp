/* -> 1472

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:
    - BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
    - void visit(string url) Visits url from the current page. It clears up all the forward history.
    - string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
    - string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.\


Eample:
Input: ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output: [null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"

*/

/*
Appraoch:- using stack
    -- new url h simple h ki push ker denge but back aur forward ko kaise sambhale using stack, linked list se to ho jayega but stack se kaise hoga,, aur jab user back gya and then koi new url diya to ab wo forward nhi ja skta, so isse bhi dhayan m rakhna h.
        -- to back ke history ko store kerne ke liye ek aur stack ka use ker lenge, and then jab forward kerna hoga to uss stack se new stack m fill ker denge, aur ager back aake new url m chale gye to uss stack ko empty ker denge.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class BrowserHistory
{
public:
    stack<string> browserStack;//-> main stack
    stack<string> forwardStack;//-> forward stack

    BrowserHistory(string homepage)
    {
        browserStack.push(homepage);
    }

    void visit(string url)
    {
        browserStack.push(url);
        // clear forward stack
        while(!forwardStack.empty()){
            forwardStack.pop();
        }
    }

    string back(int steps)
    {
        while (steps--)
        {
            if(browserStack.size()>1){
                forwardStack.push(browserStack.top());
                browserStack.pop();
            }
            else{ //-> only homepage is present
                break;
            }
        }

        return browserStack.top();
    }

    string forward(int steps)
    {
        while (steps--)
        {
            if(!forwardStack.empty()){
                browserStack.push(forwardStack.top());
                forwardStack.pop();
            }
            else{
                break;
            }
        }

        return browserStack.top();
    }
};



int main()
{

    return 0;
}