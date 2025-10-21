#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    long int sum=0;
    int median=arr[n/2];
    for(int val:arr){
        sum+=abs(median-val);
    }
    cout<<sum<<endl;
}