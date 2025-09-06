#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long unsigned int next_sum=1;
    for(int i=0;i<n;i++){
        if(arr[i]>next_sum)break;
        next_sum+=(long long int)arr[i];// it can compile with previous contigious all the sum leaving no gap
                                //to produce sum till [0,arr[i]+next_sum-1],so non producable sum would be next+=next+arr[i]
    }
    cout<<next_sum<<endl;


    return 0;
}