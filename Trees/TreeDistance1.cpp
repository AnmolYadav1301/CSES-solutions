// You are given a tree consisting of n nodes.
// Your task is to determine for each node the maximum distance to another node.
// Input
// The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
// Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
// Output
// Print n integers: for each node 1,2,\ldots,n, the maximum distance to another node.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5

// Output:
// 2 3 2 3 3


#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
    for(int i=0;i<n;i++){
        queue<pair<int,int>>q;
        q.push({i,0});
        int maxi=0;
        vector<bool>visited(n,false);
        visited[i]=true;
        while(!q.empty()){
            int u=q.front().first;
            int curr_dist=q.front().second;
            maxi=max(maxi,curr_dist);
            q.pop();
            for(int nbr:adj[u]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push({nbr,curr_dist+1});
                }
            }
        }
        dist[i]=maxi;
    }

    for(auto v:dist)cout<<v<<" ";
    cout<<endl;


    return 0;
    
}