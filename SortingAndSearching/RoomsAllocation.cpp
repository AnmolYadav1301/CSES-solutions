#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void print(vector<int>&rooms){
    for(int & v:rooms)cout<<v<<" ";
}
int main(){

    int n;cin>>n;
    vector<pair<int,pair<int,int>>>arrivals;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        arrivals.push_back({a,{b,i}});
    }

    sort(arrivals.begin(),arrivals.end(),[](const auto& a, const auto& b){
        return a.first<b.first;
    });
    vector<int>rooms(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int i=0;
    for(auto & duration:arrivals){
        if(pq.empty()){
            pq.push({duration.second.first,++i});
            rooms[duration.second.second]=i;
        }
        else if(pq.top().first<duration.first){
            int room=pq.top().second;
            pq.pop();
            pq.push({duration.second.first,room});
            rooms[duration.second.second]=room;
        }
        else{
            pq.push({duration.second.first,++i});
            rooms[duration.second.second]=i;
        }
    }
    cout<<i<<'\n';
    print(rooms);

    return 0;
}