#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int dfs(vector<int>&parent, vector<bool>&visited, vector<vector<int>>&adj,int vertex,int father,vector<bool>&recStack){

    parent[vertex]=father;
    visited[vertex]=true;
    recStack[vertex]=true;
    int isCycle=-1;

    for(auto &nbr : adj[vertex]){
        if(!visited[nbr]){
            isCycle=dfs(parent,visited,adj,nbr,vertex, recStack);

            if(isCycle!=-1)return isCycle;
        }
        else if(recStack[nbr]){
            parent[nbr]=vertex;
            return nbr;
        }
    }
    
    recStack[vertex]=false;
    return -1;

}

void retrieve_cycle(vector<int>&ans,vector<int>&parent,int u){
    for(int v=u; ; v=parent[v]){
        ans.push_back(v);
        if(ans.size()>1 && v==u){
            break;
        }
    }
}

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    
    int cycle_Node=-1;
    vector<bool>visited(n,false);
    vector<bool>recStack(n,false);
    vector<int>parent(n,-1);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            cycle_Node=dfs(parent,visited,adj,i,-1,recStack);
            if(cycle_Node!=-1){
                break;
            }
        }
    }

    if(cycle_Node==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>ans;
        // cout<<"POSSIBLE"<<endl;
        // cout<<cycle_Node;
        // int temp = cycle_Node;
        // vector<bool> mark(n, false);
        // while (!mark[temp]) {
        //     mark[temp] = true;
        //     temp = parent[temp];
        // }
        // cycle_Node = temp;
        retrieve_cycle(ans,parent,cycle_Node);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--)cout<< ans[i]+1 <<" ";
    }

    return 0;
}