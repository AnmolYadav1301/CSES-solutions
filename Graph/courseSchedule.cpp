//TopoSort


#include<iostream>
#include<vector>
#include<queue>
// #include<unordered_map>

using namespace std;
int main(){

    int n,m;cin>>n>>m;
    // unordered_map<int,int>indegree;
    vector<int>indegree(n);
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        indegree[b-1]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();

        for(int &nbr:adj[node]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(ans.size()==n){
        for(int a:ans)cout<<a+1<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE";


    return 0;
}