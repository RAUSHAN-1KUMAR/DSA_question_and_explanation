/* -> 621

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label due to cooling time.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:
    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

    After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.


Example 2:
    Input: tasks = ["A","C","A","B","D","B"], n = 1
    Output: 6
    Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

    With a cooling interval of 1, you can repeat a task after just one other task.


Example 3:
    Input: tasks = ["A","A","A", "B","B","B"], n = 3
    Output: 10
    Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

    There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

*/


/*
Approach:- 
    1. Greedy approach:- (preference-> maxFreq character)
        -- placing the max freq character first can only give us minimum number of CPU intervals with placing all tasks

        -- first take out the max Freq character and then place it by giving gap of n intervals,

        -- after this, the idlespot and gap will be 
            -> idleSpot = (maxFreq-1)*2 and gap = maxFreq-1

        -- and now we will try to fill the next character in this idleSpots. we will fill the gap in such a way that each gap will take one character, after placing, it is sure that idleSpot will be reduced 
            -> idleSpot = idleSpot-min(gap, freqOfChar); //-> min(gap, freqOfchar) because we are filling the idleSpot w.r.t gap so that each task should wait n intervals

        -- if at last:
            i) idleSpot > 0, return (n+idleSpot), means we got some idleSpot where there is no task has been done
            i) idleSpot <= 0, return n(size of tasks), means we were able to arrange the task within its size only

        But in actual we are not placing the character anywhere, we just took the understanding by using placing concept, we just have to do the operations

        TC:- O(n)
        SC:- O(1)

    2. Using Heap:-
        -- Next solution
*/

#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) 
{
    // storing the freq of each character
    vector<int> mp(26,0);
    for(char &ch:tasks) //-> O(N)
    {
        mp[ch-'A']++;
    }

    // ascending order, the maxFreq will be at the end
    sort(mp.begin(), mp.end()); //-> eventually O(1)

    // first place the most freq char
    int maxFreq = mp[25];

    //after placing 
    int gap=maxFreq-1;// we get the number of gap or gaddha
    int idleSlots=gap*n;// and total number of idleslots

    // now placing others
    for(int i=24 ; i>=0 ; i--)//-> starting from next maxFreq Char
    {
        idleSlots = idleSlots - min(gap, mp[i]);
    }

    if(idleSlots > 0)// means we have some idle slots where there is no task is done
        return tasks.size()+idleSlots;

    // if idleSlots is <= 0 it means task are done within its size
    return tasks.size();
}


int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'A', 'B', 'C', 'D', 'G'};
    int n=1;

    cout << leastInterval(tasks, n) << endl;

    return 0;
}

