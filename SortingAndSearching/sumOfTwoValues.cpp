#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,x;cin>>n>>x;
    // vector<int>arr(n);
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr.push_back({a,i+1});
    }
    sort(arr.begin(),arr.end());
    // int pos_first=-1,pos_second=-1;
    // unordered_map<int,int>mp;
    // for(int i=0;i<n;i++){
    //     if(mp.find(x-arr[i])!=mp.end()){
    //         pos_first=mp[x-arr[i]];
    //         pos_second=i;
    //         break;
    //     }
    //     mp[arr[i]]=i;
    // }

    // if(pos_first==-1)cout<<"IMPOSSIBLE";
    // else cout<<pos_first+1<<" "<<pos_second+1<<endl;

    int i=0,j=n-1;
    while(i<j){
        if((long long)(arr[i].first + arr[j].first)==1LL*x){
            break;
        }
        else if((long long )(arr[i].first + arr[j].first) < 1LL*x){
            i++;
        }
        else j--;
    }

    if(i>=j)cout<<"IMPOSSIBLE"<<endl;
    else cout<<arr[i].second<<" "<<arr[j].second<<endl;

    return 0;
}