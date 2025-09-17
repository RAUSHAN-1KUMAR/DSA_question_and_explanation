#include<bits/stdc++.h>
using namespace std;

class Heap
{  
public:
    int *arr;
    int capacity;// total size of arr
    int size;// current number of elements in heap

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    // max heap
    // TC-> O(logn)
    void insert(int val)
    {
        if(size==capacity)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        // Step1: size increase
        size++;

        // Step2: element ko heap m insert kerdo i.e., array ke last me insert kerdo
        arr[size]=val;

        // Step3: take that element into its correct position w.r.t max heap -> heapification
        int index=size;
        while (index>1) // we are indexing from 1 not 0
        {
            int parentIndex = index/2;
            if(arr[index]>arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // max heap
    // TC-> O(logn)
    int deleteNode()
    {
        if(size==0)
        {
            cout << "Heap underflow" << endl;
            return -1;
        }

        // root node at index 1
        int rootNode = arr[1];

        // Step1: root node ko last node se swap kro i.e., array ke first element ko last element se swap kerdo
        arr[1] = arr[size];
        size--;

        // Step2: now take that root node into its correct position w.r.t max heap -> heapification
        int index=1;// root node index
        while(index<size)
        {
            int leftChild = 2*index;
            int rightChild = 2*index+1;

            // finding index of parent aur uske child node m se kon sa maximum h
            int largestIndex = index;

            if(leftChild<=size && arr[leftChild]>arr[largestIndex])
                largestIndex = leftChild;

            if(rightChild<=size && arr[rightChild]>arr[largestIndex])
                largestIndex = rightChild;

            // no change in index
            if(index==largestIndex) break;
            else
            {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }

        return rootNode;
    }

    // What if i want to delete particular index node
    int deleteIndexNode(int i)
    {
        // replace the ith item to max value in case of maxHeap
        // or replace the ith item to -1 or min value in case of minHeap

        // pop that ith item to top of the heap, like heapification(bottom-up)

        // then call deleteNode() function, to delete to top(the item that you wanted to delete)

    }

    void printHeap()
    {
        for(int i=1 ;i<=size ; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Heap h(20);

    // insertion
    h.insert(10);
    h.insert(20);
    h.insert(5); 
    h.insert(11);
    h.insert(6);

    cout << "Printing the content of heap: " << endl;
    h.printHeap();

    cout << h.deleteNode() << endl;
    h.printHeap();

    return 0;
}