#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int diameter=0;
int dfs(int u,vector<vector<int>>&adj,vector<bool>&visited){

    if(adj[u].size()==0)return 0;
    // if(adj[u].size()==)
    // if(adj[u].size()==1 && adj[u][0])return 0;
    
    visited[u]=true;
    int max1=0,max2=0;
    for(int v:adj[u]){
        if(!visited[v]){
            int h=dfs(v,adj,visited);
            if(h>max1){
                max2=max1,max1=h;
            }
            else if(h>max2)max2=h;
        }
    }

    diameter=max(diameter,max1+max2);
    return 1+max1;

}

int main(){

    int n;cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<bool>visited(n,false);
    
    // visited[0]=true;
    dfs(0,adj,visited);

    cout<<diameter<<" ";

    return 0;
}