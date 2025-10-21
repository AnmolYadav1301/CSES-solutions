#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    long int sum=0,max_sum=LLONG_MIN;
    for(int val:arr){
        sum+=val;
        max_sum=max(max_sum,sum);
        if(sum<0)sum=0;
    }
    cout<<max_sum<<endl;
}