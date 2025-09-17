/* -> 735

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/

/*
Appraoch:- 
    -- stack m right move ker rhe element(i.e., posetive element) ko push kerte jao,
        -- jaise hi koi left move ker rha element(i.e., negative element) aya, to usko top se compare krdo, jiska magnitude bada hoga wo top p rahega
        -- top update hone ke baad again check hoga ki kya ye ab next top se collide hoga: ager haa to kerdo
    
    Logic:
        (i) positive push
        (ii) negative h to compare kero top se
            1. top pe posetive h-> collide
            2. top pe negative h-> no collision -> push
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    stack<int> st;

    for(auto ast:asteroids)
    {
        bool destroy = false;// initally nothing is destroyed;

        // posetive h to push kerdo
        if(ast>0){
            st.push(ast);
        }
        else{ // negative h to two cases for top
            if(st.empty() || st.top()<0){
                st.push(ast);
            }
            else{
                while (!st.empty() && st.top()>0)
                {
                    // jab dono ke mag. same h to ast destroy and top bhi pop
                    if(abs(ast)==st.top()){
                        destroy = true;
                        st.pop();
                        break;
                    }
                    else if(abs(ast)>st.top()){// jab ast ka mag. bada h to wo top ko phod dega
                        st.pop();
                    }
                    else{// jab anne wala ast ka magnitude chota h top se to bas ast destroy hoga
                        destroy = true;
                        break;
                    }

                }

                if(!destroy) st.push(ast);
            }
        }
    }

    // storing ans
    vector<int> ans(st.size());
    for(int i = st.size()-1 ; i>=0 ; i--)
    {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}


int main()
{
    vector<int> asteroids = {10,2,-5};

    vector<int> ans = asteroidCollision(asteroids);

    for(int num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



