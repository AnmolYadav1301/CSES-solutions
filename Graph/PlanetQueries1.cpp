#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int solve(int x,int k,vector<vector<int>>&dp){

    if(k==0)return x;
    
     for (int i = (int)(log2(k)+1); i>=0; i--) {
        if (k & (1LL << i)) {
            x = dp[i][x];
            if (x == -1) return -1;
        }
    }
    return x;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;cin>>n>>q;
    int m=30;
    vector<vector<int>>dp(m,vector<int>(n,0));
   
    for(int i=0;i<n;i++){
        cin>>dp[0][i];
        dp[0][i]--;
    }
    
    // cout<<m;
    
    //here row represents the 2^j th ancestor and col represents the node
    for(int j=1;j<m;j++){
        for(int i=0;i<n;i++){
    
            dp[j][i]=dp[j-1][dp[j-1][i]];

        }
        
    }
    for(int i=0;i<q;i++){
        int x,k;cin>>x>>k;
        x--;
        cout<<solve(x,k,dp)+1<<'\n';
    }
    return 0;
}