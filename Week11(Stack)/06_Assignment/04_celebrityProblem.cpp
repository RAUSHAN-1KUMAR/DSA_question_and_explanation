/* GFG

A celebrity is someone who is known to everyone but does not know anyone. So, if you are a celebrity at a party, you will be known to everyone, but you won’t know anyone there.

Given a sqaure N x N binary matrix. So, every cell can either have a value of 0 or 1. If matrix[i][j] = 1, this means that the ith person knows the jth person.

You have to tell whether a celebrity is present at the party or not. If it is present, we also have to tell which element (person) is the celebrity.

Note: The elements of the diagonal, i.e., when i = j, are always set to 0.


Example:
    input: N=3(person), {0,1,0}
                        {0,0,0}
                        {0,1,0}
    output: 1
    Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity
*/

/*
Apprach:- 
1. Brute force
    -- ager koi banda celebrity h to uski row ki sarri elment zero hogi
    -- ager koi banda celebrity h, to uski coloumn ki sarri element one hogi except its row and diagonal elment
    -- So row nikal lengen ki kon se row pe saare element zero h, and then uss row ke liye coloumn check ker lenge
But this appraoch uses O(N^2) time.

2. better O(N) time:
    -- put all person in Stack
    -- stack fill kerne ke baad, phir stack ke uper se do element nikalengen: A and B
    -- then check krengen ki kya A, B ko janta h:
        (i) ager haa it means A is not celebrity:- discard A and B ko wapas push kerdo
        (ii) else, kya B A ko janhta h: if yes-> B ko discard kerdo, push A
    -- ye kaam kerte rahengen jab tak stack one size ka nhi ho jata;-
        (i) that single person might be celebrity, to is ek ke liye ham brute force apply kr lenge
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    //push all person into stack
    for(int i = 0; i<n ; i++)
    {
        st.push(i);
    }

    // now top se do do check kro
    while(st.size() != 1)
    {
        int a = st.top(); st.pop();

        int b = st.top(); st.pop();

        if(M[a][b])// ager 'a' 'b' ko janta h means 'a' is not celebrity kyunki celebrity kisi ko nhi janta
        {
            // so discard 'a' and push 'b'
            st.push(b);
        }
        else// ager 'a' 'b' ko nhi janta h means 'a' ho sakta h celebrity ho 
        {
            st.push(a);
        }
    }

    // last m jo element aya h usko bhi to confirm kerna h
    int mightBeCelebrity = st.top(); st.pop();

    // row checking
    for(int i=0 ; i<n ; i++)
    {
        if(M[mightBeCelebrity][i] != 0)
        {
            return -1;
        }
    }

    // column checking
    for(int i=0 ; i<n ; i++)
    {
        if(M[i][mightBeCelebrity]==0 && i!=mightBeCelebrity)
        {
            return -1;
        }
    }

    return mightBeCelebrity;
}

int main()
{
    vector<vector<int>> M = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int ans = celebrity(M, 3);

    cout << ans << endl;

    return 0;
}



