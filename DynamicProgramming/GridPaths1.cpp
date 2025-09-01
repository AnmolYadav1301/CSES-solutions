#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int mod=1e9 +7;

int f(vector<vector<char>>&grid, int r, int c,int n, vector<vector<int>>&dp){
    
    if(r>=n || c>=n)return 0;
    if(r==n-1 && c==n-1){
        return dp[r][c]=1;
    }
    if(grid[r][c]=='*')return dp[r][c]=0;
    if(dp[r][c]!=-1)return dp[r][c];

    int right=f(grid, r, c+1, n, dp);
    int down=f(grid, r+1,c,n, dp);

    return dp[r][c]=(right+down)%mod;  
}

int main(){

    int n;cin>>n;
    vector<vector<char>>grid(n,vector<char>(n,'.'));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    if(grid[n-1][n-1]=='*' || grid[0][0]=='*')cout<<0<<endl;
    else cout<<f(grid,0,0,n,dp);


    return 0;
}