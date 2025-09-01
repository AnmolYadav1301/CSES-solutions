#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
void dfs(int vertex,vector<bool>&visited,vector<vector<int>>&adj){
    visited[vertex]=true;
    for(auto nbr:adj[vertex]){
        if(!visited[nbr]){
            dfs(nbr,visited,adj);
        }
    }
}
int main(){
    int n,m;cin>>n>>m;

    vector<vector<int>>edges;
    vector<vector<int>>adj(n); //adjacency list
    vector<vector<int>>revAdj(n);
    for(int i=0;i<m;i++){
        int a,b,x;cin>>a>>b>>x;
        edges.push_back({a-1,b-1,x});
        adj[a-1].push_back(b-1);
        revAdj[b-1].push_back(a-1);
    }

    vector<long long int>dist(n,LLONG_MIN);
    dist[0]=0;
    for(int i=1;i<n;i++){
        for(auto edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];

            if(dist[u]!=LLONG_MIN && dist[v]<dist[u]+w){
                dist[v]=dist[u]+w;
            }

        }
    }

    vector<bool>posCycNodes(n);//possible cycle node
    for(auto edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];

            if(dist[u]!=LLONG_MIN && dist[v]<dist[u]+w){
                posCycNodes[v]=true;
            }

    }
    vector<bool>from_src(n,false),to_dest(n,false);
    dfs(0,from_src,adj);
    dfs(n-1,to_dest,revAdj);

    bool infinite=false;
    for(int i=0;i<n;i++){
        if(posCycNodes[i] && from_src[i] && to_dest[i]){
            infinite=true;
            break;
        }

    }
    if(infinite)cout<<-1;
    else cout<<dist[n-1];

    return 0;
}
