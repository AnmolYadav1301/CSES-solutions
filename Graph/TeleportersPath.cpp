#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;

void findEulerPath(vector<int>&path, vector<multiset<int>>& Graph,int start){

    stack<int>st;
    st.push(start);
    while(!st.empty()){
        int u=st.top();
        if(!Graph[u].empty()){
            int v = * Graph[u].begin();
            Graph[u].erase(Graph[u].begin());
            st.push(v);
        }
        else{
            path.push_back(st.top());
            st.pop();
        }
    }
    reverse(path.begin(),path.end());

}
void dfs(vector<vector<int>>&adj, vector<bool>& visited, int vertex , stack<int>&topo){
    
    visited[vertex]=true;
    for(auto & nbr: adj[vertex]){
        if(!visited[nbr]){
            dfs(adj,visited,nbr,topo);
        }
    }
    topo.push(vertex);
}

void dfs2(vector<vector<int>>&adj,int vertex,vector<bool>&visited){
    visited[vertex]=true;

    for(auto & nbr:adj[vertex]){
        dfs2(adj,nbr,visited);
    }
}
bool checkSCC(vector<vector<int>>&adj,stack<int>& topo){

    int count=0;
    vector<bool>visited(adj.size(),false);
    while(!topo.empty()){
        if(!visited[topo.top()]){
            count++;
            dfs2(adj,topo.top(),visited);
        }
        if(count>1)return false;
        topo.pop();
    }
    return true;
    
}
int main(){

    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n),revAdj(n);
    vector<int>indegree(n),outdegree(n);
    vector<multiset<int>>Graph(n);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        indegree[v]++,outdegree[u]++;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
        Graph[u].insert(v);
    }

    bool isEulerPath=true;  // let's assume there exists a path
    if(indegree[n-1]-outdegree[n-1]!=1)isEulerPath=false;
    if(outdegree[0]-indegree[0]!=1)isEulerPath=false;
    if(isEulerPath){
        for(int i=1;i<n-1;i++){
            if(indegree[i]!=outdegree[i]){
                isEulerPath=false;
                break;
            }
        }
    }

    // fully strongly connected test not req just check from start node all the nodes having indegree>0 is reachable or not 
    // yet here there was no need 
    // if(isEulerPath){
    //     stack<int>topo;
    //     vector<bool>seen(n,false);
    //     dfs(adj,seen,0,topo);
    //     if(!checkSCC(revAdj,topo))isEulerPath=false;
    // }

    if(!isEulerPath){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int>path;
        findEulerPath(path,Graph,0);
        if((int)path.size()!=m+1){
            cout<<"IMPOSSIBLE\n";

        }
        else{
            for(auto level:path)cout<<level+1<<" ";
            cout<<'\n';
        }

    }




    return 0;
}