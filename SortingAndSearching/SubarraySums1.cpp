#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

// code fine for both subarray sum 1 and subarray sum 2...and hashmap prone to collision
int main(){

    int n;cin>>n;
    long long x;cin>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    long long cnt=0;
    
    long long sum=0;
    int i=0,j=0;
    while(j<n){
         sum+=1LL*v[j++];         
         while(sum>x)sum-=v[i++];
         if(sum==x)cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}