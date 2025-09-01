#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class DSU{

    vector<int>parent,size;

    public:
        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++)parent[i]=i;
            size.resize(n,1);
        }
        int findParent(int u){

            if(parent[u]==u)return u;
            return parent[u]=findParent(parent[u]);

        }

        void unite(int u, int v){
            u=findParent(u),v=findParent(v);
            if(size[u]>=size[v]){
                size[u]+=size[v];
                parent[v]=u;
            }
            else{
                size[v]+=size[u];
                parent[u]=v;
            }
        }

};
int main(){
    int n,m;cin>>n>>m;

    vector<pair<long long int,pair<int,int>>>edges;
    for(int i=0;i<m;i++){
        long long int c;
        int a,b;cin>>a>>b>>c;
        edges.push_back({c,{a-1,b-1}});
    }
    
    sort(edges.begin(),edges.end(),[](auto & a, auto &  b){
        return (a.first < b.first);   
    });

    DSU ds(n);

    long long int min_cost=0;
    for(auto & edge:edges){
        long long int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(ds.findParent(u)!=ds.findParent(v)){
            min_cost+=w;
            ds.unite(u,v);
        }
    }
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(ds.findParent(i));
    }
    if(s.size()>1 || m<n-1)cout<<"IMPOSSIBLE\n";
    else cout<<min_cost<<'\n';

    return 0;
}