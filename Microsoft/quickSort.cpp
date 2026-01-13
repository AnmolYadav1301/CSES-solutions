#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pivot(vector<int>&arr,int low, int high){

    int p=high;
    int i=low-1;
    for(int j=low;j<=high;j++){
        if(arr[j]<arr[p]){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[p]);
    return i+1;
    
}
void quickSort(vector<int>&arr,int low, int high){

    if(low>=high)return;
    int mid=pivot(arr,low,high);
    quickSort(arr,low,mid-1);
    quickSort(arr,mid+1,high);

    
}

void print(vector<int>&arr){
    for(int &val:arr)cout<<val<<" ";
}
int main(){

    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    quickSort(arr,0,n-1);
    print(arr);
}