#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){

    int n,k;cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    map<int,int>count;
    long long  cnt=0,distSoFar=0;
    int j=0,i=0;

    while(j<n){
        count[arr[j]]++;
        if(count[arr[j]]==1)distSoFar++;
        while(distSoFar>k){
            count[arr[i]]--;
            if(count[arr[i]]<1)distSoFar--;
            i++;
        }
        cnt+=1LL*(j-i+1);
        j++;
    }

    cout<<cnt<<endl;

    return 0;
}