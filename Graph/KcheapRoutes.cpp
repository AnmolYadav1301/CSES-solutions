#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int main(){
    int n,m,k;cin>>n>>m>>k;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }
    priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>>pq;

    vector<int>count(n,0);
    pq.push({0,0});//path length, node
    vector<long long >ans;
    while(count[n-1]<k){
        long long l=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(count[u]==k)continue;

        count[u]+=1;

        if(u==n-1)ans.push_back(l);
        for(auto & nbr:adj[u]){
            pq.push({nbr.second+l,nbr.first});
        }        
    }

    for(auto v:ans)cout<<v<<" ";
    cout<<endl;

}