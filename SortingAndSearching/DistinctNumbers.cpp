#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void merge(vector<int>&arr, int s, int mid, int e){

    vector<int>v;
    int ind1=s,ind2=mid+1;

    while(ind1<=mid && ind2<=e){
        if(arr[ind1]<=arr[ind2]){
            v.push_back(arr[ind1++]);
        }
        else v.push_back(arr[ind2++]);
    }

    while(ind1<=mid){
        v.push_back(arr[ind1++]);
    }
    while(ind2<=e){
        v.push_back(arr[ind2++]);
    }

    for(int x=0;x<v.size();x++){
        arr[s+x]=v[x];
    }
    return;
}

void mergesort(vector<int>&arr, int l,int r){

    if(l>=r){
        return;
    }

    int mid=l+(r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);

    merge(arr,l,mid,r);

}

int main(){

    int n;cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergesort(arr,0,arr.size()-1);

    int distinct=0;
    int last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]!=last){
            last=arr[i];
            distinct++;
        }
    }
    cout<<distinct<<'\n';
}