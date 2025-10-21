#include<iostream>
#include<vector>

using namespace  std;

void merge(vector<int>&arr, int s, int mid, int e){

    vector<int>temp;
    int ind1=s,ind2=mid+1;
    while(ind1<=mid && ind2<=e){
        if(arr[ind1]<=arr[ind2]){
            temp.push_back(arr[ind1++]);
        }
        else temp.push_back(arr[ind2++]);
    }

    while(ind1<=mid)temp.push_back(arr[ind1++]);
    while(ind2<=e)temp.push_back(arr[ind2++]);

    for(int x=0;x<(int)temp.size();x++){
        arr[s+x]=temp[x];
    }

    return;
}

void mergeSort(vector<int>&wt, int s,int e){
    if(s>=e)return;

    int mid=s+(e-s)/2;
    mergeSort(wt,s,mid);
    mergeSort(wt,mid+1,e);
    merge(wt,s,mid,e);

    return;
}

int main(){

    int n,x;cin>>n>>x;
    vector<int>wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    mergeSort(wt,0,n-1);
    int count=0;
    int i=0,j=n-1;
    while(i<=j){
        if(wt[i]+wt[j]<=x){
            count++;
            i++,j--;
        }
        else if(wt[j]<=x){
            count++;
            j--;
        }
        else if(wt[i]<=x){
            count++,i++;
        }
        else break;

    }
    cout<<count<<endl;


    return 0;
}