#include<iostream>
#include<vector>

using namespace std;

vector<bool>visited;
vector<long long>cnt;
vector<long long>distSum;
long long dfs(vector<vector<int>>&adj, int n, int u){

    long long sum=0;
    visited[u]=true;
    for(int &nbr:adj[u]){
        if(!visited[nbr]){
            sum+=dfs(adj,n,nbr);
            cnt[u]+=cnt[nbr];
        }
    }

    cnt[u]+=1LL;
    return sum+cnt[u];
}

void dfs2(int u, vector<vector<int>>&adj, int n){

    visited[u]=true;
    for(int &nbr:adj[u]){
        if(!visited[nbr]){
            distSum[nbr]=distSum[u]+(n-cnt[nbr])-(cnt[nbr]);
            dfs2(nbr,adj,n);
        }
    }
}

void print(){
    for(int i=1;i<distSum.size();i++)cout<<distSum[i]<<" ";
    cout<<endl;
}

int main(){

    int n;cin>>n;
    vector<vector<int>>adj(n+1);
    visited.assign(n+1,false),cnt.assign(n+1,0);
    distSum.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long sum=dfs(adj,n,1);
    visited.assign(n+1,false);
    distSum[1]=sum-cnt[1];
    dfs2(1, adj, n);

    print();

}