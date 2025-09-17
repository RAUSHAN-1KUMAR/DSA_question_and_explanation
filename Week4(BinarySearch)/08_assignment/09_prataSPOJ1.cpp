/* Question name is PRATA - roti prata, taken from SPOJ website.

IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first 1R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

Input
In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.


Examples
    Input: P = 10, arr = {4 1 2 3 4}
    Output: 12

    Input: P = 8, arr = {1 1}
    Output: 36

    Input: P = 8, arr = {8 1 1 1 1 1 1 1 1}
    Output: 1
*/

/*
My practice code -> logic and implementation is same but little bit difference in code
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<int>cooksRanks, int nP, int mid)
{
    int parataCount = 0;

    for(int i=0 ; i<cooksRanks.size() ; i++)
    {
        int totalMin = 0;
        int currRank = cooksRanks[i];
        int j=1;
        
        while(totalMin+(j*currRank) <= mid){
            totalMin += j*currRank;
            j++;
            parataCount++;
            if(parataCount==nP) return true;
        }
    }

    return false;
}

int minTimeToCompleteOrder(vector<int> cooksRanks, int nP)
{
    int start = 0;
    int highestRanker = *max_element(cooksRanks.begin(), cooksRanks.end());

    int end = highestRanker * (nP * (nP+1))/2; // time taken by higher ranker cook to cook all prata

    int ans = -1;

    while(start<=end)
    {
        int mid = (start+end)/2;

        if(isPossibleSolution(cooksRanks,nP,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return ans;

}

int main()
{
    // int nP = 10;
    // int nC = 4;
    // vector<int> cooksRanks = {1,2,3,4};

    // cout << "Time taken: " << minTimeToCompleteOrder(cooksRanks, nP) << endl;
    
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while(T--)
    {
        int nP, nC;
        cout << "Enter total pratas and cooks: ";
        cin >> nP >> nC;

        vector<int> cooksRanks;

        cout << "Enter the ranks: ";
        while(nC--)
        {
            int R;
            cin >> R;
            cooksRanks.push_back(R);
        }

        cout << "Time taken : " << minTimeToCompleteOrder(cooksRanks, nP) << endl;
    }

    return 0;
}