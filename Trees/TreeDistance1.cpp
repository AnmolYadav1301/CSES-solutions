#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

    int n;cin>>n;

    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int>dist(n);
    queue<pair<int,int>>q;
    q.push()
}