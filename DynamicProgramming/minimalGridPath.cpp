#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

void inline print(string &vec){

    for(auto & v:vec)cout<<v;
    cout<<'\n';

}

bool isValid(int row, int col, int n){
    return row<n && col<n;
}



int main(){

    int n;cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }


    vector<string>dp(n,"");
    dp[0]+=grid[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>0 && j>0)dp[j]=min(dp[j-1],dp[j])+grid[i][j];
            else if(i>0)dp[j]=dp[j]+grid[i][j];
            else if(j>0)dp[j]=dp[j-1]+grid[i][j];
        }
    }

    print(dp[n-1]);
   

    return 0;
}