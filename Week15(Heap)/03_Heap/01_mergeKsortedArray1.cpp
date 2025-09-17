/*
Given sorted k array, merge them to form single sorted array
*/

/*
Approach:- Dynamic memory allocation
    - Logic is same

    TC:- O((n*k)*logk)
    SC:- O(k)

Would you like to try this using mergeSort:- see next solution
*/

#include<bits/stdc++.h>
using namespace std;

class info{
public:
    int data;
    int rowIndex;
    int colIndex;

    info(int a, int b, int c){
        this->data=a;
        this->rowIndex=b;
        this->colIndex=c;
    }
};


class comparator
{
public:
    // Change1:
    bool operator()(info* a, info* b)
    {
        return a->data > b->data;
    }
};


void mergeKSortArrays(int arr[][4], int n, int k, vector<int> &ans)
{
    // Change2: for dynamic allocation we need pointer
    priority_queue<info*, vector<info*>, comparator> pq;

    for(int row=0; row<k; row++) //-> O(k)
    {
        int element = arr[row][0];
        // Change3: pointer
        info* temp = new info(element, row, 0);
        pq.push(temp);
    }

    while(!pq.empty()) //-> O(n*k*logk)
    {
        // Change4: pointer
        info* temp = pq.top();
        pq.pop();

        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        ans.push_back(topData);

        if(topCol+1 < n)
        {
            // Change5: pointer
            info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
            pq.push(newInfo);
        }

        // important Change6
        delete temp;
    }
}


int main()
{
    int arr[3][4] = {
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };

    int n=4;
    int k=3;

    vector<int> ans;

    mergeKSortArrays(arr, n, k, ans);

    cout << "Printing answer array: " << endl;

    for(int i=0 ; i<ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

