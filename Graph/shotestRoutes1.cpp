#include<iostream>
#include <vector>
#include<queue>
#include<climits>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }
    vector<long long>dist(n,LLONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        long long w=pq.top().first;
        pq.pop();
        if (w > dist[u]) continue;

        for(auto & nbr:adj[u]){
            long long  curr_dist=w+nbr.second;
            int v=nbr.first;
            if(curr_dist<dist[v]){
                dist[v]=curr_dist;
                pq.push({curr_dist,v});
            }
        }
    }

    for(long long & len:dist){
        cout<<len<<" ";
    }
    cout<<endl;
    return 0;
}