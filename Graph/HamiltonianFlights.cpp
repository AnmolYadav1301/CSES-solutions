// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<unordered_map>

// using namespace std;
// const int mod=1e9 + 7;
// int Routes_count=0;
// void findHamiltonianPath(vector<vector<int>>&adj, int n,unordered_map<int,bool>&visited, int node,int count){

//     // if(count!=1)ans.push_back(node.back());
//     if(count==n && node==n-1){
//         Routes_count=(Routes_count + 1)%mod;
//         return ;
//     }
//     visited[node]=true;
    

//     for(auto & nbr : adj[node]){
//         if(!visited[nbr]){
//             findHamiltonianPath(adj,n,visited,nbr,count+1);
//         }
//     }
//     visited[node]=false;
//     return ;

// }


// int main(){

//     int n,m;cin>>n>>m;
//     vector<vector<int>>adj(n);

//     for(int i=0;i<m;i++){
//         int a,b;cin>>a>>b;
//         a--,b--;
//         adj[a].push_back(b);
//     }

//     unordered_map<int,bool>visited;
//     findHamiltonianPath(adj,n,visited,0,1);

//     cout<<Routes_count<<'\n';

// }


// chatgpt solution
// #include<iostream>
// #include<vector>
// using namespace std;

// const int MOD = 1e9 + 7;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adj(n);
//     for (int i = 0; i < m; ++i) {
//         int u, v; cin >> u >> v;
//         u--, v--;
//         adj[u].push_back(v);
//     }

//     int fullMask = (1 << n);
//     vector<vector<int>> dp(fullMask, vector<int>(n, 0));
//     dp[1][0] = 1; // only node 0 is visited

//     for (int mask = 1; mask < fullMask; ++mask) {
//         for (int u = 0; u < n; ++u) {
//             if (!(mask & (1 << u))) continue; // skip if u not visited
//             for (int v : adj[u]) {
//                 if (mask & (1 << v)) continue; // don't revisit
//                 dp[mask | (1 << v)][v] = (dp[mask | (1 << v)][v] + dp[mask][u]) % MOD;
//             }
//         }
//     }

//     cout << dp[fullMask - 1][n - 1] << '\n'; // end at node n-1 with all visited
//     return 0;
// }

//online solution
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX_N = 20;
const ll MOD = (ll)1e9 + 7;

ll dp[1 << MAX_N][MAX_N];
// come_from[i] contains the cities that can fly to i
vector<int> come_from[MAX_N];

int main() {
	int city_num;
	int flight_num;
	cin >> city_num >> flight_num;
	for (int f = 0; f < flight_num; f++) {
		int start, end;
		cin >> start >> end;
		come_from[--end].push_back(--start);
	}

	dp[1][0] = 1;
	for (int s = 2; s < 1 << city_num; s++) {
		// only consider subsets that have the first city
		if ((s & (1 << 0)) == 0) continue;
		// also only consider subsets with the last city if it's the full subset
		if ((s & (1 << (city_num - 1))) && s != ((1 << city_num) - 1)) continue;

		for (int end = 0; end < city_num; end++) {
			if ((s & (1 << end)) == 0) continue;

			// the subset that doesn't include the current end
			int prev = s - (1 << end);
			for (int j : come_from[end]) {
				if ((s & (1 << j))) {
					dp[s][end] += dp[prev][j];
					dp[s][end] %= MOD;
				}
			}
		}
	}
	cout << dp[(1 << city_num) - 1][city_num - 1] << '\n';
}