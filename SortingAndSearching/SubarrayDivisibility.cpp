#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){

    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    map<int,int>prefix;
    long long sum=0,cnt=0;
    long long x=n;
    prefix[0]=1;
    for(int i=0;i<n;i++){
        sum+=1LL*arr[i];
        
        if(prefix.find((n+(sum%x))%x)!=prefix.end()){
            cnt+=prefix[(n+(sum%x))%x];
        }

        prefix[(n+(sum%x))%x]++;
    }

    cout<<cnt<<endl;
}