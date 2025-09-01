#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

void build_compressedGraph(vector<int>& kingdom, vector<vector<int>>& adj, vector<vector<int>>& Graph, int n){
    
    for(int u=0;u<n;u++){
        for(auto & v:adj[u]){
            if(kingdom[u]!=kingdom[v]){
                Graph[kingdom[u]].push_back(kingdom[v]);
            }
        }
    }
}

void dfs(vector<vector<int>>&adj,int vertex,int region, vector<bool>& visited, vector<int>&kingdom ){
    kingdom[vertex]=region;
    visited[vertex]=true;

    for(auto & nbr : adj[vertex]){
        if(!visited[nbr]){
            dfs(adj,nbr,region,visited,kingdom);
        }
    }
    
}

void topo_sort(vector<vector<int>>&adj,vector<bool>& vis, int vertex, stack<int>&topo){
    vis[vertex]=true;
   
    for(auto & nbr:adj[vertex]){
        if(!vis[nbr]){
            topo_sort(adj,vis,nbr,topo);
        }
    }
    topo.push(vertex);

}

int main(){

    int n,m;cin>>n>>m;
    vector<int>coinCollection;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        coinCollection.push_back(a);
    }

    vector<vector<int>>adj(n);
    vector<vector<int>>RevAdj(n);
    for(int i=0;i<m;i++){
        int home1,home2;cin>>home1>>home2;
        home1--,home2--;
        adj[home1].push_back(home2);
        RevAdj[home2].push_back(home1);
       
    }
    stack<int>topo;
    vector<bool>visited(n,false);
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            
            topo_sort(adj,visited,i,topo);
            // max_coins=max(max_coins,coins);
        }
    }

    for(int i=0;i<n;i++)visited[i]=false;
    vector<int>kingdom(n,-1);
    int i=0;
    while(!topo.empty()){
        int vertex=topo.top();topo.pop();
        if(!visited[vertex]){
            dfs(RevAdj,vertex,i,visited,kingdom);
            i++;
        }
        
    }

    vector<long long>coin_buffer(i);
    for(int j=0;j<n;j++){
        coin_buffer[kingdom[j]]+=(long long)coinCollection[j]; 
    }
    vector<vector<int>>Graph(i);
   
    build_compressedGraph(kingdom,adj,Graph,n);
        
    while(!topo.empty())topo.pop();//to reuse the same stack
    vector<long long>dp(i,0);
    vector<bool>vis(i,false);
    for(int j=0;j<i;j++){
        if(!vis[j]){
            topo_sort(Graph,vis,j,topo);
        }
    }

    long long int max_coins=LLONG_MIN;
    vector<int>v;
    while(!topo.empty()){v.push_back(topo.top());topo.pop();}
    while(!v.empty()){
        int node=v.back();v.pop_back();
        long long  maxAmongChild=0;
        for(auto child : Graph[node]){
            maxAmongChild=max(maxAmongChild,dp[child]);
        }
        dp[node]=coin_buffer[node]+maxAmongChild;
        max_coins=max(max_coins,dp[node]);
    }

    

    cout<<max_coins<<'\n';

    return 0;
}