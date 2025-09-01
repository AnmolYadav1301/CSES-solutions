#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){

    int n,k;cin>>n>>k;
    vector<pair<int,int>>sch;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        sch.push_back({b,a});
    }

    sort(sch.begin(),sch.end());

    int count=0;

    // greedy + greedy 
    //i have to remove as maximum end time as i can corresponding to the given start time 
    //not the earliest ended one
    // so that u have a maximum flexibility available to watch that movie which have earliest start time 
    // if u remove the earliest end time u may reject this choice 
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    // for(int i=0;i<n;i++){
    //     cout<<sch[i].second<<" "<<sch[i].first<<'\n';
    //     while(!pq.empty() && pq.top().first<=sch[i].second)pq.pop();
    //     if((int)pq.size()<k){
    //         count++;
    //         pq.push(sch[i]);
    //     }
        
    // }

    multiset<int>end_time;
    for(int i=0;i<n;i++){
        
        auto it=end_time.upper_bound(sch[i].second);
        if(it!=end_time.begin()){
            it--;
            end_time.erase(it);
        }
        if(end_time.size()<k){
            count++;end_time.insert(sch[i].first);
        }
        
    }

    cout<<count<<'\n';

    return 0;


}

