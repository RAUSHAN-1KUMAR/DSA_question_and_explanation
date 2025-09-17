/* 1823
There are N people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. 

Given the total number of persons N and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. The task is to choose the person in the initial circle that survives.

Examples:
    Input: N = 5 and k = 2
    Output: 3
    Explanation: 
    Firstly, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 1 is killed. 
    Finally, the person at position 5 is killed. So the person at position 3 survives. 


    Input: N = 7 and k = 3
    Output: 4
    Explanations: The persons at positions 3, 6, 2, 7, 5, and 1 are killed in order, and the person at position 4 survives.
*/

/*
Appraoch:- recursion
    - we are taking a boolean vector of size N, whose index will represent the person, and then we well mark True one by one with of k times
    - Steps on recursive call
        1. find the person to kill based on k
        2. kill that person
        3. find the next alive person

Time comp:- O(n^2)

Better solution-> next solution
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int winner(vector<bool> &person, int &n, int index, int person_left , int &k)
{
    // base case
    if(person_left==1)
    {
        for(int i=0 ; i<n; i++){
            if(person[i]==false)
                return i;
        }
    }

    // first we are finding, kon se person ko kill kerna h
    int kill = (k-1)%person_left; // what if k-1 is greater than 'n' Ok but why we have taken person_left instead of n, because if a person is already deleted than we are not counting it on rotation.

    // moving our index to kill that person
    while(kill)
    {   
        index = (index+1)%n; // mod n so that index value rotate if grater than or equal to n. 

        // if a person is already killed then index ko aage badha do
        while (person[index]==true)
        {
            index = (index+1)%n;
        }

        kill--;
    }

    // kill that person
    person[index] = true;

    // we have killed a person, now we have to find a person form where the next rotation starts
    while (person[index]==true)
    {
        index = (index+1)%n;
    }



    // resursive call
    int aageKaAnswer = winner(person, n, index, person_left-1, k);

    return aageKaAnswer;
}

int findTheWinner(int n, int k)
{
    vector<bool> person (n,false);

    return winner(person, n, 0, n, k)+1; // person, n, start_index, person_left, k 
}

int main()
{

    return 0;
}