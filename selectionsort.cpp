#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n){
    for(int i=0;i<n;i++){
        int minsofar=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minsofar]){
                minsofar = j;
            }
        }
        swap(arr[i],arr[minsofar]);
    }
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter array elements: ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"Sorted array is: ";
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}