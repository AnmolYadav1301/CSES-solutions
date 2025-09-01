#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<int>&visited,vector<vector<int>>&adj,int vertex){

    for(auto nbr:adj[vertex]){
        if(visited[nbr]==-1){
            visited[nbr]=1^visited[vertex];
            if(!dfs(visited,adj,nbr))return false;
        }
        else if(visited[nbr]==visited[vertex]){
            return false;
        }
    }
    return true;
}
int main(){
    
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int>visited(n,-1);
    bool flag=false;
    for(int i=0;i<n;i++){
        if(visited[i]==-1){
            visited[i]=0;
            if(!dfs(visited,adj,i)){
                flag=true;
                break;
            }
        }
    }
    if(flag)cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int v:visited){
            cout<<v+1<<" ";
        }
        cout<<endl;
    }
    return 0;

}