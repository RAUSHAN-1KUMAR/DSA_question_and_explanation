/* -> 632
Implementing minHeap for this question and then solving it
*/


#include<bits/stdc++.h>
using namespace std;


// we need this because each node in heap containing data, row, col
class node
{
public:
    int element;
    int rowIndex;
    int colIndex;

    node(){}

    node(int a, int b, int c){
        this->element=a;
        this->rowIndex=b;
        this->colIndex=c;
    }

    ~node()
    {
        cout << "DTOR called for: " << this->element << endl;
    }
};

// minHeap implementation
class MinHeap
{
public:
    vector<node*> hp={};
    int size=0;

    MinHeap(){}

    void pushNode(node* val)
    {
        // push and increment the size
        size++;
        hp.push_back(val);

        // heapification(bottom-up)
        int index=size-1;
        while(index>0)
        {
            int parentIndex = (index-1)/2;
            if(hp[index]->element < hp[parentIndex]->element)
            {
                swap(hp[index], hp[parentIndex]);
                index = parentIndex;
            }
            else
                break;
        }
    }

    void popNode()
    {
        if(size==0)
        {
            cout << "Heap underflow" << endl;
            return;
        }

        //-> replaced the top element with the last element;
        hp[0]=hp[size-1];
        size--;

        hp.pop_back();//-> the very important thing to do, incase of vector

        // heapification(top-down)
        int index=0;
        while(index<size)
        {
            int leftChild = 2*index+1;
            int rightChild = 2*index+2;

            int smallestIndex = index;

            if(leftChild<size && hp[leftChild]->element < hp[smallestIndex]->element)
                smallestIndex = leftChild;

            if(rightChild<size && hp[rightChild]->element < hp[smallestIndex]->element)
                smallestIndex = rightChild;

            if(index == smallestIndex) break;
            else{
                swap(hp[index], hp[smallestIndex]);
                index = smallestIndex;
            }
        }
    }

    node* frontNode()
    {
        if(size==0)
        {
            cout << "No element" << endl;
            return NULL;
        }

        return hp[0];
    }

    bool empty()
    {
        if(size==0) return true;
        else return false;
    }

    void print()
    {
        for(int i=0 ; i<size ; i++)
        {
            cout << "Data: " << hp[i]->element << " row: " << hp[i]->rowIndex << " and columns: " << hp[i]->colIndex << endl;
        }
    }
};


// solution starts
vector<int> smallestRange(vector<vector<int>>& nums) 
{
    vector<int> ans(2);
    int diff = INT_MAX;
    int maxi = INT_MIN;

    // created own minHeap
    MinHeap pq;

    for(int row = 0 ; row<nums.size() ; row++)
    {
        int data = nums[row][0];
        node* temp = new node(data, row, 0);
        pq.pushNode(temp);
        
        if(data>maxi) maxi = data;
    }

    
    while(!pq.empty())
    {
        node* front = pq.frontNode();
        pq.popNode();

        int mini = front->element;
        int rowIndex = front->rowIndex;
        int colIndex = front->colIndex;


        if(maxi-mini < diff)
        {
            ans[0] = mini;
            ans[1] = maxi;


            diff = maxi-mini;
        }

    
        int arraySize = nums[rowIndex].size();
        if(colIndex+1 >= arraySize)
            break;
        else{
            int nextData = nums[rowIndex][colIndex+1];
            if(nextData>maxi) maxi = nextData;
            node* newTemp = new node(nextData, rowIndex, colIndex+1);
            pq.pushNode(newTemp);
        }

        delete front;
    }

    return ans;
}


int main()
{
    vector<vector<int>> nums = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    vector<int> ans = smallestRange(nums);

    for(int num:ans)
        cout << num << " ";
    cout << endl;

    return 0;
}

