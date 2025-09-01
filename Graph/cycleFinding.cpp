// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;


// int main(){
    
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);


//     int n,m;cin>>n>>m;
   
//    vector<vector<long long>>dist(n,vector<long long>(n,LLONG_MAX));
//    for(int i=0;i<n;i++)dist[i][i]=0;
//    vector<vector<int>> next(n, vector<int>(n, -1));
//     for(int i=0;i<m;i++){
//         int a,b,c;cin>>a>>b>>c;
//         dist[a-1][b-1]=c;
//         next[a-1][b-1]=b-1;
        
//     }    
//     for(int k=0;k<n;k++){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
                
//                 if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX ) {
//                     long long sum=dist[i][k] + dist[k][j];

//                     if(sum < dist[i][j]){
//                         dist[i][j] = dist[i][k] + dist[k][j];
//                         next[i][j] = next[i][k];
//                     }
                    
//                 }
                    
//             }
//         }
//     }
//     int negNode=-1;
//     for(int i=0;i<n;i++){
//         if(dist[i][i]<0){
//             negNode=i;
//             break;
//         } 
//     }
//     if(negNode==-1){
//         cout<<"NO";
//     }
//     else{
//         cout<<"YES"<<endl;
//         // Step 2: Walk back to ensure we're inside the cycle
//         int cycle_start = negNode;
//         for (int i = 0; i < n; ++i)
//             cycle_start = next[cycle_start][negNode];

//         // Step 3: Reconstruct the cycle
//         vector<int> cycle;
//         int curr = cycle_start;
//         do {
//             cycle.push_back(curr);
//             curr = next[curr][cycle_start];
//         } while (curr != cycle_start);
//         cycle.push_back(cycle_start); // complete the cycle

//         // Output cycle
//         for (int v : cycle) {
//             cout << v + 1 << " "; // convert back to 1-based indexing
//         }
//         cout << endl;

//     }



// }


#include<iostream>
#include<vector>
#include<vector>
using namespace std;

int main(){

    int n,m;cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        edges.push_back({a-1,b-1,c});
    }

    vector<int>parent(n,-1);
    vector<long long>dist(n,0);

    int cycle_node=-1;
    for(int i=0;i<n;i++){
        for(auto &edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            if(dist[v]>dist[u]+w){

                if(i==n-1){
                    cycle_node=v;
                    parent[v]=u;
                    break;
                }

                dist[v]=dist[u]+w;
                parent[v]=u;

            }
        }
        
    }
   
    if(cycle_node==-1){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<endl;

        for (int i = 0; i < n; ++i){
            cycle_node = parent[cycle_node];//just to move the detected node inside the cycle 
            
        }
            

        vector<int> cycle;
        for (int v = cycle_node;; v = parent[v]) {
            cycle.push_back(v);
            if (v == cycle_node && cycle.size() > 1){
                break;
            }
                
        }

        for (int i=cycle.size()-1;i>=0;i--)
            cout << cycle[i] +1 << ' ';
        cout << endl;
    }



    return 0;
}