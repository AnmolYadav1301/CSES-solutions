#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int vertex){
    visited[vertex]=true;
    for(auto & nbr : adj[vertex]){
        if(!visited[nbr]){
            dfs(adj,visited,nbr);
        }
    }
}


void findEulerianCycle(int start, vector<multiset<int>>& graph, vector<int>& cycle){

    stack<int>st;
    st.push(start);

    while(!st.empty()){

        int u=st.top();
        if(!graph[u].empty()){
            
            int v=*graph[u].begin();
            graph[u].erase(graph[u].begin());
            graph[v].erase(graph[v].find(u));
            st.push(v);
        
        }
        else{
            cycle.push_back(u);
            st.pop();
        }

    }
    
        
    
}


int main(){
    int n,m;cin>>n>>m;

    vector<vector<int>>adj(n);
    vector<int>degree(n,0);
    vector<multiset<int>>graph(n);

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++,degree[v]++;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    bool isEulerianCycle=true;
    for(int i=0;i<n;i++){
        if(degree[i] & 1){
            isEulerianCycle=false; //odd degree edge present not a eulerian cycle
            break;
        }
    }
    if( isEulerianCycle ){
        vector<bool>visited(n,false);
        int componenet_count=0;
        for(int i=0;i<n;i++){
            if(!visited[i] && adj[i].size()>0){
                dfs(adj,visited,i);
                componenet_count++;
            }
            
        }
        if(componenet_count>1){
                isEulerianCycle=false;
                // break;
         }
    }

    if(!isEulerianCycle){
        cout<<"IMPOSSIBLE\n";
    }
    else{

        int start=0;
        // while(start<n && degree[start]==0)start++;
        //no need to do this bcz it's fixed that u have to start from 0 , if u have to find general 
        //then u do this
        
        vector<int>cycle;
        
        findEulerianCycle(start,graph,cycle);
        if((int)cycle.size() != m+1)cout<<"IMPOSSIBLE\n";
        else{
            for(auto & v : cycle){
                cout<<v+1<<" ";
            }
        }
        
        cout<<'\n';
    }
    
        
    return 0;
}