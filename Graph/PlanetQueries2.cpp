//brute force calling dfs for each pair starting from start node, TC=O(n^2)
// #include<iostream>
// #include<vector>
// #include<cmath>
// using namespace std;

// int calculate(int a,int b,vector<int>&edges,int time,vector<bool>&vis){
    
//     if(a==b)return time;
//     int temp=-1;
//     vis[a]=true;
    
//     if(!vis[edges[a]]){
//         temp=calculate(edges[a],b,edges,time+1,vis);
//     }

//     return temp;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n,q;cin>>n>>q;
//    vector<int>edges(n);
//     for(int i=0;i<n;i++){
        
//         cin>>edges[i];
//         edges[i]--;
//     }
    

//     for(int i=0;i<q;i++){
//         int a,b;cin>>a>>b;
//         a--,b--;
//         int time=0;
//         vector<bool>vis(n,false);
//         cout<<calculate(a,b,edges,time,vis)<<'\n';
        
//     }
//     return 0;
// }


// online solution
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <vector>

// using std::cout;
// using std::endl;
// using std::vector;

// int main() {
// 	int planet_num;
// 	int query_num;
// 	std::cin >> planet_num >> query_num;
// 	vector<int> next(planet_num);
// 	vector<vector<int>> before(planet_num);
// 	for (int p = 0; p < planet_num; p++) {
// 		std::cin >> next[p];
// 		next[p]--;
// 		before[next[p]].push_back(p);
// 	}

// 	/*
// 	 * -2 = We haven't even got to processing this planet yet.
// 	 * -1 = This node is part of a tree.
// 	 * >= 0: the ID of the cycle the planet belongs to.
// 	 */
// 	vector<int> cycle_id(planet_num, -2);
// 	// Each map, given a planet #, returns the index of that planet in the
// 	// cycle.
// 	vector<std::map<int, int>> cycles;
// 	for (int p = 0; p < planet_num; p++) {
// 		if (cycle_id[p] != -2) { continue; }
// 		vector<int> path{p};
// 		int at = p;
// 		while (cycle_id[next[at]] == -2) {
// 			at = next[at];
// 			cycle_id[at] = -3;  // Leave breadcrumbs for this iteration
// 			path.push_back(at);
// 		}

// 		std::map<int, int> cycle;
// 		bool in_cycle = false;
// 		for (int i : path) {
// 			in_cycle = in_cycle || i == next[at];
// 			if (in_cycle) { cycle[i] = cycle.size(); }
// 			cycle_id[i] = in_cycle ? cycles.size() : -1;
// 		}
// 		cycles.push_back(cycle);
// 	}

// 	/*
// 	 * Precalculate the distance from each planet to its cycle with BFS.
// 	 * (cyc_dist[p] = 0) if p is part of a cycle.
// 	 */
// 	vector<int> cyc_dist(planet_num);
// 	for (int p = 0; p < planet_num; p++) {
// 		// Check if this planet is part of a cycle.
// 		if (cycle_id[next[p]] == -1 || cycle_id[p] != -1) { continue; }
// 		cyc_dist[p] = 1;
// 		vector<int> stack(before[p]);
// 		while (!stack.empty()) {
// 			int curr = stack.back();
// 			stack.pop_back();
// 			cyc_dist[curr] = cyc_dist[next[curr]] + 1;
// 			stack.insert(stack.end(), before[curr].begin(), before[curr].end());
// 		}
// 	}

// 	// Initialize the binary jumping arrays.
// 	int log2 = std::ceil(std::log2(planet_num));
// 	vector<vector<int>> pow2_ends(planet_num, vector<int>(log2 + 1));
// 	for (int p = 0; p < planet_num; p++) { pow2_ends[p][0] = next[p]; }
// 	for (int i = 1; i <= log2; i++) {
// 		for (int p = 0; p < planet_num; p++) {
// 			pow2_ends[p][i] = pow2_ends[pow2_ends[p][i - 1]][i - 1];
// 		}
// 	}

// 	/*
// 	 * Given a starting planet & dist, returns the planet we end up at
// 	 * if we use the teleporter dist times.
// 	 */
// 	auto advance = [&](int pos, int dist) {
// 		for (int pow = log2; pow >= 0; pow--) {
// 			if ((dist & (1 << pow)) != 0) { pos = pow2_ends[pos][pow]; }
// 		}
// 		return pos;
// 	};
// 	for (int q = 0; q < query_num; q++) {
// 		int u, v;  // going from u to v
// 		std::cin >> u >> v;
// 		u--;
// 		v--;
// 		if (cycle_id[pow2_ends[u][log2]] != cycle_id[pow2_ends[v][log2]]) {
// 			cout << -1 << '\n';
// 			continue;
// 		}
// 		if (cycle_id[u] != -1 || cycle_id[v] != -1) {
// 			if (cycle_id[v] == -1 && cycle_id[u] != -1) {
// 				cout << -1 << '\n';
// 				continue;
// 			}
// 			// Handle the 2nd & 3rd cases at the same time.
// 			int dist = cyc_dist[u];
// 			int u_cyc = advance(u, cyc_dist[u]);  // The root of u's tree

// 			std::map<int, int> &cyc = cycles[cycle_id[u_cyc]];  // u and v's cycle
// 			int u_ind = cyc[u_cyc];
// 			int v_ind = cyc[v];
// 			int diff = u_ind <= v_ind ? v_ind - u_ind : cyc.size() - (u_ind - v_ind);
// 			cout << dist + diff << '\n';
// 		} else {
// 			if (cyc_dist[v] > cyc_dist[u]) {
// 				cout << -1 << '\n';
// 				continue;
// 			}
// 			int diff = cyc_dist[u] - cyc_dist[v];
// 			cout << (advance(u, diff) == v ? diff : -1) << '\n';
// 		}
// 	}
// }


//my solution  TC : qlog(n)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findKancestor(vector<vector<int>>&dp,int k,int x){
    
    if(k==0)return x;
    for(int i=18; i>=0; i--){
        if(k & (1LL<<i)){
            x=dp[i][x];
        }
    }
    return x;
}
void build(vector<vector<int>>&dp, int n, vector<int>& edges){

    for(int i=0; i<n; i++)dp[0][i]=edges[i];
    for(int j=1; j<19; j++){
        for(int i=0; i<n; i++){
            dp[j][i]=dp[j-1][dp[j-1][i]];
        }
    }
} 
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n,q;cin>>n>>q;
    
    vector<int>next(n);
    vector<vector<int>>before(n);
    for(int i=0;i<n;i++){
        
        cin>>next[i];
        next[i]--;
        before[next[i]].push_back(i);//this is i am using so that from junction node of cycle and tree i can do bfs and find dist from there
        
    }
    
    vector<int>cycle_id(n,-2);
    vector<unordered_map<int,int>>cycles;//it will store all the possible cycle in a graph, here it's index is the cycle id as well 
                                        // and the cycle stored at the indx contain the map maping nodes with their relative positions
    for(int i=0; i<n; i++){
        if(cycle_id[i]!=-2)continue;
        int at=i;
        vector<int>path;
        path.push_back(at);
        while(cycle_id[next[at]]==-2){
            cycle_id[at]=-3;
            at=next[at];
            path.push_back(at);
        }
        //now here next[at] is the begineer of the cycle
        bool in_cycle=false;
        unordered_map<int,int>cycle;//store the nodes in a cycle along with their relative ranking starting from one of the enty node r
        for(int & j:path){//no need to iterate over all n just traverse the nodes which u visited in this path 
            in_cycle = in_cycle || j==next[at];
            if(in_cycle){
                cycle[j]=cycle.size();
            }
            cycle_id[j]= in_cycle ? cycles.size() : -1;
        }
        cycles.push_back(cycle);

    }

    //distance calculated using bfs technique
    vector<int>dist_in_tree(n);
    for(int i=0;i<n;i++){
        
        if(cycle_id[i]==-1 && cycle_id[next[i]]!=-1){
    
            dist_in_tree[i]=1;
            vector<int>queue(before[i]);
            while(!queue.empty()){
                int node=queue.back();
                queue.pop_back();
                dist_in_tree[node]=dist_in_tree[next[node]]+1;
                queue.insert(queue.end(),before[node].begin(),before[node].end());
            }

        }
    }
    
    // building a tree for O(logn) jumping and finding an ancestor
    vector<vector<int>>ancestors(19,vector<int>(n,-1));
    build(ancestors,n,next);
    //cycle formation completed query solving time

    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        
        
        if((cycle_id[ancestors[18][a]] != cycle_id[ancestors[18][b]])){
            //if they are part of some same or diff tree their id should be -1 i.e same 
            // or if they are part of same cycle then also their id should be same 
            // but here it implies they belong to different cycle i.e never reachable
            cout<<-1<<'\n';
        }
        else if(cycle_id[a]==-1 || cycle_id[b]==-1){
            if(cycle_id[a]!=-1 && cycle_id[b]==-1){
                //u can't go out of they cycle so not reachable 
                cout<<-1<<'\n';
            }
            else if(cycle_id[a]==-1 && cycle_id[b]!=-1){
                // ya but u can go inside the cycle
                int cyc_junction_node=findKancestor(ancestors,dist_in_tree[a],a);
                if(cycle_id[cyc_junction_node]!=cycle_id[b]){
                    cout<<-1<<'\n';
                    continue;
                }
                int dist_u = cycles[cycle_id[cyc_junction_node]][cyc_junction_node];
                int dist_v = cycles[cycle_id[b]][b];
                if(dist_v>=dist_u){
                    cout<< dist_in_tree[a]+dist_v-dist_u <<'\n';
                }
                else{
                    cout<<dist_in_tree[a]+cycles[cycle_id[cyc_junction_node]].size()-abs(dist_v-dist_u)<<'\n';
                }
            }
            else{
                if(dist_in_tree[b]>dist_in_tree[a]){
                    cout<<-1<<'\n';// we can come uo but can't go down
                }
                else{
                    int LCA=findKancestor(ancestors,dist_in_tree[a]-dist_in_tree[b],a);
                    if(LCA==b)cout<<dist_in_tree[a]-dist_in_tree[b]<<'\n';//means they belong to the same tree
                    else cout<<-1<<'\n';//they are either in different branches or diff tree not reachable
                }
            }
        }
        else{
            //both of them are in the same cycle
            int dist_u=cycles[cycle_id[a]][a];
            int dist_v=cycles[cycle_id[b]][b];
            if(dist_v>=dist_u){
                cout<< dist_in_tree[a]+dist_v-dist_u <<'\n';
            }
            else{
                cout<<dist_in_tree[a]+cycles[cycle_id[a]].size()-abs(dist_v-dist_u)<<'\n';
            }
        }
        
    }
    return 0;
}

