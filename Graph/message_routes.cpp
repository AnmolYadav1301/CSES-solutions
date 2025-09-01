#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool>visited(n);
    vector<int>parent(n,-1);
    parent[0]=-1;
    queue<pair<int,int>>q;
    q.push({0,1});
    visited[0]=true;
    int k;
    while(!q.empty()){
        int node=q.front().first;
        int ncmp=q.front().second;
        if(node==n-1){
            k=ncmp;
            break;
        }
        q.pop();
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                visited[nbr]=true;
                parent[nbr]=node;
                q.push({nbr,ncmp+1});
            }
        }
    }
    if(parent[n-1]==-1)cout<<"IMPOSSIBLE";
    else {
        cout<<k<<endl;
        int u=n-1;
        vector<int>v;
        while(parent[u]!=-1){
            v.push_back(u);
            u=parent[u];
        }
        v.push_back(u);
        for(int j=v.size()-1;j>=0;j--){
            cout<<v[j]+1<<" ";
        }
    }
    return 0;

}