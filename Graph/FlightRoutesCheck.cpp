#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>

using namespace std;

void dfs(int vertex, vector<bool>&visited, vector<vector<int>>& adj){
    visited[vertex]=true;
    for(auto & nbr:adj[vertex]){
        if(!visited[nbr]){
            dfs(nbr,visited,adj);
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
    vector<int>v;
    while(!topo.empty()){
        int val=topo.top();topo.pop();
        if(!seen[val]){
            v.push_back(val);
            if(v.size()>1)break;
            dfs(val,seen,revAdj);
        }
    }
    if(v.size()==2){
        cout<<"NO"<<'\n';
        cout<< v[1]+1 <<' '<< v[0]+1 <<endl;
    }
    else{
        cout<<"YES"<<'\n';
    }

    return 0;
}