#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int log2(int n){
    int count=0;
    while(n>0){
        n>>=1;
        count++;
       
    }
    return count;
}

int findKAncestor(vector<vector<int>>&dp, int x, int k){
    if(k==0)return x;
    for(int i=dp.size()-1;i>=0;i--){
        if(k & (1 << i)){
            x=dp[i][x];
        }
    }
   
    return x;
}

void build(vector<int>&edges, int n, int m, vector<vector<int>>&dp){
    
    for(int i=0;i<n;i++)dp[0][i]=edges[i];
    for(int j=1;j<m;j++){
        for(int i=0;i<n;i++){
            dp[j][i]=dp[j-1][dp[j-1][i]];
        }
    }
    
}

int main(){
    int n;cin>>n;
    vector<int>next(n);
    vector<vector<int>>before(n);
    for(int i=0; i<n; i++){
        cin>>next[i];
        next[i]--;
        before[next[i]].push_back(i);

    }

    vector<int>cycle_id(n,-2);
    vector<unordered_map<int,int>>cycles;
    for( int i=0;i<n;i++){
        if(cycle_id[i]!=-2)continue;
        int at=i;
        vector<int>path;
        path.push_back(at);
        while(cycle_id[next[at]]==-2){

            cycle_id[at]=-3;
            at=next[at];
            path.push_back(at);
            
        }

        bool in_cycle=false;
        unordered_map<int,int>cycle;
        for(int & j: path){
            in_cycle=in_cycle || j==next[at];
            if(in_cycle)cycle[j]=cycle.size();
            cycle_id[j]=in_cycle ? cycles.size() : -1;
        }
        cycles.push_back(cycle);
    }

    vector<int>dist_in_tree(n);
    for(int i=0;i<n;i++){
        if(cycle_id[i] == -1 && cycle_id[next[i]]!=-1){
            dist_in_tree[i]=1;
            vector<int>stack(before[i]);
            while(!stack.empty()){
                int node=stack.back();
                stack.pop_back();
                dist_in_tree[node]=dist_in_tree[next[node]]+1;
                stack.insert(stack.end(),before[node].begin(),before[node].end());
            }
        }
    }
   
    int m=(int)log2(n)+1;
    vector<vector<int>>ancestors(m,vector<int>(n));
    build(next,n,m,ancestors);
    vector<int>ans;
    for(int i=0;i<n;i++){

        if(cycle_id[i]!=-1){
            ans.push_back(cycles[cycle_id[i]].size());
        }
        else{
            int dist=dist_in_tree[i];
            int cyc_junction_node=findKAncestor(ancestors,i,dist);
            dist+=cycles[cycle_id[cyc_junction_node]].size();
            ans.push_back(dist);
        }

    }

    
    for(int v: ans)cout<<v<<" ";

    return 0;

}