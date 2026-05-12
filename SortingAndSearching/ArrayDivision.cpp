#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int can_split(vector<int>&arr, long long target){

    int cnt=1;
    long long sum=0;

    for(int i=0;i<arr.size();i++){
        if(arr[i]>target)return INT_MAX;
        if(sum+arr[i]>target){
            cnt++;
            sum=(long long)arr[i];
        }
        else sum+=1LL*arr[i];
    }

    return cnt;
}

int main(){

    int n,k;cin>>n>>k;
    vector<int>arr(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=1LL*arr[i];
    }

    long long low=0,high=sum;

    while(low<=high){

        long long mid = low+(high-low)/2;

        if(can_split(arr,mid)<=k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<low<<endl;

    return 0;
}