#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class DSU{
private:
    vector<int>parent;
    vector<int>size;
public:

    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)parent[i]=i;
    }
    void unite(int u,int v){
        u=findParent(u);
        v=findParent(v);
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
    int findParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findParent(parent[u]);
        
    }

};
int main(){

    int n,m;cin>>n>>m;
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        edges.push_back({u,v});
    }
    
    // making components
    DSU ds(n);
    for(auto edge:edges){
        int u=edge.first;
        int v=edge.second;
        if(ds.findParent(u)!=ds.findParent(v)){
            ds.unite(u,v);
        }
    }
    unordered_set<int>pars;
    for(int i=1;i<=n;i++){
        pars.insert(ds.findParent(i));
    }
    vector<int>req_roads(pars.begin(),pars.end());
    cout<<pars.size()-1<<endl;
    for(int i=0;i<req_roads.size()-1;i++){
        cout<<req_roads[i]<<" "<<req_roads[i+1]<<endl;
    }
    return 0;
}