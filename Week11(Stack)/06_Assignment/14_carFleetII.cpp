/* -> 1776

There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [position(i), speed(i)] represents:
    - position(i) is the distance between the ith car and the beginning of the road in meters. It is guaranteed that position(i) < position(i+1).
    - speed(i) is the initial speed of the ith car in meters per second.

For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.

Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10^(-5) of the actual answers are accepted.



Example 1:
Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.


Example 2:
Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]

*/

/*
Appraoch:- 
    -- pichle question m hame target diya hua tha, aur jo car collide ker rhi thi, kitne second baad ye to nhi pata, wo phir ek fleet ban ja rhi thi.
    -- iss question m hame time nikalna h ki kitne second baad collide hoga, ager collide nhi hua to -1.

    How to find collision time:-
        - position is already sorted so no need to sort them just as we did in previous question by making Car class.
        - collide tabhi hoga jab uske aage wali gaadi slow chal rhi h, so sabse phele ye find krengen ki kya aage koi aisii car h jiski speed isse slow h
        - ham start krengen last car se:
            - let say do car [a,b] and [c,d] mil gyi, means b>d:
                => car collide ho sakti h
                => collideTime = (c-a)/(b-d)

        - point to be noted: ager koi ek car(a) apne aage wale car(b) se t1 time m collide hui h, and ek car(c) apne aage wale car(a) se t2 time m collide hui h:
            scene: c -> a -> b
                     t2   t1
            and t1>t2, it means pehle c se a ka collision ho rha h and then [ca]fleet b se collide ker rha next t1-t2 time m     

            Means hame ye bhi dhayan m rakhna hoga ki koi kam time wala collision hua h to wo ab ek fleet ban jayega, so uss fleet ka speed minimum speed of all car in that fleet. 

    How to apply stack:- O(n)
        --  ek time array hoga, and then cars array ke last se start krengen, ager wo kisi se collide nhi hoti to time(answer) wale array m uss respective index p -1:
        -- stack m fill ker rhe index, cars array ke last se, aur jab koi new index hoga to stack ke top index ko leke check krengen ki kya top index ki speed naye wale index ke speed se jyada ya equal h:
            (i) ager nhi to ham pop nhi krengen(because car ahead(stack ke top) of me(new index) is slower, so collision hoga)
                - so collisoin ka time nikal lengen aur time(answer) wale array m uss index ke liye fill kre denge only if current wala time is less than equal to current top wala time, 
                    - ager asa nhi h to stack se pop kerdo and then again ab jo top p h uske respective time nikal ke check kro
                - phir uske baad ab stack ke top p wo index push kerdo, aur time(answer) walle array m time ko
            (ii) ager haa to pop kerte jao stack, kyunki uss speed wale car se collide nhi hoga
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>>& cars)
{
    // -1 meanns no collision
    vector<double> answer(cars.size(), -1);

    stack<int> st;// index store krengen

    for(int i=cars.size()-1 ; i>=0 ; i--)
    {
        // ager stack ke top wali cars ki speed equal ya jyada h to collide nhi hoga pop kerdo
        while(!st.empty() && cars[st.top()][1] >= cars[i][1])
        {
            st.pop();
        }

        // jisse collision possible nhi tha wo to pop ho gya h, so ab collision time nikalengen,
        while(!st.empty())
        {
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);

            // colTime ko answer m store kerne se pehle usko check krengen top of the time se, kyunki ager curr colTime is less than or equal to top than it will definetely collide to car ahead of him or if curr colTime is greater then the time of top of stack it means curr car will collide its front car after the collition of its front cars 
            if(answer[st.top()]==-1 || colTime <= answer[st.top()])
            {
                answer[i] = colTime;
                break;//-> becuase car has collided
            }

            // ager colTime bada ho gya top wale time se
            st.pop();
            // after that while loop will again find the colTime for new top of stack
        }

        // stack m index ko push kerna h
        st.push(i);

    }

    return answer;
}


int main()
{
    vector<vector<int>> cars = {
        {3,4},
        {5,4},
        {6,3},
        {9,1}
    };

    vector<double> ans = getCollisionTimes(cars);

    for(double num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}