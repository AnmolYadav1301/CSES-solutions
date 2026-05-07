#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){

    int n;cin>>n;
    long long sum=0;
    int maxi=INT_MIN;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        maxi=max(maxi,v[i]);
    }
    sum-=maxi;
    if(maxi>=sum){
        cout<<2*maxi<<endl;
    }
    else cout<<sum+maxi<<endl;

    // sort(v.begin(),v.end());

    // int i=0,j=n-1;
    // long long cnt=0;
    // while(i<=j){
    //     long long sum=0;
    //     while(sum+v[i]<=v[j]){
    //         sum+=v[i++];
    //     }
    //     cnt+=max(sum,1LL*v[j--]);

    // }

    // cout<<cnt<<endl;

}