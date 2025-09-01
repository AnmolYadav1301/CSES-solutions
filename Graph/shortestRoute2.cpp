
//FLOYD WARSHALL 

#include<iostream>
#include <vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n,m,q;cin>>n>>m>>q;
    vector<vector<pair<int,int>>>adj(n);
    vector<vector<long long>>distances(n,vector<long long>(n,LLONG_MAX));

    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
        distances[a-1][b-1]=distances[b-1][a-1]=min(distances[a-1][b-1],(long long)c);
    }
    
    
    //creating a distance matrix using a floyd warshall
    for(int i=0;i<n;i++)distances[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(distances[i][k]!=LLONG_MAX && distances[k][j]!=LLONG_MAX)
                distances[i][j]=min(distances[i][k]+distances[k][j],distances[i][j]);
            }
        }
    }



    vector<long long>ans(q);
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        ans[i]=distances[a-1][b-1]==LLONG_MAX ? -1 : distances[a-1][b-1];
    }

    for(auto &p:ans)cout<<p<<endl;
    return 0;
}