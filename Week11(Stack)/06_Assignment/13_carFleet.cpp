/* -> 853

There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

 

Example 1:
Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation: The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.


Example 2:
Input: target = 10, position = [3], speed = [3]
Output: 1
Explanation:There is only one car, hence there is only one fleet.


Example 3:
Input: target = 100, position = [0,2,4], speed = [4,2,1]
Output: 1
Explanation:The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

*/

/*
Appraoch:- intuition based question
    -- sort the positions, and speed will be corresponding to that position 
    -- ek new array(time) banao jo store krega akela ka total time to reach at target
    
    Logic:- koi car tabhi kisi se milega jab uske aage wala car slow chal rha ho means aage wala car jyada time le rha ho ya same time le rha ho
        -- time wale array m, her elment p jake uske aage jo usse jyada time le rha h usko dhundhengen
            (i) ya to two for loop use kerle-> O(n^2)
            (ii) stack -> O(n)
        -- ager nhi mila to single fleet hogi
        -- ager mil gya to wo sab ek fleet hogi

    How stack:
        -- stack m fill kerte jao, ager aane wala time usse jyada h to wo sab ek fleet hongen, to top ko pop kerke new jyada wala time push kerdo
        -- last m stack m jitne elements bachengen utne no. of fleet is the answer i.e., size of the stack
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// we will sort our position array so to also maintain its speed we are gonna use class ( we can also use vector of pairs)
class Car
{
public:
    int pos, speed;

    Car(int p, int s):pos(p),speed(s){}
};

static bool myComp(Car &a, Car &b)
{
    return a.pos < b.pos;
}

int carFleet(int target, vector<int>& position, vector<int>& speed)
{
    vector<Car> cars;
    for(int i=0 ; i<position.size() ; i++)
    {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }

    // sort
    sort(cars.begin(), cars.end(), myComp);

    stack<float> st; // time float bhi nikal sakta h, issiliye float type
    
    for(auto car:cars)
    {
        float time = (target-car.pos)/((float)car.speed);

        // stack ke top aur aane wala time
        while(!st.empty() && time >= st.top())
        {
            st.pop();
        }
        st.push(time);
    }

    return st.size();
}


int main()
{
    vector<int> positions = {10,8,0,5,3};
    vector<int> speeds = {2,4,1,1,3};
    int target = 12;

    int ans = carFleet(target, positions, speeds);

    cout << ans << endl;

    return 0;
}