#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

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

        int unite(int u, int v){
            u=findParent(u),v=findParent(v);
            if(size[u]>=size[v]){
                size[u]+=size[v];
                parent[v]=u;
                return size[u];
            }
            else{
                size[v]+=size[u];
                parent[u]=v;
                return size[v];
            }
        }

};


int main(){

    int n,m;cin>>n>>m;
    int component=n,maxSize=1;
    DSU ds(n);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        if(ds.findParent(u)!=ds.findParent(v)){
            component--;
           
            cout<<component<<' ';
            maxSize=max(maxSize,ds.unite(u,v));
            cout<<maxSize<<'\n';
        }
        else{
           
            cout<<component<<' '<<maxSize<<'\n';
        }
    }
}