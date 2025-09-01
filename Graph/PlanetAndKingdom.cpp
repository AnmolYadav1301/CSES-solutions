//Two planets a and b belong to the same kingdom exactly when there is a route both from a to b and from b to a.
//Definition of Strongly connected components

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>

using namespace std;

void dfs(int vertex, vector<bool>&visited, vector<vector<int>>& adj, int region, vector<int>&Kingdom){
    visited[vertex]=true;
    Kingdom[vertex]=region;
    for(auto & nbr:adj[vertex]){
        if(!visited[nbr]){
            dfs(nbr,visited,adj,region,Kingdom);
        }
    }
    
}

void topo_sort(int vertex, vector<bool>&visited, stack<int>&topo, vector<vector<int>>& adj){
    visited[vertex]=true;
    for(auto & nbr:adj[vertex]){
        if(!visited[nbr]){
            topo_sort(nbr,visited,topo,adj);
        }
    }
    topo.push(vertex);
}
int main(){

    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n),revAdj(n);

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    stack<int>topo;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topo_sort(i,visited,topo,adj);
        }
    }

    vector<bool>seen(n,false);
    vector<int>Kingdom(n);
    int i=0;
    while(!topo.empty()){
        int val=topo.top();topo.pop();
        if(!seen[val]){
            i++;
            // v.push_back(val);
            dfs(val,seen,revAdj,i,Kingdom);
        }
    }

    cout<<i<<'\n';
    for(int & v:Kingdom)cout<<v<<' ';
    return 0;
}