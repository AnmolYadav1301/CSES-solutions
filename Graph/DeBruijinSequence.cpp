#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

void buildGraph(unordered_map<string,vector<string>>&adj, int n,unordered_map<string,bool>&visited,string s){

   if(visited[s])return;
    string newnode=s.substr(1);
    if(newnode+"0"!=s)adj[s].push_back(newnode+"0");
    if(newnode+"1"!=s)adj[s].push_back(newnode+"1");
    visited[s]=true;
    buildGraph(adj, n, visited,newnode+"0");
    buildGraph(adj, n, visited,newnode+"1");

}

bool findHamiltonianPath(unordered_map<string,vector<string>>&adj, int n,unordered_map<string,bool>&visited,string node,string& ans,int count){

    if(count!=1)ans.push_back(node.back());
    if(count==(1<<n))return true;
    visited[node]=true;
    

    for(auto & nbr :adj[node]){
        if(!visited[nbr]){
            if(findHamiltonianPath(adj,n,visited,nbr,ans,count+1))return true;;
        }
    }
    visited[node]=false;
    ans.pop_back();
    return false;

}

int main(){

    int n;cin>>n;
    unordered_map<string,vector<string>>adj;
    unordered_map<string,bool>visited;
    string s(n,'0');
    buildGraph(adj,n,visited,s);
    string ans=s;
    unordered_map<string,bool>seen;
    // for(auto u:adj){
    //     cout<<u.first<<':';
    //      for(auto nbr:u.second){
    //         cout<<nbr<<" ";
    //     }
    //     cout<<'\n';
    // }
   
    if(findHamiltonianPath(adj,n,seen,s,ans,1)){
        cout<<ans<<endl;
    }
    else{
        cout<<"no hmt cycle";
    }

    


    return 0;
}