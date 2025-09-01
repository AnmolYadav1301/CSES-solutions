#include<iostream>
#include<vector>
using namespace std;
bool dfs(vector<bool>&visited,int vertex,vector<vector<int>>&adj,vector<int>&route,vector<int>&parent){

    visited[vertex]=true;
    
    for(auto nbr:adj[vertex]){
        if(!visited[nbr]){
            parent[nbr]=vertex;
            if(dfs(visited,nbr,adj,route,parent)){
                return true;
            }
        }
        else if(visited[nbr] && parent[vertex]!=nbr){
            route.push_back(nbr);
            int curr=vertex;
            while(parent[curr]!=nbr){
                route.push_back(curr);
                curr=parent[curr];
            }
            route.push_back(curr);
            route.push_back(nbr);
            return true;
        }
        
    }
    
    return false;

}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    vector<bool>visited(n,false);
    vector<int>parent(n,-1);
    bool temp=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int>v;
            if(dfs(visited,i,adj,v,parent)){
                cout<<v.size()<<endl;
                for(auto & cities:v){
                    cout<<cities+1<<" ";
                }
                cout<<endl;
                temp=true;
                break;
            }            
        }
    }
    if(!temp)cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
