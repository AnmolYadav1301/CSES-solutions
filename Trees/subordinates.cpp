#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int v,vector<bool>&vis, stack<int>&topo,vector<vector<int>>&adj){

    vis[v]=true;
    topo.push(v);

    for(int nbr:adj[v]){
        if(!vis[nbr]){
            dfs(nbr,vis,topo,adj);
        }
    }


}

void print(vector<int>&v){
    for(auto val:v)cout<<val<<" ";
    cout<<endl;
}

int main(){

    int n;cin>>n;
    vector<vector<int>>adj(n);

    for(int i=1;i<=n-1;i++){
        int a;cin>>a;
        a--;
        adj[a].push_back(i);
    }

    stack<int>topo;
    vector<bool>vis(n,false);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,topo,adj);
        }
    }

    vector<int>dp(n);
    while(!topo.empty()){
        int u=topo.top();topo.pop();
        dp[u]+=adj[u].size();
        for(int v:adj[u]){
            dp[u]+=dp[v];
        }   
    }

    print(dp);

}