#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

const int mod=1e9 + 7;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);

    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }

    vector<bool>visited(n,false);
    priority_queue<pair<long long int,int>,vector<pair<long long int ,int>>,greater<pair<long long int,int>>>pq;
    pq.push({0,0});//dist from src , node, min routes, maximum routes
    vector<long long int>dist(n,LLONG_MAX);
    dist[0]=0;
    vector<long long int>ways(n,0);
    ways[0]=1;
    vector<int>max_step(n,0),min_step(n,0);
    max_step[0]=min_step[0]=0;
    while(!pq.empty()){
        long long int curr_dist=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(dist[u]<curr_dist)continue;
        

        for(auto & nbr:adj[u]){
            int v=nbr.first,w=nbr.second;
            if(dist[u]+w<dist[v]){
                ways[v]=ways[u];
                dist[v]=w+dist[u];
                pq.push({dist[v],v});
                max_step[v]=max_step[u]+1;
                min_step[v]=min_step[u]+1;
            }
            else if(dist[u]+w==dist[v]){
                ways[v]=(ways[v]+ways[u])%mod;
                max_step[v]=max(max_step[v],max_step[u]+1);
                min_step[v]=min(min_step[v],min_step[u]+1);
        
            }
        }

    }

    cout<<dist[n-1]<<" "<<ways[n-1]<<" "<<min_step[n-1]<<' '<<max_step[n-1];

    return 0;
}