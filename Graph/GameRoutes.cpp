#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
const int mod=1e9 + 7;
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

    
    vector<long long>ways(n,0);
    ways[0]=1;
    while(!topo.empty()){
        int u=topo.top();topo.pop();
        for(auto &nbr:adj[u]){

            ways[nbr]=(ways[nbr]+ways[u])%mod;
               
        }
    }
    cout<<ways[n-1];


    return 0;
}
