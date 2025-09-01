//Two planets a and b belong to the same kingdom exactly when there is a route both from a to b and from b to a.
//Definition of Strongly connected components

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

bool dfs(int vertex, unordered_map<int,bool>&visited, unordered_map<int,vector<int>>& adj, int region, unordered_map<int,int>&Kingdom){
    visited[vertex]=true;
    if(Kingdom[-vertex]==region){
        return true;
    }
    Kingdom[vertex]=region;
    for(auto & nbr:adj[vertex]){
        if(!visited[nbr]){
            if(dfs(nbr,visited,adj,region,Kingdom))return true;;
        }
    }
    return false;
    
}

void topo_sort(int vertex, unordered_map<int,bool>&visited, stack<int>&topo, unordered_map<int,vector<int>>& adj){
    visited[vertex]=true;
    for(auto & nbr:adj[vertex]){
        if(!visited[nbr]){
            topo_sort(nbr,visited,topo,adj);
        }
    }
    topo.push(vertex);
}
int main(){

    int n,m;cin>>n>>m;
    
    unordered_map<int,vector<int>>adj;
    unordered_map<int,vector<int>>revAdj;
   
    for(int i=0;i<n;i++){
        int u,v;//cin>>u>>v;
        int x, y;
        char s1,s2;
        cin >> s1 >> x >> s2 >> y;

        if(s1 == '-')u=-x;
        else u=x;
        if(s2 == '-')v=-y;
        else v=y;
        //a V b = (~a->b) ^ (~b -> a)
        adj[-u].push_back(v);
        adj[-v].push_back(u);
        revAdj[v].push_back(-u);
        revAdj[u].push_back(-v);
        
    }

    stack<int>topo;
    unordered_map<int,bool>visited;
    for(int i=-m;i<=m;i++){
        if(i==0)continue;
        if(!visited[i]){
            topo_sort(i,visited,topo,adj);
        }
    }

    unordered_map<int,bool>seen;
    unordered_map<int,int>Kingdom;
    int i=0;
    bool flag=false;
    stack<int>temp(topo);
    while(!topo.empty()){
        int val=topo.top();topo.pop();
        if(!seen[val]){
            i++;
            // v.push_back(val);
            if(dfs(val,seen,revAdj,i,Kingdom)){
                flag=true;
                break;
            }
        }
    }

    vector<bool>ans(m+1,false);
   
   

    if(flag)cout<<"IMPOSSIBLE\n";
    else{
        while(!temp.empty()){
            int val=temp.top();temp.pop();
            if(val<0)ans[-val]=false;
            else ans[val]=true;

        }
        for(int i=1;i<=m;i++){
            if(ans[i])cout<<"+ ";
            else cout<<"- ";
        }
        cout<<endl;
    }


    return 0;
}

