     
// every element occurs twice except one.

#include<iostream>
#include<vector>
using namespace std;
 
int findUnique(vector<int> arr){
    int ans = 0;
    for(int i = 0 ; i<arr.size() ; i++){
        ans = ans^arr[i];
    }

    return ans;
}

int main()
{   
    int n ;
    cout << "Enter the size of array " << endl;
    cin >>n;

    vector<int > arr(n);
    cout << "enter the elements " << endl;

    for( int i = 0; i<arr.size() ; i++){
        cin >> arr[i];
    }

    int uniqEle = findUnique(arr);

    cout << "Unique element is " << uniqEle << endl;
    return 0;
}


