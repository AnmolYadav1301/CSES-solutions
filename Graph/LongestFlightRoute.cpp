#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
void dfs(stack<int>&topo,vector<vector<int>>&adj,vector<bool>&visited,int u){
    visited[u]=true;
    for(auto &nbr:adj[u]){
        if(!visited[nbr]){
            dfs(topo,adj,visited,nbr);
        }
    }
    topo.push(u);
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    stack<int>topo;
    vector<bool>visited(n,false);
    dfs(topo,adj,visited,0);

    vector<long long>dist(n,LLONG_MIN);
    dist[0]=0;
    vector<int>parent(n,-1);
    while(!topo.empty()){
        int u=topo.top();topo.pop();
        for(auto &nbr:adj[u]){
            if(dist[u]+1>dist[nbr]){
                parent[nbr]=u;
                dist[nbr]=dist[u]+1;
            }
        }
    }
    if(dist[n-1]==LLONG_MIN){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<dist[n-1]+1<<endl;
        vector<int>ans;
        for(int x=n-1;;x=parent[x]){
            ans.push_back(x);
            if(x==0){
                break;
            }
        }
        for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]+1<<" ";
        cout<<endl;
    }



    return 0;
}
