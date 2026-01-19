#include<iostream>
#include<set>
#include<queue>

using namespace std;

// long max(int &a, int &b){
//     return (a>b) ? a:b;
// }

bool ProductsMade(long Total_time,vector<int>&machineTime,int t){
    unsigned long cnt=0;
    for(int &time:machineTime){
        cnt+=(Total_time/(1LL*time));
        if(cnt>=1LL*t)return true;
    }
    return cnt>=1LL*t;
}

int main(){
    int n,t;cin>>n>>t;

    // it's time complexity is going to be O(t*log(n)) but t is 10^9 need to reduce
    // int cnt=0;
    // priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>>pq;
    // for(int i=0;i<n;i++){
    //     int k;cin>>k;
    //     pq.push({1LL*k,k});
    // }

    // long  min_time=0;
    // while(cnt<t){
    //     auto it=pq.top();
    //     pq.pop();cnt++;
    //     min_time=max(min_time,it.first);
    //     pq.push({1LL*it.first+it.second,it.second});
    // }
    // cout<<min_time<<endl;


    // if we can switch like O(nlog(t)) then it could work out
    // NOte: since we already aware about the range of answer + checking is easy-> b.s on answer
    vector<int>machines(n);
    for(int i=0;i<n;i++)cin>>machines[i];
    unsigned long low=0,high=10000000000000000000;
    unsigned long ans=0;
    while(low<=high){
        unsigned long mid=low+(high-low)/2;
        if(ProductsMade(mid,machines,t)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<ans<<endl;
    return 0;
    
}