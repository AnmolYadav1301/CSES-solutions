#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
using namespace std;

// void isReachable(int vertex,vector<bool>&visited,vector<vector<int>>&adj){
//     visited[vertex]=true;
//     for(auto nbr:adj[vertex]){
//         if(!visited[nbr]){
//             isReachable(nbr,visited,adj);
//         }
//     }
// }

// long long int dfs(vector<vector<pair<int,int>>>&adj, int node,int discount,vector<vector<long long>>&dp,vector<bool>&to_dest){
    
//     if(node==(int)adj.size()-1){
//         return dp[node][discount]=0;
//     }
//     cout<<"hello"<<" ";
//     if(dp[node][discount]!=-1)return dp[node][discount];

//     long long disc_taken=LLONG_MAX,disc_nottaken=LLONG_MAX;
//     for(auto &nbr:adj[node]){
//         if(!to_dest[nbr.first])continue;
//         long long res1=dfs(adj, nbr.first, discount, dp,to_dest);
//         if(res1 != LLONG_MAX)disc_nottaken = min(disc_nottaken, nbr.second + res1);

//         if (discount == 0) {
//             long long res2=dfs(adj, nbr.first, 1, dp,to_dest);
//             if(res2!=LLONG_MAX)disc_taken = min(disc_taken, (nbr.second / 2)+res2);
//         }
        
//     }
//     cout<<"hello"<<" ";
//     return dp[node][discount]=min(disc_nottaken,disc_taken);

// }
// using ll=long long int;
void minDist_djikstra(vector<vector<pair<int,int>>>&adj,int src,vector<long long>&dist){
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    
    dist[src]=0;
    pq.push({0,src});
   
    while(!pq.empty()){
        auto curr_dist=pq.top().first;
        auto u=pq.top().second;
        pq.pop();

        if(curr_dist>dist[u])continue;

        for(auto &nbr:adj[u]){
            auto v=nbr.first,w=nbr.second;
            if(dist[v]>curr_dist+w){
                dist[v]=w+curr_dist;
                pq.push({dist[v],v});
            }
        }
    }
}
int main(){
    
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    vector<vector<pair<int,int>>>revAdj(n);
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
        revAdj[b-1].push_back({a-1,c});
        edges.push_back({a-1,b-1,c});
    }
    vector<long long>dist_from_src(n,LLONG_MAX);
    vector<long long>dist_from_end(n,LLONG_MAX);

    minDist_djikstra(adj,0,dist_from_src);
    minDist_djikstra(revAdj,n-1,dist_from_end);

    long long int discounted_cost=LLONG_MAX;
    for(auto &edge:edges){
        int u=edge[0],v=edge[1],w=edge[2];
        if(dist_from_src[u]!=LLONG_MAX && dist_from_end[v]!=LLONG_MAX)
            discounted_cost=min(discounted_cost,w/2+dist_from_src[u]+dist_from_end[v]);
    }

    cout<<discounted_cost<<endl; 
    

    return 0;
}