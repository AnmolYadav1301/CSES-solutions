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
    
    map<long long,long long>prefix;
    long long cnt=0;
    prefix[0]=1;
    long long sum=0;
    for(int i=0;i<n;i++){

         sum+=1LL*v[i];
         if(prefix.find(sum-x)!=prefix.end()){
            cnt+=prefix[sum-x];
         }

         prefix[sum]++;

    }

    cout<<cnt<<endl;

    return 0;
}